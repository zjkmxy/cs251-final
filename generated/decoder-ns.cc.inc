// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   riscv/isa/main.isa

#if !defined(__SPLIT) || (__SPLIT == 1)

// CIOp::c_addi4spn((['\n            imm = CIMM8<1:1> << 2 |\n                  CIMM8<0:0> << 3 |\n                  CIMM8<7:6> << 4 |\n                  CIMM8<5:2> << 6;\n        ', '\n            if (machInst == 0)\n                fault = make_shared<IllegalInstFault>("zero instruction",\n                                                      machInst);\n            Rp2 = sp + imm;\n        ', 'uint64_t'], {}))

    C_addi4spn::C_addi4spn(MachInst machInst)
        : ImmOp<uint64_t>("c_addi4spn", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, StackPointerReg);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP2 + 8);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
            imm = bits(CIMM8, 1, 1) << 2 |
                  bits(CIMM8, 0, 0) << 3 |
                  bits(CIMM8, 7, 6) << 4 |
                  bits(CIMM8, 5, 2) << 6;
        ;
    }

// CompressedLoad::c_fld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Fp2_bits = Mem;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_fld::C_fld(ExtMachInst machInst):
        Load("c_fld", machInst, FloatMemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FP2 + 8);
	_numFPDestRegs++;
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        
                offset = CIMM3 << 3 | CIMM2 << 6;
            ;
    }

// CompressedLoad::c_lw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Rp2_sd = Mem_sw;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_lw::C_lw(ExtMachInst machInst):
        Load("c_lw", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP2 + 8);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        
                offset = bits(CIMM2, 1, 1) << 2 |
                         CIMM3 << 3 |
                         bits(CIMM2, 0, 0) << 6;
            ;
    }

// CompressedLoad::c_ld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Rp2_sd = Mem_sd;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_ld::C_ld(ExtMachInst machInst):
        Load("c_ld", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP2 + 8);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        
                offset = CIMM3 << 3 | CIMM2 << 6;
            ;
    }

// CompressedStore::c_fsd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Mem = Fp2_bits;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_fsd::C_fsd(ExtMachInst machInst):
        Store("c_fsd", machInst, FloatMemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FP2 + 8);
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        
                offset = CIMM3 << 3 | CIMM2 << 6;
            ;
    }

// CompressedStore::c_sw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Mem_uw = Rp2_uw;\n            '],{'ea_code': '\n                EA = Rp1 + offset;\n            '})

    C_sw::C_sw(ExtMachInst machInst):
        Store("c_sw", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP2 + 8);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        
                offset = bits(CIMM2, 1, 1) << 2 |
                         CIMM3 << 3 |
                         bits(CIMM2, 0, 0) << 6;
            ;
    }

// CompressedStore::c_sd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                    Mem_ud = Rp2_ud;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_sd::C_sd(ExtMachInst machInst):
        Store("c_sd", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP2 + 8);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        
                offset = CIMM3 << 3 | CIMM2 << 6;
            ;
    }

// Unknown::unknown(([], {}))

// CIOp::c_addi(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if ((RC1 == 0) != (imm == 0)) {\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    } else // imm == 0\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                }\n                Rc1_sd = Rc1_sd + imm;\n            '],{})

    C_addi::C_addi(MachInst machInst)
        : ImmOp<int64_t>("c_addi", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                imm = CIMM5;
                if (CIMM1 > 0)
                    imm |= ~((uint64_t)0x1F);
            ;
    }

// CIOp::c_addiw(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = (int32_t)Rc1_sd + imm;\n            '],{})

    C_addiw::C_addiw(MachInst machInst)
        : ImmOp<int64_t>("c_addiw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                imm = CIMM5;
                if (CIMM1 > 0)
                    imm |= ~((uint64_t)0x1F);
            ;
    }

// CIOp::c_li(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = imm;\n            '],{})

    C_li::C_li(MachInst machInst)
        : ImmOp<int64_t>("c_li", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                imm = CIMM5;
                if (CIMM1 > 0)
                    imm |= ~((uint64_t)0x1F);
            ;
    }

// CIOp::c_addi16sp(['\n                    imm = CIMM5<4:4> << 4 |\n                          CIMM5<0:0> << 5 |\n                          CIMM5<3:3> << 6 |\n                          CIMM5<2:1> << 7;\n                    if (CIMM1 > 0)\n                        imm |= ~((int64_t)0x1FF);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    sp_sd = sp_sd + imm;\n                '],{})

    C_addi16sp::C_addi16sp(MachInst machInst)
        : ImmOp<int64_t>("c_addi16sp", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, StackPointerReg);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, StackPointerReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = bits(CIMM5, 4, 4) << 4 |
                          bits(CIMM5, 0, 0) << 5 |
                          bits(CIMM5, 3, 3) << 6 |
                          bits(CIMM5, 2, 1) << 7;
                    if (CIMM1 > 0)
                        imm |= ~((int64_t)0x1FF);
                ;
    }

// CIOp::c_lui(['\n                    imm = CIMM5 << 12;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1FFFF);\n                ', '\n                    if (RC1 == 0 || RC1 == 2) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rc1_sd = imm;\n                '],{})

    C_lui::C_lui(MachInst machInst)
        : ImmOp<int64_t>("c_lui", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = CIMM5 << 12;
                    if (CIMM1 > 0)
                        imm |= ~((uint64_t)0x1FFFF);
                ;
    }

// CIOp::c_srli(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rp1 = Rp1 >> imm;\n                ', 'uint64_t'],{})

    C_srli::C_srli(MachInst machInst)
        : ImmOp<uint64_t>("c_srli", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = CIMM5 | (CIMM1 << 5);
                ;
    }

// CIOp::c_srai(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rp1_sd = Rp1_sd >> imm;\n                ', 'uint64_t'],{})

    C_srai::C_srai(MachInst machInst)
        : ImmOp<uint64_t>("c_srai", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = CIMM5 | (CIMM1 << 5);
                ;
    }

// CIOp::c_andi(['\n                    imm = CIMM5;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1F);\n                ', '\n                    Rp1 = Rp1 & imm;\n                ', 'uint64_t'],{})

    C_andi::C_andi(MachInst machInst)
        : ImmOp<uint64_t>("c_andi", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = CIMM5;
                    if (CIMM1 > 0)
                        imm |= ~((uint64_t)0x1F);
                ;
    }

// ROp::c_sub(['\n                            Rp1 = Rp1 - Rp2;\n                        '],{})

    C_sub::C_sub(MachInst machInst)
        : RegOp("c_sub", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP2 + 8);
	flags[IsInteger] = true;;
    }

// ROp::c_xor(['\n                            Rp1 = Rp1 ^ Rp2;\n                        '],{})

    C_xor::C_xor(MachInst machInst)
        : RegOp("c_xor", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP2 + 8);
	flags[IsInteger] = true;;
    }

// ROp::c_or(['\n                            Rp1 = Rp1 | Rp2;\n                        '],{})

    C_or::C_or(MachInst machInst)
        : RegOp("c_or", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP2 + 8);
	flags[IsInteger] = true;;
    }

// ROp::c_and(['\n                            Rp1 = Rp1 & Rp2;\n                        '],{})

    C_and::C_and(MachInst machInst)
        : RegOp("c_and", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP2 + 8);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::c_subw(['\n                            Rp1_sd = (int32_t)Rp1_sd - Rp2_sw;\n                        '],{})

    C_subw::C_subw(MachInst machInst)
        : RegOp("c_subw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP2 + 8);
	flags[IsInteger] = true;;
    }

