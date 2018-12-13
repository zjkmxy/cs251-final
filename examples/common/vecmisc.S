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
    VMERGEX(3, R_A2, 3, MASK_SCALAR)
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
    VSLT(0, 1, 2, MASK_VECTOR)
    # vmerge v2, v1, v2, v0.t # v2 = v1 < v2 ? v1 : v2
    VMERGE(2, 1, 2, MASK_V0T)
    # vsw.v v2, (a3) # *w = v2
    VSW(2, R_A3, 0)
    add a1, a1, t0
    add a3, a3, t0
    bne a0, x0, 1b # while (n != 0) 
    ret

fdis_relax:
    .globl fdis_relax
    # ***********************
    # brief:
    #   W[i] = min{W[i], X[i] + edge}
    # input: 
    #   a0 = N
    #   a1 = addr of X
    #   fa0 = weight of edge
    #   a2 = addr of W
    # output: 
    #   W[]
    # ctype: 
    #   dis_relax (int, float *, float, float *) -> void
    # ***********************
    li t0, 4
    # vsetvli x0, a0, vint32 # vl <- 4
    VSETVL(0, R_T0)
    fmv.x.w a3, fa0
    # vmv v3.s, a2 # v3 = edge
    VMERGEX(3, R_A3, 3, MASK_SCALAR)
1:
    # vsetvli t0, a0, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A0)
    sub a0, a0, t0 # n <- n - vector to be dealt
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v1, (a1) # v1 = *x
    VLW(1, R_A1, 0)
    # vlw.v v2, (a2) # v2 = *w
    VLW(2, R_A2, 0)
    # vadd.vv v1, v1, v3 # v1 = v1 + v3
    VFADD(1, 1, 3, MASK_VECTOR)
    # vfmin v2, v1, v2
    VFMIN(2, 1, 2, MASK_VECTOR)
    # vsw.v v2, (a2) # *w = v2
    VSW(2, R_A2, 0)
    add a1, a1, t0
    add a2, a2, t0
    bne a0, x0, 1b # while (n != 0) 
    ret

sieve_with:
    .globl sieve_with
    # ***********************
    # brief:
    #   Sieve all
    # input: 
    #   a0 = N
    #   a1 = X
    #   a2 = addr of prime[]
    #   a3 = size of prime[]
    #   a4 = addr of flag[]
    # output: 
    #   flag[prime[j] * X] = prime[j]
    # ctype: 
    #   sieve_with (int, int, int *, int, int *) -> void
    # ***********************
    li t0, 4
    # vsetvli x0, a0, vint32 # vl <- 4
    VSETVL(0, R_T0)
    # vmv v1.s, a1 # v1 = X
    VMERGEX(1, R_A1, 1, MASK_SCALAR)
    # vmv v3.s, a0 # v3 = N
    VMERGEX(3, R_A0, 3, MASK_SCALAR)
    # vmvi v5.0, 0 # v5 = 0
    VXOR(5, 5, 5, MASK_SCALAR)
1:
    # vsetvli t0, a3, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A3)
    sub a3, a3, t0
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    # vlw.v v2, (a2) # v2 = *prime
    VLW(2, R_A2, 0)
    # vmul.v v4, v2, v1 # v4 = v2 * X
    VMUL(4, 2, 1, MASK_VECTOR)
    # vslt.vv v0, v4, v3 # v0 = v4 < v3
    VSLT(0, 4, 3, MASK_VECTOR)
    # vxor.vv v4, v4, v4, v0.f # v4[i] = v4[i] >= N ? 0 : v4[i]
    VXOR(4, 4, 4, MASK_V0F)
    # v4 = v4 << 2 ; Calculate offset
    VSLI(4, 4, 2, MASK_V0T)
    # flag[v4] = v2
    VSXW(R_A4, 4, 2)
    # v4 = X % v2
    VREM(4, 1, 2, MASK_V0T)
    # v0 = v0 & (v4 != 0)
    VSNE(0, 4, 5, MASK_V0T)
    # t2 = sum{v0}
    VREDSUM(2, 0, MASK_V0T)
    VEXTRACT(R_T2, 2, 0)
    add a2, a2, t0
    # while(t2 == 4)
    li t3, 4
    beq t2, t3, 1b
    ret

sieve_with2:
    .globl sieve_with2
    # ***********************
    # brief:
    #   Sieve all
    # input: 
    #   a0 = N
    #   a1 = X
    #   a2 = addr of prime[]
    #   a3 = flag[X]
    #   a4 = addr of flag[]
    # output: 
    #   flag[prime[j] * X] = j + 1
    # ctype: 
    #   sieve_with (int, int, int *, int, int *) -> void
    # ***********************
    li t0, 4
    # vsetvli x0, a0, vint32 # vl <- 4
    VSETVL(0, R_T0)
    # vmv v1.s, a1 # v1 = X
    VMERGEX(1, R_A1, 1, MASK_SCALAR)
    # vmv v3.s, a0 # v3 = N
    VMERGEX(3, R_A0, 3, MASK_SCALAR)
    # vmvi v5.0, 0 # v5 = 0
    VXOR(5, 5, 5, MASK_SCALAR)

    la t0, TEMP
    VLW(7, R_T0, 0)
1:
    # vsetvli t0, a3, vint32 # t0 <- vector length
    VSETVL(R_T0, R_A3)
    sub a3, a3, t0
    # vlw.v v2, (a2) # v2 = *prime
    VLW(2, R_A2, 0)
    # vmul.v v4, v2, v1 # v4 = v2 * X
    VMUL(4, 2, 1, MASK_VECTOR)
    # vslt.vv v0, v4, v3 # v0 = v4 < v3
    VSLT(0, 4, 3, MASK_VECTOR)
    # vxor.vv v4, v4, v4, v0.f # v4[i] = v4[i] >= N ? 0 : v4[i]
    VXOR(4, 4, 4, MASK_V0F)
    # v4 = v4 << 2 ; Calculate offset
    VSLI(4, 4, 2, MASK_V0T)
    # flag[v4] = v7
    VSXW(R_A4, 4, 7)

    beq a3, zero, 2f

    # v7 += t0
    VMERGEX(6, R_T0, 6, MASK_SCALAR)
    VADD(7, 7, 6, MASK_VECTOR)
    
    # v4 = X % v2
    #VREM(4, 1, 2, MASK_V0T)
    # v0 = v0 & (v4 != 0)
    #VSNE(0, 4, 5, MASK_V0T)

    # t2 = sum{v0}
    VREDSUM(2, 0, MASK_V0T)
    VEXTRACT(R_T2, 2, 0)
    slli t0, t0, 2 # t0 <- sizeof(int32[t0])
    add a2, a2, t0
    # while(t2 == 4)
    li t3, 4
    beq t2, t3, 1b
2:
    ret

    .data
TEMP:
    .word 1, 2, 3, 4

# ===== Text section ends =====