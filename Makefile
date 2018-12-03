all: build build/add

build:
	mkdir -p build

build/add: examples/assembly/add.S
	riscv64-unknown-elf-gcc -nostdlib -nostartfiles \
	-T./examples/link.ld examples/assembly/add.S -o build/add
