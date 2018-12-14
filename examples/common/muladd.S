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
    VADD(2, 0, 1, MASK_VECTOR)
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
    #   W[]
    # ctype: 
    #   muladd (int, int *, int *, int *) -> void
    # ***********************
    # vsetvli t0, a0, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v0, (a1) # v0 = *x
    VLW(0, R_A1, 0)
    # vlw.v v1, (a2) # v1 = *y
    VLW(1, R_A2, 0)
    # vlw.v v2, (a3) # v2 = *w
    VLW(2, R_A3, 0)
    # vmadd.vv v2, v0, v1 # v2 = v0 * v1 + v2
    VMADD(2, 0, 1, MASK_VECTOR)
    # vsw.v v2, (a3) # *w = v2
    VSW(2, R_A3, 0)
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
    li t0, 4
    # vsetvli x0, a0, vint32 # vl <- 4
    VSETVL(0, R_T0)
    # vxor.vv v2, v2, v2 # v2 <- 0
    VXOR(2, 2, 2, MASK_VECTOR)
1:
    # vsetvli t0, a0, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    mul t1, t0, a3 # t1 <- sizeof(Y[])
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v0, (a1) # v0 = x[]
    VLW(0, R_A1, 0)
    # vlsw.v v1, (a2), a3 # v1 = y[][a3]
    VLSW(1, R_A2, 0, R_A3)
    # vmadd.vv v2, v0, v1 # v2 = v0 * v1 + v2
    VMADD(2, 0, 1, MASK_VECTOR)
    add a1, a1, t0
    add a2, a2, t1
    bne a0, x0, 1b # while (n != 0) 
2:
    li a0, 4
    # vsetvli x0, a0, vint32 # vl <- 4
    VSETVL(0, R_A0)
    # vredsum v2.s, v2
    VREDSUM(2, 2, MASK_VECTOR)
    # vextract a0, v2, x0
    VEXTRACT(R_A0, 2, 0)
    ret

vextract:
    .globl vextract
    # ***********************
    # brief:
    #   Get ret = X[index]
    # input: 
    #   a0 = addr of X
    #   a1 = index
    # output: 
    #   a0 = ret
    # ctype: 
    #   vextract (int *, int) -> int
    # ***********************
    # vxor.vv v2, v2, v2 # v2 <- 0
    VSETVL(R_T0, R_A0)
    VLW(0, R_A0, 0)
    VEXTRACT(R_A0, 0, R_A1)
    ret

fmuladd:
    .globl fmuladd
    # ***********************
    # brief:
    #   W[i] = X[i] * Y[i] + Z[i]
    # input: 
    #   a0 = N
    #   a1 = addr of X
    #   a2 = addr of Y
    #   a3 = addr of Z
    #   a4 = addr of W
    # output: 
    #   W[]
    # ctype: 
    #   fmuladd (int, float *, float *, float *, float *) -> void
    # ***********************
    # vsetvli t0, a0, vfloat.s # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v0, (a1) # v0 = *x
    VLW(0, R_A1, 0)
    # vlw.v v1, (a2) # v1 = *y
    VLW(1, R_A2, 0)
    # vlw.v v2, (a3) # v2 = *z
    VLW(2, R_A3, 0)
    # vfmadd.vvv v3, v0, v1, v2 # v3 = v0 * v1 + v2
    VFMADD(3, 0, 1, 2)
    # vsw.v v3, (a4) # *w = v2
    VSW(3, R_A4, 0)
    add a1, a1, t0
    add a2, a2, t0
    add a3, a3, t0
    add a4, a4, t0
    bne a0, x0, fmuladd # while (n != 0) 
    ret

fdotprod:
    .globl fdotprod
    # ***********************
    # brief:
    #   Calc sum_i{X[i] * Y[i][b]}
    # input: 
    #   a0 = N
    #   a1 = addr of X
    #   a2 = addr of Y
    #   a3 = stride of Y
    # output: 
    #   fa0 = ret
    # ctype: 
    #   fdotprod (int, float *, float *, unsigned int) -> float
    # ***********************
    li t0, 4
    # vsetvli x0, a0, vint32 # vl <- 4
    VSETVL(0, R_T0)
    # vxor.vv v2, v2, v2 # v2 <- 0
    VXOR(2, 2, 2, MASK_VECTOR)
1:
    # vsetvli t0, a0, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    mul t1, t0, a3 # t1 <- sizeof(Y[])
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v0, (a1) # v0 = x[]
    VLW(0, R_A1, 0)
    # vlsw.v v1, (a2), a3 # v1 = y[][a3]
    VLSW(1, R_A2, 0, R_A3)
    # vmadd.vv v2, v0, v1 # v2 = v0 * v1 + v2
    VFMADD(2, 0, 1, 2)
    add a1, a1, t0
    add a2, a2, t1
    bne a0, x0, 1b # while (n != 0) 
2:
    li a0, 4
    # vsetvli x0, a0, vint32 # vl <- 4
    VSETVL(0, R_A0)
    # vredsum v2.s, v2
    VFREDSUM(2, 2, MASK_VECTOR)
    # vextract a0, v2, x0
    VFEXTRACT(R_A0, 2, 0)
    ret

# ===== Text section ends =====