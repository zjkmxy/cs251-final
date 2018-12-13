#ifndef _VECINSTS_H
#define _VECINSTS_H

#ifdef __ASSEMBLER__

#define REGD(no) ((no & 0x1F) << 7)
#define REGS1(no) ((no & 0x1F) << 15)
#define REGS2(no) ((no & 0x1F) << 20)
#define REGS3(no) ((no & 0x1F) << 27)
#define MAKEIMM(no) ((no & 0xFF) << 20)

#define R_T0 0x05
#define R_T1 0x06
#define R_T2 0x07
#define R_S0 0x08
#define R_S1 0x09
#define R_A0 0x0a
#define R_A1 0x0b
#define R_A2 0x0c
#define R_A3 0x0d
#define R_A4 0x0e
#define R_A5 0x0f
#define R_A6 0x10
#define R_A7 0x11
#define R_S2 0x12
#define R_S3 0x13
#define R_S4 0x14
#define R_S5 0x15
#define R_S6 0x16
#define R_S7 0x17
#define R_S8 0x18
#define R_S9 0x19
#define R_S10 0x1a
#define R_S11 0x1b
#define R_T3 0x1c
#define R_T4 0x1d
#define R_T5 0x1e
#define R_T6 0x1f

#define MASK_SCALAR (0x0)
#define MASK_VECTOR (0x1)
#define MASK_V0F    (0x2)
#define MASK_V0T    (0x3)

#define VSETVL(rd, rs1) \
    .word (0xf0004057 | REGD(rd) | REGS1(rs1))

#define VLW(vd, rs1, offset) \
    .word (0x00006007 | REGD(vd) | REGS1(rs1) | ((offset & 0x07) << 29))

#define VLSW(vd, rs1, offset, rs2) \
    .word (0x00006007 | REGD(vd) | REGS1(rs1) | REGS2(rs2) | ((offset & 0x07) << 29))

#define VSW(vs3, rs1, offset) \
    .word (0x00006027 | REGS3(vs3) | REGS1(rs1) | ((offset & 0x07) << 9))

#define VSSW(vs3, rs1, offset) \
    .word (0x00006027 | REGS3(vs3) | REGS1(rs1) | REGS2(rs2) | ((offset & 0x07) << 9))

#define VADD(vd, vs1, vs2, mask) \
    .word (0x90004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VSUB(vd, vs1, vs2, mask) \
    .word (0x92004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VXOR(vd, vs1, vs2, mask) \
    .word (0xC0004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VMADD(vd, vs1, vs2, mask) \
    .word (0xE0004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VREDSUM(vd, vs1, mask) \
    .word (0xCE404057 | REGD(vd) | REGS1(vs1) | (mask << 12))

#define VEXTRACT(rd, vs1, rs2) \
    .word (0xA0004057 | REGD(rd) | REGS1(vs1) | REGS2(rs2))

#define VFADD(rd, vs1, vs2, mask) \
    .word (0x00000057 | REGD(rd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VFSUB(rd, vs1, vs2, mask) \
    .word (0x08000057 | REGD(rd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VFMADD(rd, vs1, vs2, vs3) \
    .word (0x0000604b | REGD(rd) | REGS1(vs1) | REGS2(vs2) | REGS3(vs3))

#define VFREDSUM(vd, vs1, mask) \
    .word (0x48400057 | REGD(vd) | REGS1(vs1) | (mask << 12))

#define VFEXTRACT(fd, vs1, rs2) \
    .word (0xA2004057 | REGD(fd) | REGS1(vs1) | REGS2(rs2))


#define VMERGE(vd, vs1, vs2, mask) \
    .word (0xC2004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VMERGEX(vd, rs1, vs2, mask) \
    .word (0xCA004057 | REGD(vd) | REGS1(rs1) | REGS2(vs2) | (mask << 12))

#define VSLT(vd, vs1, vs2, mask) \
    .word (0xD4004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VFMIN(vd, vs1, vs2, mask) \
    .word (0x38000057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VMUL(vd, vs1, vs2, mask) \
    .word (0x88004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VSXW(rs1, vs2, vs3) \
    .word (0x000060A7 | REGS1(rs1) | REGS2(vs2) | REGS3(vs3))

#define VREM(vd, vs1, vs2, mask) \
    .word (0x84004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VSNE(vd, vs1, vs2, mask) \
    .word (0xD2004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VSL(vd, vs1, vs2, mask) \
    .word (0x94004057 | REGD(vd) | REGS1(vs1) | REGS2(vs2) | (mask << 12))

#define VSLI(vd, vs1, imm, mask) \
    .word (0x10004057 | REGD(vd) | REGS1(vs1) | MAKEIMM(imm) | (mask << 12))

#endif // __ASSEMBLER__

#endif // _VECINSTS_H