// ROp::c_addw(['\n                            Rp1_sd = (int32_t)Rp1_sd + Rp2_sw;\n                        '],{})

    C_addw::C_addw(MachInst machInst)
        : RegOp("c_addw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RP1 + 8);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP2 + 8);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// JOp::c_j((['\n            int64_t offset = CJUMPIMM<3:1> << 1 |\n                             CJUMPIMM<9:9> << 4 |\n                             CJUMPIMM<0:0> << 5 |\n                             CJUMPIMM<5:5> << 6 |\n                             CJUMPIMM<4:4> << 7 |\n                             CJUMPIMM<8:7> << 8 |\n                             CJUMPIMM<6:6> << 10;\n            if (CJUMPIMM<10:10> > 0)\n                offset |= ~((int64_t)0x7FF);\n            NPC = PC + offset;\n        ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    C_j::C_j(MachInst machInst)
        : ImmOp<int64_t>("c_j", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsUncondControl] = true;;
        
                imm = UJIMMBITS10TO1 << 1   |
                      UJIMMBIT11 << 11      |
                      UJIMMBITS19TO12 << 12 |
                      IMMSIGN << 20;
                imm = sext<21>(imm);
               ;
    }

// CBOp::c_beqz(['\n                if (Rp1 == 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    C_beqz::C_beqz(MachInst machInst)
        : ImmOp<int64_t>("c_beqz", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = bits(CIMM5, 2, 1) << 1 |
                      bits(CIMM3, 1, 0) << 3 |
                      bits(CIMM5, 0, 0) << 5 |
                      bits(CIMM5, 4, 3) << 6;
                if (bits(CIMM3, 2, 2) > 0)
                    imm |= ~((int64_t)0xFF);
               ;
    }

// CBOp::c_bnez(['\n                if (Rp1 != 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    C_bnez::C_bnez(MachInst machInst)
        : ImmOp<int64_t>("c_bnez", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RP1 + 8);
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = bits(CIMM5, 2, 1) << 1 |
                      bits(CIMM3, 1, 0) << 3 |
                      bits(CIMM5, 0, 0) << 5 |
                      bits(CIMM5, 4, 3) << 6;
                if (bits(CIMM3, 2, 2) > 0)
                    imm |= ~((int64_t)0xFF);
               ;
    }

// Unknown::unknown(([], {}))

// CIOp::c_slli((['\n            imm = CIMM5 | (CIMM1 << 5);\n        ', '\n            if (imm == 0) {\n                fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                      machInst);\n            }\n            if (RC1 == 0) {\n                fault = make_shared<IllegalInstFault>("source reg x0",\n                                                      machInst);\n            }\n            Rc1 = Rc1 << imm;\n        ', 'uint64_t'], {}))

    C_slli::C_slli(MachInst machInst)
        : ImmOp<uint64_t>("c_slli", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
            imm = CIMM5 | (CIMM1 << 5);
        ;
    }

// CompressedLoad::c_fldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                Fc1_bits = Mem;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_fldsp::C_fldsp(ExtMachInst machInst):
        Load("c_fldsp", machInst, FloatMemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FC1);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, StackPointerReg);
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        
                offset = bits(CIMM5, 4, 3) << 3 |
                         CIMM1 << 5 |
                         bits(CIMM5, 2, 0) << 6;
            ;
    }

// CompressedLoad::c_lwsp(['\n                offset = CIMM5<4:2> << 2 |\n                         CIMM1 << 5 |\n                         CIMM5<1:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = Mem_sw;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_lwsp::C_lwsp(ExtMachInst machInst):
        Load("c_lwsp", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, StackPointerReg);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        
                offset = bits(CIMM5, 4, 2) << 2 |
                         CIMM1 << 5 |
                         bits(CIMM5, 1, 0) << 6;
            ;
    }

// CompressedLoad::c_ldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = Mem_sd;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_ldsp::C_ldsp(ExtMachInst machInst):
        Load("c_ldsp", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, StackPointerReg);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        
                offset = bits(CIMM5, 4, 3) << 3 |
                         CIMM1 << 5 |
                         bits(CIMM5, 2, 0) << 6;
            ;
    }

// Jump::c_jr((['\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    NPC = Rc1;\n                ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    C_jr::C_jr(MachInst machInst)
        : ImmOp<int64_t>("c_jr", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC1);
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
        imm = sext<12>(IMM12);;
    }

// CROp::c_mv((['\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    Rc1 = Rc2;\n                '], {}))

    C_mv::C_mv(MachInst machInst)
        : CompRegOp("c_mv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC2);
	flags[IsInteger] = true;;
    }

// SystemOp::c_ebreak((['\n                    if (RC2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    fault = make_shared<BreakpointFault>(xc->pcState());\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'], {}))

    C_ebreak::C_ebreak(MachInst machInst)
        : SystemOp("c_ebreak", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// Jump::c_jalr((['\n                        if (RC1 == 0) {\n                            fault = make_shared<IllegalInstFault>\n                                                        ("source reg x0",\n                                                         machInst);\n                        }\n                        ra = NPC;\n                        NPC = Rc1;\n                    ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    C_jalr::C_jalr(MachInst machInst)
        : ImmOp<int64_t>("c_jalr", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, ReturnAddrReg);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC1);
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
        imm = sext<12>(IMM12);;
    }

// ROp::c_add((['\n                        Rc1_sd = Rc1_sd + Rc2_sd;\n                    '], {}))

    C_add::C_add(MachInst machInst)
        : RegOp("c_add", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RC1);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// CompressedStore::c_fsdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem_ud = Fc2_bits;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_fsdsp::C_fsdsp(ExtMachInst machInst):
        Store("c_fsdsp", machInst, FloatMemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, StackPointerReg);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FC2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        
                offset = bits(CIMM6, 5, 3) << 3 |
                         bits(CIMM6, 2, 0) << 6;
            ;
    }

// CompressedStore::c_swsp(['\n                offset = CIMM6<5:2> << 2 |\n                         CIMM6<1:0> << 6;\n            ', '\n                Mem_uw = Rc2_uw;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_swsp::C_swsp(ExtMachInst machInst):
        Store("c_swsp", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, StackPointerReg);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC2);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        
                offset = bits(CIMM6, 5, 2) << 2 |
                         bits(CIMM6, 1, 0) << 6;
            ;
    }

// CompressedStore::c_sdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem = Rc2;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_sdsp::C_sdsp(ExtMachInst machInst):
        Store("c_sdsp", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, StackPointerReg);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RC2);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        
                offset = bits(CIMM6, 5, 3) << 3 |
                         bits(CIMM6, 2, 0) << 6;
            ;
    }

// Unknown::unknown(([], {}))

