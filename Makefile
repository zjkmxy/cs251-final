all: build build/add build/print

build:
	mkdir -p build

build/add: examples/assembly/add.S
	riscv64-unknown-elf-gcc -nostdlib -nostartfiles -T./examples/link.ld \
	examples/assembly/add.S \
	-o build/add

build/print: examples/withc/print.S \
             examples/withc/main.c \
			 examples/withc/config.h
	riscv64-unknown-elf-gcc -nostdlib -nostartfiles -T./examples/link.ld \
	-fPIC \
	examples/withc/print.S \
	examples/withc/main.c \
	-o build/print

clean:
	rm -rf build
