#include "config.h"

# ===== Text section starts =====
    .section .text;
    .align 2
print:
    .globl print
    # ***********************
    # brief:
    #   print a string of specified length
    # input: 
    #   a0 = None
    #   a1 = addr of string
    #   a2 = length of string
    # output: 
    #   a0 = bytes written
    # ctype: 
    #   print (void*, char*, size_t) -> int
    # ***********************
    # save ra
    addi sp, sp, -8
    sd ra, 0(sp)
    # a0 = system call (WRITE_SYSCALL, STDOUT, str, len, 0, 0, 0)
    li a7, WRITE_SYSCALL
    li a0, STDOUT
    li a3, 0
    li a4, 0
    li a5, 0
    ecall
    # load ra & return
    ld ra, 0(sp)
    addi sp, sp, 8
    ret

# ===== Text section ends =====