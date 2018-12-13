all: build \
	 build/3mm \
	 build/floyd \
	 build/sieve

test: all
	../gem5/./build/RISCV/gem5.opt ../gem5/configs/example/se.py -c build/sieve

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

build/print.o: examples/common/print.S \
			   examples/common/config.h
	riscv64-unknown-elf-gcc -c \
	examples/common/print.S \
	-o build/print.o

build/start.o: examples/common/start.S \
			   examples/common/config.h
	riscv64-unknown-elf-gcc -c \
	examples/common/start.S \
	-o build/start.o

build/string.o: examples/common/string.c \
			    examples/common/config.h
	riscv64-unknown-elf-gcc -c \
	-fPIC \
	examples/common/string.c \
	-o build/string.o

build/muladd.o: examples/common/muladd.S \
			    examples/common/config.h \
				examples/common/vecinsts.h
	riscv64-unknown-elf-gcc -c \
	examples/common/muladd.S \
	-o build/muladd.o

build/vecmisc.o: examples/common/vecmisc.S \
			    examples/common/config.h \
				examples/common/vecinsts.h
	riscv64-unknown-elf-gcc -c \
	examples/common/vecmisc.S \
	-o build/vecmisc.o

build/3mm: examples/3mm/3mm.c \
		   examples/3mm/3mm.h \
		   build/print.o \
           build/start.o \
		   build/muladd.o \
		   build/string.o
	riscv64-unknown-elf-gcc -I./examples/common \
	-nostdlib -nostartfiles -T./examples/link.ld \
	-fPIC \
	build/start.o \
    build/print.o \
	build/muladd.o \
	build/string.o \
	examples/3mm/3mm.c \
	-o build/3mm -O2

build/floyd: examples/floyd_warshall/floyd.c \
		     examples/floyd_warshall/floyd.h \
		     build/print.o \
             build/start.o \
		     build/vecmisc.o \
			 build/string.o
	riscv64-unknown-elf-gcc -I./examples/common \
	-nostdlib -nostartfiles -T./examples/link.ld \
	-fPIC \
	build/start.o \
    build/print.o \
	build/vecmisc.o \
	build/string.o \
	examples/floyd_warshall/floyd.c \
	-o build/floyd -O2

build/sieve: examples/linear_sieve/sieve.c \
		     examples/linear_sieve/sieve.h \
		     build/print.o \
             build/start.o \
		     build/vecmisc.o \
			 build/string.o
	riscv64-unknown-elf-gcc -I./examples/common \
	-nostdlib -nostartfiles -T./examples/link.ld \
	-fPIC \
	build/start.o \
    build/print.o \
	build/vecmisc.o \
	build/string.o \
	examples/linear_sieve/sieve.c \
	-o build/sieve -O2

clean:
	rm -rf build
