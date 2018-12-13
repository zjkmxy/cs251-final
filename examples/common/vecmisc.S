#include "config.h"
#include "vecinsts.h"

# ===== Text section starts =====
    .section .text;
    .align 2
dis_relax:
    .globl dis_relax
    # ***********************
    # brief:
    #   W[i] = min{W[i], X[i] + edge}
    # input: 
    #   a0 = N
    #   a1 = addr of X
    #   a2 = weight of edge
    #   a3 = addr of W
    # output: 
    #   W[]
    # ctype: 
    #   dis_relax (int, int *, int, int *) -> void
    # ***********************
    li t0, 4
    # vsetvli x0, a0, vint32 # vl <- 4
    VSETVL(0, R_T0)
    # vmv v3.s, a2 # v3 = edge
    # vmergex v3, a2, v3
1:
    # vsetvli t0, a0, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v1, (a1) # v1 = *x
    VLW(1, R_A1, 0)
    # vlw.v v2, (a3) # v2 = *w
    VLW(2, R_A3, 0)
    # vadd.vv v1, v1, v3 # v1 = v1 + v3
    VADD(1, 1, 3, MASK_VECTOR)
    # vslt v0, v1, v2
    # vmerge v2, v1, v2, v0.t # v2 = v1 < v2 ? v1 : v2
    # vsw.v v2, (a3) # *w = v2
    VSW(2, R_A3, 0)
    add a1, a1, t0
    add a3, a3, t0
    bne a0, x0, vecadd # while (n != 0) 
    ret

# ===== Text section ends =====