# YokedNand2

This is my implementation of the hardware components from the book "The Elements of Computing
Systems: Building a Modern Computer from First Principles" 2nd edition by Noam Nisan and Shimon
Schocken. The book and the course are informally known as "Nand to Tetris" or
[nand2tetris](https://www.nand2tetris.org/).

The name YokedNand2 is a reference to this
[YouTube video from 2021](https://www.youtube.com/watch?v=jquaz5axNC4&t=1825s) where chess
grandmaster Aman Hambleton beats a very aggressive player called YokedNando in a humorous way.

I decided to use SystemVerilog as the hardware description language (HDL). My reasoning was that if
I have to learn a HDL, I'd rather learn a real one and not the toy one from the book. I created a
script to translate the .tst files to C++.

I considered implementing the screen and the keyboard using a library like SDL, but I realized this
would be complicated and not very fun, so I only implemented the CPU from chapter 5 and stopped
there.

## How to build and run

You run the tests with `./test.fsx` or `dotnet fsi test.fsx`.

You need to install .NET, Verilator, and a C++ compiler. Here's an example of how to do that on
Ubuntu 24.04:

```console
$ sudo apt install dotnet-sdk-8.0
$ sudo apt install verilator
$ sudo apt install g++
```

## License

Here are the files that I wrote:
- All the .sv files
- Nand.tst, Nand.cmp, Nand.tst.cpp
- DFF.tst, DFF.cmp, DFF.tst.cpp
- test.fsx
- README.md

The rest of the files keep their
[CC BY-NC-SA 3.0 license](https://creativecommons.org/licenses/by-nc-sa/3.0/) as specified on
[https://www.nand2tetris.org/license](https://www.nand2tetris.org/license).

For the sake of simplicity, I've chosen to also license all the files that I wrote under the CC
BY-NC-SA 3.0 so that the whole repository is under the same license.
