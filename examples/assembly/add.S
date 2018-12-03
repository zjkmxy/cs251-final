# Test for single file compilation
# Copied from gem5/tests/test-progs

#define EXIT_SYSCALL 93
#define TESTNUM gp

  .macro init; 
  .endm

.section .text.init;
.align  6;
.weak stvec_handler;
.weak mtvec_handler;
.globl _start;
_start:
        la t0, 1f;
        jr t0;
        .align 2;
1:
        la t0, _prog_main;
        jr t0;

.section .text;
.align 2
_prog_main:

test_99:
    # Test if 0x3 + 0x7 = 0xb
    # Return 0 if yes, 99 otherwise
    li  x1, 0x00000003;
    li  x2, 0x00000007;
    add x30, x1, x2;
    li  x29, 0x0000000b;
    li  TESTNUM, 99;
    bne x30, x29, fail;

test_pass_fail:
        bne x0, TESTNUM, pass;
fail:
        fence;
        mv a0, TESTNUM; 
        li a7, EXIT_SYSCALL;
        ecall;
pass:
        fence;
        li a0, 0;

code_end:
        li a7, EXIT_SYSCALL;
        ecall;


.data
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
.align 4; 
.global begin_signature; 
begin_signature:

.align 4;
.global end_signature;
end_signature:
