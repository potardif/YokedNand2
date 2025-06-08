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
  let mutable hasTime = false
  let mutable hasOutM = false

  let tick () = sb.AppendLine("\tdevice->clk = 0; ++time_; device->eval(); // tick") |> ignore
  let tock () = sb.AppendLine("\tdevice->clk = 1; ++time_; device->eval(); // tock") |> ignore

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
          match col.Split('%') with
          | [| var |] ->
              output.Headers.Add(center var 3)
              output.Fmts.Add(" %01b ")
              output.Vars.Add($"device->{var}")
          | [| "time"; fmt |] ->
              hasTime <- true
              let totalLength =
                match fmt with
                | "S1.3.1" -> 1 + 3 + 1
                | "S1.4.1" -> 1 + 4 + 1
                | _ -> raise (NotImplementedException(fmt))
              output.Headers.Add(center "time" totalLength)
              output.Fmts.Add("%s")
              output.Vars.Add($"fmt_time({totalLength}).c_str()")
          | [| "outM"; "D1.6.0" |] ->
              hasOutM <- true
              output.Headers.Add(center "outM" 7)
              output.Fmts.Add("%s")
              output.Vars.Add("fmt_outM(device).c_str()")
          | [| var; fmt |] ->
              let paddingChar =
                match fmt.[0] with
                | 'B' ->
                    output.Vars.Add($"device->{var}")
                    "0"
                | 'D' ->
                    output.Vars.Add($"static_cast<int16_t>(device->{var})")
                    ""
                | _ -> raise (NotImplementedException(fmt))
              match fmt.[1 ..].Split('.') |> Array.map int with
              | [| l; chars; r |] ->
                  output.Headers.Add(center var (l + chars + r))

                  let lPad = String.replicate l " "
                  let rPad = String.replicate r " "
                  let fmtType = Char.ToLower(fmt.[0])
                  output.Fmts.Add($"{lPad}%%{paddingChar}{chars}{fmtType}{rPad}")
              | _ -> raise (NotImplementedException(fmt))
          | _ -> raise (NotImplementedException(col))
    | ["set"; var; value]
    | "set" :: var :: value :: "//" :: _ ->
        let value = value.Replace("%B", "0b").TrimEnd([| ','; ';' |])
        sb.AppendLine($"\tdevice->{var} = {value};") |> ignore
    | ["eval"] -> sb.AppendLine("\tdevice->eval();") |> ignore
    | ["output"] -> sb.AppendLine("\toutput(device);") |> ignore
    | ["tick"] -> tick ()
    | ["tock"] -> tock ()
    | ["tick,"; "output,"; "tock,"; "output"] ->
        tick ()
        sb.AppendLine("\toutput(device);") |> ignore
        tock ()
        sb.AppendLine("\toutput(device);") |> ignore
    | tokens -> raise (NotImplementedException($"%A{tokens}"))

  let className = $"V{device}"

  let timeFunctions =
    if hasTime then $$"""int time_ = 0;

std::string fmt_time(int total_length) {
	std::string s = ' ' + std::to_string(time_ / 2);
	if (time_ % 2 == 1)
		s += '+';
	s.append(total_length - s.length(), ' ');
	return s;
}"""
    else ""

  let fmt_outM =
    if hasOutM then $$"""
std::string fmt_outM(const {{ className }}* device) {
	if (!device->writeM)
		return "*******";

	std::string right = std::to_string(static_cast<int16_t>(device->outM));

	std::string left;
	left.append(7 - right.length(), ' ');

	return left + right;
}
"""
    else ""

  $$"""#include "{{ className }}.h"

{{ timeFunctions }}
{{ fmt_outM }}
void output(const {{ className }}* device) {
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
  for project in [| 1; 2; 3; 5 |] do
    let projectFolder = getProjectFolder project
    for svPath in Directory.EnumerateFiles(projectFolder, "*.sv") do
      let device = Path.GetFileNameWithoutExtension(svPath)

      let tstPaths = List()
      match device with
      | "ALU" ->
          tstPaths.Add(Path.Combine(projectFolder, $"{device}.tst"))
          tstPaths.Add(Path.Combine(projectFolder, $"ALU-basic.tst"))
      | "CPU" ->
          // CPU.tst is deliberately ignored because it is exactly the same test as
          // CPU-external.tst, but it also tests the value of the D register which is a nonsense in
          // my opinion because it is not exposed in the output pins. And you can't just expose it
          // in the output pins to pass the test, because the test seems to expect the value of D
          // before it even propagates to its output, which starts becoming a philosophical
          // question: What is the value of a register if not its output?
          tstPaths.Add(Path.Combine(projectFolder, $"CPU-external.tst"))
      | _ -> tstPaths.Add(Path.Combine(projectFolder, $"{device}.tst"))

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
