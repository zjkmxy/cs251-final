test: all
	../gem5/./build/RISCV/gem5.opt ../gem5/configs/example/se.py -c build/3mm
	
all: build \
     build/add \
	 build/print \
	 build/3mm

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

build/3mm: examples/3mm/print.S \
           examples/3mm/start.S \
           examples/3mm/3mm.c \
		   examples/3mm/3mm.h \
		   examples/3mm/config.h \
		   examples/3mm/vecinsts.h \
		   examples/3mm/muladd.S
	riscv64-unknown-elf-gcc -nostdlib -nostartfiles -T./examples/link.ld \
	-fPIC \
	examples/3mm/muladd.S \
	examples/3mm/print.S \
	examples/3mm/start.S \
	examples/3mm/3mm.c \
	-o build/3mm -O2

clean:
	rm -rf build