// Load::lb(['\n                    Rd_sd = Mem_sb;\n                '],{})

    Lb::Lb(ExtMachInst machInst):
        Load("lb", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lh(['\n                    Rd_sd = Mem_sh;\n                '],{})

    Lh::Lh(ExtMachInst machInst):
        Load("lh", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lw(['\n                    Rd_sd = Mem_sw;\n                '],{})

    Lw::Lw(ExtMachInst machInst):
        Load("lw", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::ld(['\n                    Rd_sd = Mem_sd;\n                '],{})

    Ld::Ld(ExtMachInst machInst):
        Load("ld", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lbu(['\n                    Rd = Mem_ub;\n                '],{})

    Lbu::Lbu(ExtMachInst machInst):
        Load("lbu", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lhu(['\n                    Rd = Mem_uh;\n                '],{})

    Lhu::Lhu(ExtMachInst machInst):
        Load("lhu", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lwu(['\n                    Rd = Mem_uw;\n                '],{})

    Lwu::Lwu(ExtMachInst machInst):
        Load("lwu", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// Load::flw(['\n                    Fd_bits = (uint64_t)Mem_uw;\n                '],{'inst_flags': 'FloatMemReadOp'})

    Flw::Flw(ExtMachInst machInst):
        Load("flw", machInst, FloatMemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::fld(['\n                    Fd_bits = Mem;\n                '],{'inst_flags': 'FloatMemReadOp'})

    Fld::Fld(ExtMachInst machInst):
        Load("fld", machInst, FloatMemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        offset = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// IOp::fence(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsMemBarrier', 'No_OpClass'],{})

    Fence::Fence(MachInst machInst)
        : ImmOp<uint64_t>("fence", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsMemBarrier] = true;
	flags[IsNonSpeculative] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::fence_i(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    Fence_i::Fence_i(MachInst machInst)
        : ImmOp<uint64_t>("fence_i", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
        imm = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// IOp::addi(['\n                    Rd_sd = Rs1_sd + imm;\n                '],{})

    Addi::Addi(MachInst machInst)
        : ImmOp<int64_t>("addi", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::slli(['\n                    Rd = Rs1 << SHAMT6;\n                '],{})

    Slli::Slli(MachInst machInst)
        : ImmOp<int64_t>("slli", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::slti(['\n                    Rd = (Rs1_sd < imm) ? 1 : 0;\n                '],{})

    Slti::Slti(MachInst machInst)
        : ImmOp<int64_t>("slti", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::sltiu(['\n                    Rd = (Rs1 < imm) ? 1 : 0;\n                ', 'uint64_t'],{})

    Sltiu::Sltiu(MachInst machInst)
        : ImmOp<uint64_t>("sltiu", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::xori(['\n                    Rd = Rs1 ^ imm;\n                ', 'uint64_t'],{})

    Xori::Xori(MachInst machInst)
        : ImmOp<uint64_t>("xori", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::srli(['\n                        Rd = Rs1 >> SHAMT6;\n                    '],{})

    Srli::Srli(MachInst machInst)
        : ImmOp<int64_t>("srli", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::srai(['\n                        Rd_sd = Rs1_sd >> SHAMT6;\n                    '],{})

    Srai::Srai(MachInst machInst)
        : ImmOp<int64_t>("srai", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// IOp::ori(['\n                    Rd = Rs1 | imm;\n                ', 'uint64_t'],{})

    Ori::Ori(MachInst machInst)
        : ImmOp<uint64_t>("ori", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::andi(['\n                    Rd = Rs1 & imm;\n                ', 'uint64_t'],{})

    Andi::Andi(MachInst machInst)
        : ImmOp<uint64_t>("andi", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// UOp::auipc((['\n            Rd = PC + imm;\n        '], {}))

    Auipc::Auipc(MachInst machInst)
        : ImmOp<int64_t>("auipc", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        imm = sext<20>(IMM20) << 12;;
    }

// IOp::addiw(['\n                    Rd_sd = Rs1_sw + imm;\n                ', 'int32_t'],{})

    Addiw::Addiw(MachInst machInst)
        : ImmOp<int32_t>("addiw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::slliw(['\n                    Rd_sd = Rs1_sw << SHAMT5;\n                '],{})

    Slliw::Slliw(MachInst machInst)
        : ImmOp<int64_t>("slliw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::srliw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> SHAMT5);\n                    '],{})

    Srliw::Srliw(MachInst machInst)
        : ImmOp<int64_t>("srliw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::sraiw(['\n                        Rd_sd = Rs1_sw >> SHAMT5;\n                    '],{})

    Sraiw::Sraiw(MachInst machInst)
        : ImmOp<int64_t>("sraiw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Store::sb(['\n                    Mem_ub = Rs2_ub;\n                '],{})

    Sb::Sb(ExtMachInst machInst):
        Store("sb", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Store::sh(['\n                    Mem_uh = Rs2_uh;\n                '],{})

    Sh::Sh(ExtMachInst machInst):
        Store("sh", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Store::sw(['\n                    Mem_uw = Rs2_uw;\n                '],{})

    Sw::Sw(ExtMachInst machInst):
        Store("sw", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Store::sd(['\n                    Mem_ud = Rs2_ud;\n                '],{})

    Sd::Sd(ExtMachInst machInst):
        Store("sd", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Unknown::unknown(([], {}))

// Store::fsw(['\n                    Mem_uw = (uint32_t)Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    Fsw::Fsw(ExtMachInst machInst):
        Store("fsw", machInst, FloatMemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Store::fsd(['\n                    Mem_ud = Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    Fsd::Fsd(ExtMachInst machInst):
        Store("fsd", machInst, FloatMemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Unknown::unknown(([], {}))

// LoadReserved::lr_w((['\n                    Rd_sd = Mem_sw;\n                '], {'mem_flags': 'LLSC'}))

    Lr_w::Lr_w(ExtMachInst machInst):
        LoadReserved("lr_w", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;
	memAccessFlags = memAccessFlags | Request::LLSC;;
        if (AQ)
            memAccessFlags = memAccessFlags | Request::ACQUIRE;
        if (RL)
            memAccessFlags = memAccessFlags | Request::RELEASE;
    }

// StoreCond::sc_w((['\n                    Mem_uw = Rs2_uw;\n                ', '\n                    Rd = result;\n                '], {'mem_flags': 'LLSC', 'inst_flags': 'IsStoreConditional'}))

    Sc_w::Sc_w(ExtMachInst machInst):
        StoreCond("sc_w", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;
	flags[IsStoreConditional] = true;
	memAccessFlags = memAccessFlags | Request::LLSC;;
        if (AQ)
            memAccessFlags = memAccessFlags | Request::ACQUIRE;
        if (RL)
            memAccessFlags = memAccessFlags | Request::RELEASE;
    }

// AtomicMemOp::amoadd_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_sw + Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amoadd_w::Amoadd_w(ExtMachInst machInst)
            : AtomicMemOp("amoadd_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoadd_wLoad(machInst, this),
            new Amoadd_wStore(machInst, this)};
    }

    Amoadd_w::Amoadd_wLoad::Amoadd_wLoad(
        ExtMachInst machInst, Amoadd_w *_p)
            : AtomicMemOpMicro("amoadd_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoadd_w::Amoadd_wStore::Amoadd_wStore(
        ExtMachInst machInst, Amoadd_w *_p)
            : AtomicMemOpMicro("amoadd_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amoswap_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amoswap_w::Amoswap_w(ExtMachInst machInst)
            : AtomicMemOp("amoswap_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoswap_wLoad(machInst, this),
            new Amoswap_wStore(machInst, this)};
    }

    Amoswap_w::Amoswap_wLoad::Amoswap_wLoad(
        ExtMachInst machInst, Amoswap_w *_p)
            : AtomicMemOpMicro("amoswap_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoswap_w::Amoswap_wStore::Amoswap_wStore(
        ExtMachInst machInst, Amoswap_w *_p)
            : AtomicMemOpMicro("amoswap_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amoxor_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw^Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amoxor_w::Amoxor_w(ExtMachInst machInst)
            : AtomicMemOp("amoxor_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoxor_wLoad(machInst, this),
            new Amoxor_wStore(machInst, this)};
    }

    Amoxor_w::Amoxor_wLoad::Amoxor_wLoad(
        ExtMachInst machInst, Amoxor_w *_p)
            : AtomicMemOpMicro("amoxor_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoxor_w::Amoxor_wStore::Amoxor_wStore(
        ExtMachInst machInst, Amoxor_w *_p)
            : AtomicMemOpMicro("amoxor_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amoor_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw | Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amoor_w::Amoor_w(ExtMachInst machInst)
            : AtomicMemOp("amoor_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoor_wLoad(machInst, this),
            new Amoor_wStore(machInst, this)};
    }

    Amoor_w::Amoor_wLoad::Amoor_wLoad(
        ExtMachInst machInst, Amoor_w *_p)
            : AtomicMemOpMicro("amoor_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoor_w::Amoor_wStore::Amoor_wStore(
        ExtMachInst machInst, Amoor_w *_p)
            : AtomicMemOpMicro("amoor_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amoand_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw&Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amoand_w::Amoand_w(ExtMachInst machInst)
            : AtomicMemOp("amoand_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoand_wLoad(machInst, this),
            new Amoand_wStore(machInst, this)};
    }

    Amoand_w::Amoand_wLoad::Amoand_wLoad(
        ExtMachInst machInst, Amoand_w *_p)
            : AtomicMemOpMicro("amoand_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoand_w::Amoand_wStore::Amoand_wStore(
        ExtMachInst machInst, Amoand_w *_p)
            : AtomicMemOpMicro("amoand_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amomin_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = min<int32_t>(Rs2_sw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amomin_w::Amomin_w(ExtMachInst machInst)
            : AtomicMemOp("amomin_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amomin_wLoad(machInst, this),
            new Amomin_wStore(machInst, this)};
    }

    Amomin_w::Amomin_wLoad::Amomin_wLoad(
        ExtMachInst machInst, Amomin_w *_p)
            : AtomicMemOpMicro("amomin_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amomin_w::Amomin_wStore::Amomin_wStore(
        ExtMachInst machInst, Amomin_w *_p)
            : AtomicMemOpMicro("amomin_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amomax_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = max<int32_t>(Rs2_sw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amomax_w::Amomax_w(ExtMachInst machInst)
            : AtomicMemOp("amomax_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amomax_wLoad(machInst, this),
            new Amomax_wStore(machInst, this)};
    }

    Amomax_w::Amomax_wLoad::Amomax_wLoad(
        ExtMachInst machInst, Amomax_w *_p)
            : AtomicMemOpMicro("amomax_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amomax_w::Amomax_wStore::Amomax_wStore(
        ExtMachInst machInst, Amomax_w *_p)
            : AtomicMemOpMicro("amomax_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amominu_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = min<uint32_t>(Rs2_uw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amominu_w::Amominu_w(ExtMachInst machInst)
            : AtomicMemOp("amominu_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amominu_wLoad(machInst, this),
            new Amominu_wStore(machInst, this)};
    }

    Amominu_w::Amominu_wLoad::Amominu_wLoad(
        ExtMachInst machInst, Amominu_w *_p)
            : AtomicMemOpMicro("amominu_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amominu_w::Amominu_wStore::Amominu_wStore(
        ExtMachInst machInst, Amominu_w *_p)
            : AtomicMemOpMicro("amominu_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amomaxu_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = max<uint32_t>(Rs2_uw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amomaxu_w::Amomaxu_w(ExtMachInst machInst)
            : AtomicMemOp("amomaxu_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amomaxu_wLoad(machInst, this),
            new Amomaxu_wStore(machInst, this)};
    }

    Amomaxu_w::Amomaxu_wLoad::Amomaxu_wLoad(
        ExtMachInst machInst, Amomaxu_w *_p)
            : AtomicMemOpMicro("amomaxu_w[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amomaxu_w::Amomaxu_wStore::Amomaxu_wStore(
        ExtMachInst machInst, Amomaxu_w *_p)
            : AtomicMemOpMicro("amomaxu_w[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// Unknown::unknown(([], {}))

// LoadReserved::lr_d((['\n                    Rd_sd = Mem_sd;\n                '], {'mem_flags': 'LLSC'}))

    Lr_d::Lr_d(ExtMachInst machInst):
        LoadReserved("lr_d", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;
	memAccessFlags = memAccessFlags | Request::LLSC;;
        if (AQ)
            memAccessFlags = memAccessFlags | Request::ACQUIRE;
        if (RL)
            memAccessFlags = memAccessFlags | Request::RELEASE;
    }

// StoreCond::sc_d((['\n                    Mem = Rs2;\n                ', '\n                    Rd = result;\n                '], {'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'}))

    Sc_d::Sc_d(ExtMachInst machInst):
        StoreCond("sc_d", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;
	flags[IsStoreConditional] = true;
	memAccessFlags = memAccessFlags | Request::LLSC;;
        if (AQ)
            memAccessFlags = memAccessFlags | Request::ACQUIRE;
        if (RL)
            memAccessFlags = memAccessFlags | Request::RELEASE;
    }

// AtomicMemOp::amoadd_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = Rs2_sd + Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amoadd_d::Amoadd_d(ExtMachInst machInst)
            : AtomicMemOp("amoadd_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoadd_dLoad(machInst, this),
            new Amoadd_dStore(machInst, this)};
    }

    Amoadd_d::Amoadd_dLoad::Amoadd_dLoad(
        ExtMachInst machInst, Amoadd_d *_p)
            : AtomicMemOpMicro("amoadd_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoadd_d::Amoadd_dStore::Amoadd_dStore(
        ExtMachInst machInst, Amoadd_d *_p)
            : AtomicMemOpMicro("amoadd_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amoswap_d(['Rt = Mem;', '\n                        Mem = Rs2;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Amoswap_d::Amoswap_d(ExtMachInst machInst)
            : AtomicMemOp("amoswap_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoswap_dLoad(machInst, this),
            new Amoswap_dStore(machInst, this)};
    }

    Amoswap_d::Amoswap_dLoad::Amoswap_dLoad(
        ExtMachInst machInst, Amoswap_d *_p)
            : AtomicMemOpMicro("amoswap_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoswap_d::Amoswap_dStore::Amoswap_dStore(
        ExtMachInst machInst, Amoswap_d *_p)
            : AtomicMemOpMicro("amoswap_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amoxor_d(['Rt = Mem;', '\n                        Mem = Rs2^Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Amoxor_d::Amoxor_d(ExtMachInst machInst)
            : AtomicMemOp("amoxor_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoxor_dLoad(machInst, this),
            new Amoxor_dStore(machInst, this)};
    }

    Amoxor_d::Amoxor_dLoad::Amoxor_dLoad(
        ExtMachInst machInst, Amoxor_d *_p)
            : AtomicMemOpMicro("amoxor_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoxor_d::Amoxor_dStore::Amoxor_dStore(
        ExtMachInst machInst, Amoxor_d *_p)
            : AtomicMemOpMicro("amoxor_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amoor_d(['Rt = Mem;', '\n                        Mem = Rs2 | Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Amoor_d::Amoor_d(ExtMachInst machInst)
            : AtomicMemOp("amoor_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoor_dLoad(machInst, this),
            new Amoor_dStore(machInst, this)};
    }

    Amoor_d::Amoor_dLoad::Amoor_dLoad(
        ExtMachInst machInst, Amoor_d *_p)
            : AtomicMemOpMicro("amoor_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoor_d::Amoor_dStore::Amoor_dStore(
        ExtMachInst machInst, Amoor_d *_p)
            : AtomicMemOpMicro("amoor_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amoand_d(['Rt = Mem;', '\n                        Mem = Rs2&Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Amoand_d::Amoand_d(ExtMachInst machInst)
            : AtomicMemOp("amoand_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amoand_dLoad(machInst, this),
            new Amoand_dStore(machInst, this)};
    }

    Amoand_d::Amoand_dLoad::Amoand_dLoad(
        ExtMachInst machInst, Amoand_d *_p)
            : AtomicMemOpMicro("amoand_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amoand_d::Amoand_dStore::Amoand_dStore(
        ExtMachInst machInst, Amoand_d *_p)
            : AtomicMemOpMicro("amoand_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amomin_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = min(Rs2_sd, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amomin_d::Amomin_d(ExtMachInst machInst)
            : AtomicMemOp("amomin_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amomin_dLoad(machInst, this),
            new Amomin_dStore(machInst, this)};
    }

    Amomin_d::Amomin_dLoad::Amomin_dLoad(
        ExtMachInst machInst, Amomin_d *_p)
            : AtomicMemOpMicro("amomin_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amomin_d::Amomin_dStore::Amomin_dStore(
        ExtMachInst machInst, Amomin_d *_p)
            : AtomicMemOpMicro("amomin_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amomax_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = max(Rs2_sd, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Amomax_d::Amomax_d(ExtMachInst machInst)
            : AtomicMemOp("amomax_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amomax_dLoad(machInst, this),
            new Amomax_dStore(machInst, this)};
    }

    Amomax_d::Amomax_dLoad::Amomax_dLoad(
        ExtMachInst machInst, Amomax_d *_p)
            : AtomicMemOpMicro("amomax_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amomax_d::Amomax_dStore::Amomax_dStore(
        ExtMachInst machInst, Amomax_d *_p)
            : AtomicMemOpMicro("amomax_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amominu_d(['Rt = Mem;', '\n                        Mem = min(Rs2, Rt);\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Amominu_d::Amominu_d(ExtMachInst machInst)
            : AtomicMemOp("amominu_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amominu_dLoad(machInst, this),
            new Amominu_dStore(machInst, this)};
    }

    Amominu_d::Amominu_dLoad::Amominu_dLoad(
        ExtMachInst machInst, Amominu_d *_p)
            : AtomicMemOpMicro("amominu_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amominu_d::Amominu_dStore::Amominu_dStore(
        ExtMachInst machInst, Amominu_d *_p)
            : AtomicMemOpMicro("amominu_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// AtomicMemOp::amomaxu_d(['Rt = Mem;', '\n                        Mem = max(Rs2, Rt);\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Amomaxu_d::Amomaxu_d(ExtMachInst machInst)
            : AtomicMemOp("amomaxu_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;;
        microops = {new Amomaxu_dLoad(machInst, this),
            new Amomaxu_dStore(machInst, this)};
    }

    Amomaxu_d::Amomaxu_dLoad::Amomaxu_dLoad(
        ExtMachInst machInst, Amomaxu_d *_p)
            : AtomicMemOpMicro("amomaxu_d[l]", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, AMOTempReg);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
        flags[IsFirstMicroop] = true;
        flags[IsDelayedCommit] = true;
        if (AQ)
            memAccessFlags = Request::ACQUIRE;
    }

    Amomaxu_d::Amomaxu_dStore::Amomaxu_dStore(
        ExtMachInst machInst, Amomaxu_d *_p)
            : AtomicMemOpMicro("amomaxu_d[s]", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, AMOTempReg);
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
        flags[IsLastMicroop] = true;
        flags[IsNonSpeculative] = true;
        if (RL)
            memAccessFlags = Request::RELEASE;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// ROp::add(['\n                        Rd = Rs1_sd + Rs2_sd;\n                    '],{})

    Add::Add(MachInst machInst)
        : RegOp("add", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::mul(['\n                        Rd = Rs1_sd*Rs2_sd;\n                    ', 'IntMultOp'],{})

    Mul::Mul(MachInst machInst)
        : RegOp("mul", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::sub(['\n                        Rd = Rs1_sd - Rs2_sd;\n                    '],{})

    Sub::Sub(MachInst machInst)
        : RegOp("sub", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::sll(['\n                        Rd = Rs1 << Rs2<5:0>;\n                    '],{})

    Sll::Sll(MachInst machInst)
        : RegOp("sll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::mulh(['\n                        bool negate = (Rs1_sd < 0) != (Rs2_sd < 0);\n\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)abs(Rs2_sd);\n                        uint64_t Rs2_hi = (uint64_t)abs(Rs2_sd) >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs2_lo*Rs1_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2_sd == 0 ? 1 : 0)\n                                    : res;\n                    ', 'IntMultOp'],{})

    Mulh::Mulh(MachInst machInst)
        : RegOp("mulh", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::slt(['\n                        Rd = (Rs1_sd < Rs2_sd) ? 1 : 0;\n                    '],{})

    Slt::Slt(MachInst machInst)
        : RegOp("slt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::mulhsu(['\n                        bool negate = Rs1_sd < 0;\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2 == 0 ? 1 : 0) : res;\n                    ', 'IntMultOp'],{})

    Mulhsu::Mulhsu(MachInst machInst)
        : RegOp("mulhsu", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::sltu(['\n                        Rd = (Rs1 < Rs2) ? 1 : 0;\n                    '],{})

    Sltu::Sltu(MachInst machInst)
        : RegOp("sltu", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::mulhu(['\n                        uint64_t Rs1_lo = (uint32_t)Rs1;\n                        uint64_t Rs1_hi = Rs1 >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;\n                    ', 'IntMultOp'],{})

    Mulhu::Mulhu(MachInst machInst)
        : RegOp("mulhu", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::xor(['\n                        Rd = Rs1 ^ Rs2;\n                    '],{})

    Xor::Xor(MachInst machInst)
        : RegOp("xor", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::div(['\n                        if (Rs2_sd == 0) {\n                            Rd_sd = -1;\n                        } else if (Rs1_sd == numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                        } else {\n                            Rd_sd = Rs1_sd/Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    Div::Div(MachInst machInst)
        : RegOp("div", machInst, IntDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::srl(['\n                        Rd = Rs1 >> Rs2<5:0>;\n                    '],{})

    Srl::Srl(MachInst machInst)
        : RegOp("srl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::divu(['\n                        if (Rs2 == 0) {\n                            Rd = numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd = Rs1/Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    Divu::Divu(MachInst machInst)
        : RegOp("divu", machInst, IntDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::sra(['\n                        Rd_sd = Rs1_sd >> Rs2<5:0>;\n                    '],{})

    Sra::Sra(MachInst machInst)
        : RegOp("sra", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::or(['\n                        Rd = Rs1 | Rs2;\n                    '],{})

    Or::Or(MachInst machInst)
        : RegOp("or", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::rem(['\n                        if (Rs2_sd == 0) {\n                            Rd = Rs1_sd;\n                        } else if (Rs1_sd == numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd = 0;\n                        } else {\n                            Rd = Rs1_sd%Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    Rem::Rem(MachInst machInst)
        : RegOp("rem", machInst, IntDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::and(['\n                        Rd = Rs1 & Rs2;\n                    '],{})

    And::And(MachInst machInst)
        : RegOp("and", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::remu(['\n                        if (Rs2 == 0) {\n                            Rd = Rs1;\n                        } else {\n                            Rd = Rs1%Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    Remu::Remu(MachInst machInst)
        : RegOp("remu", machInst, IntDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// UOp::lui((['\n            Rd = (uint64_t)imm;\n        '], {}))

    Lui::Lui(MachInst machInst)
        : ImmOp<int64_t>("lui", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        imm = sext<20>(IMM20) << 12;;
    }

// ROp::addw(['\n                        Rd_sd = Rs1_sw + Rs2_sw;\n                    '],{})

    Addw::Addw(MachInst machInst)
        : RegOp("addw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::mulw(['\n                        Rd_sd = (int32_t)(Rs1_sw*Rs2_sw);\n                    ', 'IntMultOp'],{})

    Mulw::Mulw(MachInst machInst)
        : RegOp("mulw", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::subw(['\n                        Rd_sd = Rs1_sw - Rs2_sw;\n                    '],{})

    Subw::Subw(MachInst machInst)
        : RegOp("subw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::sllw(['\n                    Rd_sd = Rs1_sw << Rs2<4:0>;\n                '],{})

    Sllw::Sllw(MachInst machInst)
        : RegOp("sllw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::divw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = -1;\n                    } else if (Rs1_sw == numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = numeric_limits<int32_t>::min();\n                    } else {\n                        Rd_sd = Rs1_sw/Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    Divw::Divw(MachInst machInst)
        : RegOp("divw", machInst, IntDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::srlw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> Rs2<4:0>);\n                    '],{})

    Srlw::Srlw(MachInst machInst)
        : RegOp("srlw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::divuw(['\n                        if (Rs2_uw == 0) {\n                            Rd_sd = numeric_limits<IntReg>::max();\n                        } else {\n                            Rd_sd = (int32_t)(Rs1_uw/Rs2_uw);\n                        }\n                    ', 'IntDivOp'],{})

    Divuw::Divuw(MachInst machInst)
        : RegOp("divuw", machInst, IntDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::sraw(['\n                        Rd_sd = Rs1_sw >> Rs2<4:0>;\n                    '],{})

    Sraw::Sraw(MachInst machInst)
        : RegOp("sraw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::remw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = Rs1_sw;\n                    } else if (Rs1_sw == numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = 0;\n                    } else {\n                        Rd_sd = Rs1_sw%Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    Remw::Remw(MachInst machInst)
        : RegOp("remw", machInst, IntDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// ROp::remuw(['\n                    if (Rs2_uw == 0) {\n                        Rd_sd = (int32_t)Rs1_uw;\n                    } else {\n                        Rd_sd = (int32_t)(Rs1_uw%Rs2_uw);\n                    }\n                ', 'IntDivOp'],{})

    Remuw::Remuw(MachInst machInst)
        : RegOp("remuw", machInst, IntDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = fs3;\n                        }\n                    } else {\n                        fd = fs1*fs2 + fs3;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    Fmadd_s::Fmadd_s(MachInst machInst)
        : RegOp("fmadd_s", machInst, FloatMultAccOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS3);
	flags[IsFloating] = true;;
    }

// FPROp::fmadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else {\n                            Fd = Fs3;\n                        }\n                    } else {\n                        Fd = Fs1*Fs2 + Fs3;\n                    }\n                ', 'FloatMultAccOp'],{})

    Fmadd_d::Fmadd_d(MachInst machInst)
        : RegOp("fmadd_d", machInst, FloatMultAccOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS3);
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = -fs3;\n                        }\n                    } else {\n                        fd = fs1*fs2 - fs3;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    Fmsub_s::Fmsub_s(MachInst machInst)
        : RegOp("fmsub_s", machInst, FloatMultAccOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS3);
	flags[IsFloating] = true;;
    }

// FPROp::fmsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else {\n                            Fd = -Fs3;\n                        }\n                    } else {\n                        Fd = Fs1*Fs2 - Fs3;\n                    }\n                ', 'FloatMultAccOp'],{})

    Fmsub_d::Fmsub_d(MachInst machInst)
        : RegOp("fmsub_d", machInst, FloatMultAccOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS3);
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fnmsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = fs3;\n                        }\n                    } else {\n                        fd = -(fs1*fs2 - fs3);\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    Fnmsub_s::Fnmsub_s(MachInst machInst)
        : RegOp("fnmsub_s", machInst, FloatMultAccOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS3);
	flags[IsFloating] = true;;
    }

// FPROp::fnmsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2)\n                            || std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else {\n                            Fd = Fs3;\n                        }\n                    } else {\n                        Fd = -(Fs1*Fs2 - Fs3);\n                    }\n                ', 'FloatMultAccOp'],{})

    Fnmsub_d::Fnmsub_d(MachInst machInst)
        : RegOp("fnmsub_d", machInst, FloatMultAccOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS3);
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fnmadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = -fs3;\n                        }\n                    } else {\n                        fd = -(fs1*fs2 + fs3);\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    Fnmadd_s::Fnmadd_s(MachInst machInst)
        : RegOp("fnmadd_s", machInst, FloatMultAccOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS3);
	flags[IsFloating] = true;;
    }

// FPROp::fnmadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else {\n                            Fd = -Fs3;\n                        }\n                    } else {\n                        Fd = -(Fs1*Fs2 + Fs3);\n                    }\n                ', 'FloatMultAccOp'],{})

    Fnmadd_d::Fnmadd_d(MachInst machInst)
        : RegOp("fnmadd_d", machInst, FloatMultAccOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS3);
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1 + fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatAddOp'],{})

    Fadd_s::Fadd_s(MachInst machInst)
        : RegOp("fadd_s", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1 + Fs2;\n                    }\n                ', 'FloatAddOp'],{})

    Fadd_d::Fadd_d(MachInst machInst)
        : RegOp("fadd_d", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1 - fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatAddOp'],{})

    Fsub_s::Fsub_s(MachInst machInst)
        : RegOp("fsub_s", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1 - Fs2;\n                    }\n                ', 'FloatAddOp'],{})

    Fsub_d::Fsub_d(MachInst machInst)
        : RegOp("fsub_d", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fmul_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1*fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultOp'],{})

    Fmul_s::Fmul_s(MachInst machInst)
        : RegOp("fmul_s", machInst, FloatMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fmul_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1*Fs2;\n                    }\n                ', 'FloatMultOp'],{})

    Fmul_d::Fmul_d(MachInst machInst)
        : RegOp("fmul_d", machInst, FloatMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fdiv_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1/fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatDivOp'],{})

    Fdiv_s::Fdiv_s(MachInst machInst)
        : RegOp("fdiv_s", machInst, FloatDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fdiv_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1/Fs2;\n                    }\n                ', 'FloatDivOp'],{})

    Fdiv_d::Fdiv_d(MachInst machInst)
        : RegOp("fdiv_d", machInst, FloatDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fsgnj_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = copysign(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    Fsgnj_s::Fsgnj_s(MachInst machInst)
        : RegOp("fsgnj_s", machInst, FloatMiscOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fsgnjn_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = copysign(fs1, -fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    Fsgnjn_s::Fsgnjn_s(MachInst machInst)
        : RegOp("fsgnjn_s", machInst, FloatMiscOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fsgnjx_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = fs1*(signbit(fs2) ? -1.0 : 1.0);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    Fsgnjx_s::Fsgnjx_s(MachInst machInst)
        : RegOp("fsgnjx_s", machInst, FloatMiscOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fsgnj_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = copysign(Fs1, Fs2);\n                        }\n                    ', 'FloatMiscOp'],{})

    Fsgnj_d::Fsgnj_d(MachInst machInst)
        : RegOp("fsgnj_d", machInst, FloatMiscOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fsgnjn_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = copysign(Fs1, -Fs2);\n                        }\n                    ', 'FloatMiscOp'],{})

    Fsgnjn_d::Fsgnjn_d(MachInst machInst)
        : RegOp("fsgnjn_d", machInst, FloatMiscOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fsgnjx_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = Fs1*(signbit(Fs2) ? -1.0 : 1.0);\n                        }\n                    ', 'FloatMiscOp'],{})

    Fsgnjx_d::Fsgnjx_d(MachInst machInst)
        : RegOp("fsgnjx_d", machInst, FloatMiscOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmin_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs2)) {\n                            fd = fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(fs1)) {\n                            fd = fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            fd = fmin(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatCmpOp'],{})

    Fmin_s::Fmin_s(MachInst machInst)
        : RegOp("fmin_s", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fmax_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs2)) {\n                            fd = fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(fs1)) {\n                            fd = fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            fd = fmax(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatCmpOp'],{})

    Fmax_s::Fmax_s(MachInst machInst)
        : RegOp("fmax_s", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmin_d(['\n                        if (issignalingnan(Fs2)) {\n                            Fd = Fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(Fs1)) {\n                            Fd = Fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Fd = fmin(Fs1, Fs2);\n                        }\n                    ', 'FloatCmpOp'],{})

    Fmin_d::Fmin_d(MachInst machInst)
        : RegOp("fmin_d", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// FPROp::fmax_d(['\n                        if (issignalingnan(Fs2)) {\n                            Fd = Fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(Fs1)) {\n                            Fd = Fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Fd = fmax(Fs1, Fs2);\n                        }\n                    ', 'FloatCmpOp'],{})

    Fmax_d::Fmax_d(MachInst machInst)
        : RegOp("fmax_d", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_d(['\n                    if (CONV_SGN != 1) {\n                        fault = make_shared<IllegalInstFault>("CONV_SGN != 1",\n                                                              machInst);\n                    }\n                    float fd;\n                    if (issignalingnan(Fs1)) {\n                        fd = numeric_limits<float>::quiet_NaN();\n                        FFLAGS |= FloatInvalid;\n                    } else {\n                        fd = (float)Fs1;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatCvtOp'],{})

    Fcvt_s_d::Fcvt_s_d(MachInst machInst)
        : RegOp("fcvt_s_d", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;;
    }

// FPROp::fcvt_d_s(['\n                    if (CONV_SGN != 0) {\n                        fault = make_shared<IllegalInstFault>("CONV_SGN != 0",\n                                                              machInst);\n                    }\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                    if (issignalingnan(fs1)) {\n                        Fd = numeric_limits<double>::quiet_NaN();\n                        FFLAGS |= FloatInvalid;\n                    } else {\n                        Fd = (double)fs1;\n                    }\n                ', 'FloatCvtOp'],{})

    Fcvt_d_s::Fcvt_d_s(MachInst machInst)
        : RegOp("fcvt_d_s", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;;
    }

// FPROp::fsqrt_s(['\n                    if (RS2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fd;\n\n                    if (issignalingnan(Fs1_sf)) {\n                        FFLAGS |= FloatInvalid;\n                    }\n                    fd = sqrt(fs1);\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatSqrtOp'],{})

    Fsqrt_s::Fsqrt_s(MachInst machInst)
        : RegOp("fsqrt_s", machInst, FloatSqrtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;;
    }

// FPROp::fsqrt_d(['\n                    if (RS2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    Fd = sqrt(Fs1);\n                ', 'FloatSqrtOp'],{})

    Fsqrt_d::Fsqrt_d(MachInst machInst)
        : RegOp("fsqrt_d", machInst, FloatSqrtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;;
    }

// FPROp::fle_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (std::isnan(fs1) || std::isnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = fs1 <= fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    Fle_s::Fle_s(MachInst machInst)
        : RegOp("fle_s", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::flt_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (std::isnan(fs1) || std::isnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = fs1 < fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    Flt_s::Flt_s(MachInst machInst)
        : RegOp("flt_s", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::feq_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Rd = fs1 == fs2 ? 1 : 0;\n                    ', 'FloatCmpOp'],{})

    Feq_s::Feq_s(MachInst machInst)
        : RegOp("feq_s", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fle_d(['\n                        if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = Fs1 <= Fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    Fle_d::Fle_d(MachInst machInst)
        : RegOp("fle_d", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::flt_d(['\n                        if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = Fs1 < Fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    Flt_d::Flt_d(MachInst machInst)
        : RegOp("flt_d", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::feq_d(['\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Rd = Fs1 == Fs2 ? 1 : 0;\n                    ', 'FloatCmpOp'],{})

    Feq_d::Feq_d(MachInst machInst)
        : RegOp("feq_d", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS2);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 >= numeric_limits<int32_t>::max()) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 <= numeric_limits<int32_t>::min()) {\n                            Rd_sd = numeric_limits<int32_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int32_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fcvt_w_s::Fcvt_w_s(MachInst machInst)
        : RegOp("fcvt_w_s", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_wu_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < 0.0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<uint32_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint32_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fcvt_wu_s::Fcvt_wu_s(MachInst machInst)
        : RegOp("fcvt_wu_s", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_l_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<int64_t>::max()) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < numeric_limits<int64_t>::min()) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int64_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fcvt_l_s::Fcvt_l_s(MachInst machInst)
        : RegOp("fcvt_l_s", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_lu_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < 0.0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<uint64_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint64_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fcvt_lu_s::Fcvt_lu_s(MachInst machInst)
        : RegOp("fcvt_lu_s", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<int32_t>::max()) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < numeric_limits<int32_t>::min()) {\n                            Rd_sd = numeric_limits<int32_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int32_t)Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fcvt_w_d::Fcvt_w_d(MachInst machInst)
        : RegOp("fcvt_w_d", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_wu_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < 0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<uint32_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint32_t)Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fcvt_wu_d::Fcvt_wu_d(MachInst machInst)
        : RegOp("fcvt_wu_d", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_l_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<int64_t>::max()) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < numeric_limits<int64_t>::min()) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fcvt_l_d::Fcvt_l_d(MachInst machInst)
        : RegOp("fcvt_l_d", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_lu_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < 0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<uint64_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fcvt_lu_d::Fcvt_lu_d(MachInst machInst)
        : RegOp("fcvt_lu_d", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_w(['\n                        float temp = (float)Rs1_sw;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    Fcvt_s_w::Fcvt_s_w(MachInst machInst)
        : RegOp("fcvt_s_w", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_s_wu(['\n                        float temp = (float)Rs1_uw;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    Fcvt_s_wu::Fcvt_s_wu(MachInst machInst)
        : RegOp("fcvt_s_wu", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_s_l(['\n                        float temp = (float)Rs1_sd;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    Fcvt_s_l::Fcvt_s_l(MachInst machInst)
        : RegOp("fcvt_s_l", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_s_lu(['\n                        float temp = (float)Rs1;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    Fcvt_s_lu::Fcvt_s_lu(MachInst machInst)
        : RegOp("fcvt_s_lu", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_d_w(['\n                        Fd = (double)Rs1_sw;\n                    ', 'FloatCvtOp'],{})

    Fcvt_d_w::Fcvt_d_w(MachInst machInst)
        : RegOp("fcvt_d_w", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_d_wu(['\n                        Fd = (double)Rs1_uw;\n                    ', 'FloatCvtOp'],{})

    Fcvt_d_wu::Fcvt_d_wu(MachInst machInst)
        : RegOp("fcvt_d_wu", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_d_l(['\n                        Fd = (double)Rs1_sd;\n                    ', 'FloatCvtOp'],{})

    Fcvt_d_l::Fcvt_d_l(MachInst machInst)
        : RegOp("fcvt_d_l", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_d_lu(['\n                        Fd = (double)Rs1;\n                    ', 'FloatCvtOp'],{})

    Fcvt_d_lu::Fcvt_d_lu(MachInst machInst)
        : RegOp("fcvt_d_lu", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_x_s(['\n                        Rd = (uint32_t)Fs1_bits;\n                        if ((Rd&0x80000000) != 0) {\n                            Rd |= (0xFFFFFFFFULL << 32);\n                        }\n                    ', 'FloatCvtOp'],{})

    Fmv_x_s::Fmv_x_s(MachInst machInst)
        : RegOp("fmv_x_s", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RD);
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fclass_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        switch (fpclassify(fs1)) {\n                          case FP_INFINITE:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 0;\n                            } else {\n                                Rd = 1 << 7;\n                            }\n                            break;\n                          case FP_NAN:\n                            if (issignalingnan(fs1)) {\n                                Rd = 1 << 8;\n                            } else {\n                                Rd = 1 << 9;\n                            }\n                            break;\n                          case FP_ZERO:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 3;\n                            } else {\n                                Rd = 1 << 4;\n                            }\n                            break;\n                          case FP_SUBNORMAL:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 2;\n                            } else {\n                                Rd = 1 << 5;\n                            }\n                            break;\n                          case FP_NORMAL:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 1;\n                            } else {\n                                Rd = 1 << 6;\n                            }\n                            break;\n                          default:\n                            panic("Unknown classification for operand.");\n                            break;\n                        }\n                    ', 'FloatMiscOp'],{})

    Fclass_s::Fclass_s(MachInst machInst)
        : RegOp("fclass_s", machInst, FloatMiscOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_x_d(['\n                        Rd = Fs1_bits;\n                    ', 'FloatCvtOp'],{})

    Fmv_x_d::Fmv_x_d(MachInst machInst)
        : RegOp("fmv_x_d", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fclass_d(['\n                        switch (fpclassify(Fs1)) {\n                          case FP_INFINITE:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 0;\n                            } else {\n                                Rd = 1 << 7;\n                            }\n                            break;\n                          case FP_NAN:\n                            if (issignalingnan(Fs1)) {\n                                Rd = 1 << 8;\n                            } else {\n                                Rd = 1 << 9;\n                            }\n                            break;\n                          case FP_ZERO:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 3;\n                            } else {\n                                Rd = 1 << 4;\n                            }\n                            break;\n                          case FP_SUBNORMAL:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 2;\n                            } else {\n                                Rd = 1 << 5;\n                            }\n                            break;\n                          case FP_NORMAL:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 1;\n                            } else {\n                                Rd = 1 << 6;\n                            }\n                            break;\n                          default:\n                            panic("Unknown classification for operand.");\n                            break;\n                        }\n                    ', 'FloatMiscOp'],{})

    Fclass_d::Fclass_d(MachInst machInst)
        : RegOp("fclass_d", machInst, FloatMiscOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(FloatRegClass, FS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_s_x(['\n                    Fd_bits = (uint64_t)Rs1_uw;\n                ', 'FloatCvtOp'],{})

    Fmv_s_x::Fmv_s_x(MachInst machInst)
        : RegOp("fmv_s_x", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fmv_d_x(['\n                    Fd_bits = Rs1;\n                ', 'FloatCvtOp'],{})

    Fmv_d_x::Fmv_d_x(MachInst machInst)
        : RegOp("fmv_d_x", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(FloatRegClass, FD);
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// BOp::beq(['\n                    if (Rs1 == Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Beq::Beq(MachInst machInst)
        : ImmOp<int64_t>("beq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::bne(['\n                    if (Rs1 != Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Bne::Bne(MachInst machInst)
        : ImmOp<int64_t>("bne", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::blt(['\n                    if (Rs1_sd < Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Blt::Blt(MachInst machInst)
        : ImmOp<int64_t>("blt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::bge(['\n                    if (Rs1_sd >= Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Bge::Bge(MachInst machInst)
        : ImmOp<int64_t>("bge", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::bltu(['\n                    if (Rs1 < Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Bltu::Bltu(MachInst machInst)
        : ImmOp<int64_t>("bltu", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::bgeu(['\n                    if (Rs1 >= Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Bgeu::Bgeu(MachInst machInst)
        : ImmOp<int64_t>("bgeu", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS2);
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// Unknown::unknown(([], {}))

// Jump::jalr((['\n                Rd = NPC;\n                NPC = (imm + Rs1) & (~0x1);\n            ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Jalr::Jalr(MachInst machInst)
        : ImmOp<int64_t>("jalr", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
        imm = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// JOp::jal((['\n            Rd = NPC;\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl', 'IsCall'], {}))

    Jal::Jal(MachInst machInst)
        : ImmOp<int64_t>("jal", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
        
                imm = UJIMMBITS10TO1 << 1   |
                      UJIMMBIT11 << 11      |
                      UJIMMBITS19TO12 << 12 |
                      IMMSIGN << 20;
                imm = sext<21>(imm);
               ;
    }

// SystemOp::ecall(['\n                        fault = make_shared<SyscallFault>(\n                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall', 'No_OpClass'],{})

    Ecall::Ecall(MachInst machInst)
        : SystemOp("ecall", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;
	flags[IsSyscall] = true;;
    }

// SystemOp::ebreak(['\n                        fault = make_shared<BreakpointFault>(xc->pcState());\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Ebreak::Ebreak(MachInst machInst)
        : SystemOp("ebreak", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// SystemOp::uret(['\n                        STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                        status.uie = status.upie;\n                        status.upie = 1;\n                        xc->setMiscReg(MISCREG_STATUS, status);\n                        NPC = xc->readMiscReg(MISCREG_UEPC);\n                    ', 'IsReturn'],{})

    Uret::Uret(MachInst machInst)
        : SystemOp("uret", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsReturn] = true;;
    }

// SystemOp::sret(['\n                        if (xc->readMiscReg(MISCREG_PRV) == PRV_U) {\n                            fault = make_shared<IllegalInstFault>(\n                                        "sret in user mode", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.spp);\n                            status.sie = status.spie;\n                            status.spie = 1;\n                            status.spp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_SEPC);\n                        }\n                    ', 'IsReturn'],{})

    Sret::Sret(MachInst machInst)
        : SystemOp("sret", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsReturn] = true;;
    }

// SystemOp::mret(['\n                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {\n                            fault = make_shared<IllegalInstFault>(\n                                        "mret at lower privilege", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.mpp);\n                            status.mie = status.mpie;\n                            status.mpie = 1;\n                            status.mpp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_MEPC);\n                        }\n                    ', 'IsReturn'],{})

    Mret::Mret(MachInst machInst)
        : SystemOp("mret", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsReturn] = true;;
    }

// Unknown::unknown(([], {}))

// CSROp::csrrw(['\n                    Rd = data;\n                    data = Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrw::Csrrw(MachInst machInst)
        : CSROp("csrrw", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;;
    }

// CSROp::csrrs(['\n                    Rd = data;\n                    data |= Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrs::Csrrs(MachInst machInst)
        : CSROp("csrrs", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;;
    }

// CSROp::csrrc(['\n                    Rd = data;\n                    data &= ~Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrc::Csrrc(MachInst machInst)
        : CSROp("csrrc", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = RegId(IntRegClass, RS1);
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;;
    }

// CSROp::csrrwi(['\n                    Rd = data;\n                    data = uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrwi::Csrrwi(MachInst machInst)
        : CSROp("csrrwi", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;;
    }

// CSROp::csrrsi(['\n                    Rd = data;\n                    data |= uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrsi::Csrrsi(MachInst machInst)
        : CSROp("csrrsi", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;;
    }

// CSROp::csrrci(['\n                    Rd = data;\n                    data &= ~uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrci::Csrrci(MachInst machInst)
        : CSROp("csrrci", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = RegId(IntRegClass, RD);
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

#endif
