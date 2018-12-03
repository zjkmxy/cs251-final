Build RISC-V Compilation Environment
====================================
```bash
git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain
./configure --prefix=/opt/riscv
make
export PATH=$PATH:/opt/riscv/bin
```

Compile Tools Usage Reference
=============================

Compile and run single C file
-----------------------------
```bash
riscv64-unknown-elf-gcc -g <SOURCE.c> -o <PROGRAM>
./build/RISCV/gem5.opt configs/example/se.py -c <PATH/TO/SOURCE>
```

Disassembly
-----------
```bash
riscv64-unknown-elf-objdump -D <PROGRAM> > <DISASM.dasm>
```
It will contain codes of pk (proxy kernel).
If you want to intermix source code with disassembly, use `-S` instead of `-D`.

Compile C files to assembly codes and link
------------------------------------------
```bash
riscv64-unknown-elf-gcc -S <SOURCE.c> -o <SOURCE.s>
riscv64-unknown-elf-gcc <SOURCE.s> -o <PROGRAM>
```
or
```bash
riscv64-unknown-elf-gcc -S <SOURCE.c> -o <SOURCE.s>
riscv64-unknown-elf-as <SOURCE.s> -o <SOURCE.o>
riscv64-unknown-elf-gcc <SOURCE.o> -o <PROGRAM>
```
The last line is actually equivalent to
```bash
riscv64-unknown-elf-ld /opt/riscv/riscv64-unknown-elf/lib/crt0.o /opt/riscv/lib/gcc/riscv64-unknown-elf/8.2.0/crtbegin.o <SOURCE.o> /opt/riscv/lib/gcc/riscv64-unknown-elf/8.2.0/crtend.o -L/opt/riscv/lib/gcc/riscv64-unknown-elf/8.2.0/ -lgcc --start-group -lc -lgloss --end-group -o <PROGRAM>
```
We can define our own link script `link.ld` and get rid of newlib.

Compile assembly codes without newlib
-------------------------------------
See `Makefile` and `examples/assembly`

Compile assembly and C codes
----------------------------
To be done.
