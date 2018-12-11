#include "config.h"
#include "vecinsts.h"

# ===== Text section starts =====
    .section .text;
    .align 2
vecadd:
    .globl vecadd
    # ***********************
    # brief:
    #   W[i] = X[i] + Y[i]
    # input: 
    #   a0 = N
    #   a1 = addr of X
    #   a2 = addr of Y
    #   a3 = addr of W
    # output: 
    #   None
    # ctype: 
    #   vecadd (int, int *, int *, int *) -> void
    # ***********************
    # vsetvli t0, a0, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v0, (a1) # v0 = *x
    VLW(0, R_A1, 0)
    # vlw.v v1, (a2) # v1 = *y
    VLW(1, R_A2, 0)
    # vadd.vv v2, v0, v1 # v2 = v0 * v1 + v2
    VADD(2, 0, 1)
    # vsw.v v2, (a3) # *w = v2
    VSW(2, R_A3, 0)
    add a1, a1, t0
    add a2, a2, t0
    add a3, a3, t0
    bne a0, x0, vecadd # while (n != 0) 
    ret

muladd:
    .globl muladd
    # ***********************
    # brief:
    #   W[i] += X[i] * Y[i]
    # input: 
    #   a0 = N
    #   a1 = addr of X
    #   a2 = addr of Y
    #   a3 = addr of W
    # output: 
    #   None
    # ctype: 
    #   muladd (int, int *, int *, int *) -> void
    # ***********************
    # vsetvli t0, a0, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v0, (a1) # v0 = *x
    # vlw.v v1, (a2) # v1 = *y
    # vlw.v v2, (a3) # v2 = *w
    # vmadd.vv v2, v0, v1 # v2 = v0 * v1 + v2
    # vsw.v v2, (a3) # *w = v2
    add a1, a1, t0
    add a2, a2, t0
    add a3, a3, t0
    bne a0, x0, muladd # while (n != 0) 
    ret


dotprod:
    .globl dotprod
    # ***********************
    # brief:
    #   Calc sum_i{X[i] * Y[i][b]}
    # input: 
    #   a0 = N
    #   a1 = addr of X
    #   a2 = addr of Y
    #   a3 = stride of Y
    # output: 
    #   a0 = ret
    # ctype: 
    #   dotprod (int, int *, int *, int) -> int
    # ***********************
    # vxor.vv v2, v2, v2 # v2 <- 0
1:
    # vsetvli t0, a0, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v0, (a1) # v0 = x[]
    # vlsw.v v1, (a2), a3 # v1 = y[][a3]
    # vmadd.vv v2, v0, v1 # v2 = v0 * v1 + v2
    add a1, a1, t0
    add a2, a2, t0
    bne a0, x0, 1b # while (n != 0) 
2:
    # vredsum v2.s, v2
    # vextract a0, v2, x0
    ret


# ===== Text section ends =====