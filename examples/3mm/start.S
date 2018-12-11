# Test for single file compilation
# Copied from gem5/tests/test-progs

#include "config.h"
#include "vecinsts.h"

    .macro init; 
    .endm

# ===== Init text section starts =====
    .section .text.init;
    .align  6;
    .weak stvec_handler;
    .weak mtvec_handler;
    .globl _start;
_start:
    # jump to real start
    la t0, 1f;
    jr t0;
    .align 2;
1:
    # setup stack; sp is very small by default
    la sp, STACK_TOP
    # jump to program main
    la t0, _prog_main;
    jr t0;

# ===== Init text section ends =====

# ===== Text section starts =====
    .section .text;
    .align 2
_prog_main:
    # a0 = cfile_main()
    # Notice that only low byte of a0 will be accepted as retcode.
    #call cfile_main
    call _test_in_asm
    # return a0
    # mv a0, a0

_prog_exit:
    .globl _prog_exit
    # Exported as exit() function
    # ctype: _prog_exit (unsigned char) -> void
    fence
    li a7, EXIT_SYSCALL
    ecall

_test_in_asm:
    li t0, 5
    VSETVL(R_A0, R_T0)
    la t0, arr_a
    la t1, arr_b
    VLW(1, R_T0, 0)
    VSW(1, R_T1, 0)
    lw a0, 0(t1)
    ret

# ===== Text section ends =====

# ===== Data section starts =====
# I don't know why but you cannot use msg in C program.
# GCC cannot get the correct address of it.
# But you can use C global variants in asm.
    .data
arr_a:
    .word 1, 2, 3, 4, 5, 6, 7, 8
arr_b:
    .word 0, 0, 0, 0, 0, 0, 0, 0

# TOHOST section
# Useless in our program. You cannot use it to communicate with gem5 host.
    .pushsection .tohost,"aw",@progbits;
    .align 6;
    .global tohost;
tohost: 
    .dword 0;
    .align 6;
    .global fromhost;
fromhost: 
    .dword 0;
    .popsection;

# Signature for end of data
# For the convenience of disassembly
    .align 4; 
    .global begin_signature; 
begin_signature:

    .align 4;
    .global end_signature;
end_signature:

# ===== Data section ends =====

# ===== Stack section starts =====
    .bss
_stack_begin:
    .zero STACK_SIZE
_stack_end:
# ===== Stack section ends =====