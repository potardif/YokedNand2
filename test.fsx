#!/usr/bin/env -S dotnet fsi

open System
open System.Collections.Generic
open System.Diagnostics
open System.IO
open System.Text

let center (s : string) (n : int) =
  let s = s.[.. n - 1]
  let l = (n - s.Length) / 2
  let r = n - l - s.Length
  $"""{String.replicate l " "}{s}{String.replicate r " "}"""

let tst2cpp tstPath device =
  let output = {|
    Headers = List()
    Fmts = List()
    Vars = List()
  |}
  let sb = StringBuilder()

  for line in File.ReadLines(tstPath) do
    let line = line.Trim().TrimEnd([| ','; ';' |])
    match line.Split((null : char[]), StringSplitOptions.RemoveEmptyEntries) |> Array.toList with
    | "//" :: _ -> ()
    | [] -> sb.AppendLine("") |> ignore
    | ["load"; _] -> ()
    | ["output-file"; _] -> ()
    | ["compare-to"; _] -> ()
    | "output-list" :: cols ->
        for col in cols do
          let (var, l, bits, r) =
            match col.Split('%') with
            | [| var |] -> (var, 1, 1, 1)
            | [| var; fmt |] ->
                match fmt.TrimStart('B').Split('.') |> Array.map int with
                | [| l; bits; r |] -> (var, l, bits, r)
                | _ -> raise (NotImplementedException(fmt))
            | _ -> raise (NotImplementedException(col))
          
          output.Headers.Add(center var (l + bits + r))
          output.Fmts.Add($"""{String.replicate l " "}%%0{bits}b{String.replicate r " "}""")
          output.Vars.Add($"device->{var}")
    | ["set"; var; value]
    | "set" :: var :: value :: "//" :: _ ->
        let value = value.Replace("%B", "0b").TrimEnd([| ','; ';' |])
        sb.AppendLine($"\tdevice->{var} = {value};") |> ignore
    | ["eval"] -> sb.AppendLine("\tdevice->eval();") |> ignore
    | ["output"] -> sb.AppendLine("\toutput(device);") |> ignore
    | tokens -> raise (NotImplementedException($"%A{tokens}"))

  let className = $"V{device}"

  $$"""#include "{{ className }}.h"

void output({{ className }}* device) {
	printf("|{{ String.Join("|", output.Fmts) }}|\n", {{ String.Join(", ", output.Vars) }});
}

int main() {
	auto device = new {{ className }};

	printf("|{{ String.Join("|", output.Headers) }}|\n");

{{ sb.ToString() }}

	delete device;
	return 0;
}
"""

let printCmd (si : ProcessStartInfo) =
  let tokens = List()
  tokens.Add(si.FileName)
  tokens.AddRange(si.ArgumentList)
  printfn $"{String.Join(' ', tokens)}"

let build cppPath svPath includePaths exeName =
  let si = ProcessStartInfo()
  si.FileName <- "verilator"
  si.RedirectStandardOutput <- true

  // https://verilator.org/guide/latest/example_cc.html
  for arg in [|
    "--cc" // Generate C++ output.
    "--exe" // Create an executable instead of a library.
    "--build" // Verilator will call make instead of us.
    "-j"; "0" // Use all available cores for building.
    "-Wall" // Enable all Verilator warnings.
    "-o"; exeName
    cppPath
    svPath
  |] do
    si.ArgumentList.Add(arg)
  
  for includePath in includePaths do
    si.ArgumentList.Add($"-I{includePath}")

  let proc = new Process()
  proc.StartInfo <- si
  printCmd si
  proc.Start() |> ignore
  proc.WaitForExit()
  if proc.ExitCode <> 0 then
    failwith $"{proc.ExitCode}"

let run exeName =
  let si = ProcessStartInfo()
  si.FileName <- $"obj_dir/{exeName}"
  si.RedirectStandardOutput <- true

  let proc = new Process()
  proc.StartInfo <- si
  printCmd si
  proc.Start() |> ignore
  proc.WaitForExit()
  if proc.ExitCode <> 0 then
    failwith $"{proc.ExitCode}"
  proc.StandardOutput.ReadToEnd()

let () =
  let getProjectFolder i = Path.Combine("projects", $"{i}")
  for project in 1 .. 2 do
    let projectFolder = getProjectFolder project
    for svPath in Directory.EnumerateFiles(projectFolder, "*.sv") do
      let device = Path.GetFileNameWithoutExtension(svPath)

      let tstPaths = List()
      tstPaths.Add(Path.Combine(projectFolder, $"{device}.tst"))
      if device = "ALU" then
        tstPaths.Add(Path.Combine(projectFolder, $"ALU-basic.tst"))

      for tstPath in tstPaths do
        let tstName = Path.GetFileNameWithoutExtension(tstPath)

        let cpp = tst2cpp tstPath device
        let cppPath = $"{tstPath}.cpp"
        File.WriteAllText(cppPath, cpp)

        let includePaths = [| for i in 1 .. project -> getProjectFolder i |]
        let exeName = $"V{tstName}"
        build cppPath svPath includePaths exeName

        let actualOutput = run exeName
        let cmpPath = Path.Combine(projectFolder, $"{tstName}.cmp")
        let expectedOutput = File.ReadAllText(cmpPath)
        if actualOutput <> expectedOutput then
          failwith $"Expected\n{expectedOutput}Got\n{actualOutput}"
