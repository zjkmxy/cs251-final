// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   riscv/isa/main.isa

#if !defined(__SPLIT) || (__SPLIT == 1)

// CIOp::c_addi4spn((['\n            imm = CIMM8<1:1> << 2 |\n                  CIMM8<0:0> << 3 |\n                  CIMM8<7:6> << 4 |\n                  CIMM8<5:2> << 6;\n        ', '\n            if (machInst == 0)\n                fault = make_shared<IllegalInstFault>("zero instruction",\n                                                      machInst);\n            Rp2 = sp + imm;\n        ', 'uint64_t'], {}))

    Fault
    C_addi4spn::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t sp = 0;
uint64_t Rp2 = 0;
;
        sp = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
            if (machInst == 0)
                fault = make_shared<IllegalInstFault>("zero instruction",
                                                      machInst);
            Rp2 = sp + imm;
        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_addi4spn::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CompressedLoad::c_fld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Fp2_bits = Mem;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_fld::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Fp2_bits = 0;
uint64_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                Fp2_bits = Mem;
            ;
        }

        if (fault == NoFault) {
            
        {
            uint64_t final_val = Fp2_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    C_fld::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    C_fld::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fp2_bits = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                Fp2_bits = Mem;
            ;
        }

        if (fault == NoFault) {
            
        {
            uint64_t final_val = Fp2_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// CompressedLoad::c_lw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Rp2_sd = Mem_sw;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_lw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
int64_t Rp2 = 0;
int32_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                Rp2 = Mem;
            ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    C_lw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
int32_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    C_lw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rp2 = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                Rp2 = Mem;
            ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// CompressedLoad::c_ld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Rp2_sd = Mem_sd;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_ld::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
int64_t Rp2 = 0;
int64_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                Rp2 = Mem;
            ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    C_ld::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
int64_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    C_ld::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rp2 = 0;
int64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                Rp2 = Mem;
            ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// CompressedStore::c_fsd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Mem = Fp2_bits;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_fsd::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Fp2_bits = 0;
uint64_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Fp2_bits = xc->readFloatRegOperandBits(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Fp2_bits;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_fsd::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Fp2_bits = 0;
uint64_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Fp2_bits = xc->readFloatRegOperandBits(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Fp2_bits;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_fsd::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// CompressedStore::c_sw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Mem_uw = Rp2_uw;\n            '],{'ea_code': '\n                EA = Rp1 + offset;\n            '})

    Fault
    C_sw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint32_t Rp2 = 0;
uint32_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Rp2;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_sw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint32_t Rp2 = 0;
uint32_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Rp2;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_sw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// CompressedStore::c_sd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                    Mem_ud = Rp2_ud;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_sd::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
uint64_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            
                    Mem = Rp2;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_sd::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
uint64_t Mem;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        if (fault == NoFault) {
            
                    Mem = Rp2;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_sd::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// CIOp::c_addi(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if ((RC1 == 0) != (imm == 0)) {\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    } else // imm == 0\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                }\n                Rc1_sd = Rc1_sd + imm;\n            '],{})

    Fault
    C_addi::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rc1 = 0;
;
        Rc1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                if ((RC1 == 0) != (imm == 0)) {
                    if (RC1 == 0) {
                        fault = make_shared<IllegalInstFault>("source reg x0",
                                                              machInst);
                    } else // imm == 0
                        fault = make_shared<IllegalInstFault>("immediate = 0",
                                                              machInst);
                }
                Rc1 = Rc1 + imm;
            ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_addi::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_addiw(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = (int32_t)Rc1_sd + imm;\n            '],{})

    Fault
    C_addiw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rc1 = 0;
;
        Rc1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                if (RC1 == 0) {
                    fault = make_shared<IllegalInstFault>("source reg x0",
                                                          machInst);
                }
                Rc1 = (int32_t)Rc1 + imm;
            ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_addiw::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_li(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = imm;\n            '],{})

    Fault
    C_li::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rc1 = 0;
;
        ;
        if (fault == NoFault) {
            
                if (RC1 == 0) {
                    fault = make_shared<IllegalInstFault>("source reg x0",
                                                          machInst);
                }
                Rc1 = imm;
            ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_li::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_addi16sp(['\n                    imm = CIMM5<4:4> << 4 |\n                          CIMM5<0:0> << 5 |\n                          CIMM5<3:3> << 6 |\n                          CIMM5<2:1> << 7;\n                    if (CIMM1 > 0)\n                        imm |= ~((int64_t)0x1FF);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    sp_sd = sp_sd + imm;\n                '],{})

    Fault
    C_addi16sp::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t sp = 0;
;
        sp = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    if (imm == 0) {
                        fault = make_shared<IllegalInstFault>("immediate = 0",
                                                              machInst);
                    }
                    sp = sp + imm;
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = sp;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_addi16sp::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_lui(['\n                    imm = CIMM5 << 12;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1FFFF);\n                ', '\n                    if (RC1 == 0 || RC1 == 2) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rc1_sd = imm;\n                '],{})

    Fault
    C_lui::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rc1 = 0;
;
        ;
        if (fault == NoFault) {
            
                    if (RC1 == 0 || RC1 == 2) {
                        fault = make_shared<IllegalInstFault>("source reg x0",
                                                              machInst);
                    }
                    if (imm == 0) {
                        fault = make_shared<IllegalInstFault>("immediate = 0",
                                                              machInst);
                    }
                    Rc1 = imm;
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_lui::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_srli(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rp1 = Rp1 >> imm;\n                ', 'uint64_t'],{})

    Fault
    C_srli::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    if (imm == 0) {
                        fault = make_shared<IllegalInstFault>("immediate = 0",
                                                              machInst);
                    }
                    Rp1 = Rp1 >> imm;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_srli::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_srai(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rp1_sd = Rp1_sd >> imm;\n                ', 'uint64_t'],{})

    Fault
    C_srai::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rp1 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    if (imm == 0) {
                        fault = make_shared<IllegalInstFault>("immediate = 0",
                                                              machInst);
                    }
                    Rp1 = Rp1 >> imm;
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_srai::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_andi(['\n                    imm = CIMM5;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1F);\n                ', '\n                    Rp1 = Rp1 & imm;\n                ', 'uint64_t'],{})

    Fault
    C_andi::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rp1 = Rp1 & imm;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_andi::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// ROp::c_sub(['\n                            Rp1 = Rp1 - Rp2;\n                        '],{})

    Fault
    C_sub::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                            Rp1 = Rp1 - Rp2;
                        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::c_xor(['\n                            Rp1 = Rp1 ^ Rp2;\n                        '],{})

    Fault
    C_xor::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                            Rp1 = Rp1 ^ Rp2;
                        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::c_or(['\n                            Rp1 = Rp1 | Rp2;\n                        '],{})

    Fault
    C_or::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                            Rp1 = Rp1 | Rp2;
                        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::c_and(['\n                            Rp1 = Rp1 & Rp2;\n                        '],{})

    Fault
    C_and::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                            Rp1 = Rp1 & Rp2;
                        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::c_subw(['\n                            Rp1_sd = (int32_t)Rp1_sd - Rp2_sw;\n                        '],{})

    Fault
    C_subw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rp1 = 0;
int32_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                            Rp1 = (int32_t)Rp1 - Rp2;
                        ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::c_addw(['\n                            Rp1_sd = (int32_t)Rp1_sd + Rp2_sw;\n                        '],{})

    Fault
    C_addw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rp1 = 0;
int32_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                            Rp1 = (int32_t)Rp1 + Rp2;
                        ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// JOp::c_j((['\n            int64_t offset = CJUMPIMM<3:1> << 1 |\n                             CJUMPIMM<9:9> << 4 |\n                             CJUMPIMM<0:0> << 5 |\n                             CJUMPIMM<5:5> << 6 |\n                             CJUMPIMM<4:4> << 7 |\n                             CJUMPIMM<8:7> << 8 |\n                             CJUMPIMM<6:6> << 10;\n            if (CJUMPIMM<10:10> > 0)\n                offset |= ~((int64_t)0x7FF);\n            NPC = PC + offset;\n        ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    C_j::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
PC = __parserAutoPCState.pc();
;
        if (fault == NoFault) {
            
            int64_t offset = bits(CJUMPIMM, 3, 1) << 1 |
                             bits(CJUMPIMM, 9, 9) << 4 |
                             bits(CJUMPIMM, 0, 0) << 5 |
                             bits(CJUMPIMM, 5, 5) << 6 |
                             bits(CJUMPIMM, 4, 4) << 7 |
                             bits(CJUMPIMM, 8, 7) << 8 |
                             bits(CJUMPIMM, 6, 6) << 10;
            if (bits(CJUMPIMM, 10, 10) > 0)
                offset |= ~((int64_t)0x7FF);
            NPC = PC + offset;
        ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    C_j::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    C_j::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CBOp::c_beqz(['\n                if (Rp1 == 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    C_beqz::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rp1 = xc->readIntRegOperand(this, 0);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                if (Rp1 == 0)
                    NPC = PC + imm;
                else
                    NPC = NPC;
            ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    C_beqz::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    C_beqz::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_srcRegIdx[0],_srcRegIdx[1]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CBOp::c_bnez(['\n                if (Rp1 != 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    C_bnez::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rp1 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rp1 = xc->readIntRegOperand(this, 0);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                if (Rp1 != 0)
                    NPC = PC + imm;
                else
                    NPC = NPC;
            ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    C_bnez::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    C_bnez::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_srcRegIdx[0],_srcRegIdx[1]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// CIOp::c_slli((['\n            imm = CIMM5 | (CIMM1 << 5);\n        ', '\n            if (imm == 0) {\n                fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                      machInst);\n            }\n            if (RC1 == 0) {\n                fault = make_shared<IllegalInstFault>("source reg x0",\n                                                      machInst);\n            }\n            Rc1 = Rc1 << imm;\n        ', 'uint64_t'], {}))

    Fault
    C_slli::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rc1 = 0;
;
        Rc1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
            if (imm == 0) {
                fault = make_shared<IllegalInstFault>("immediate = 0",
                                                      machInst);
            }
            if (RC1 == 0) {
                fault = make_shared<IllegalInstFault>("source reg x0",
                                                      machInst);
            }
            Rc1 = Rc1 << imm;
        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    C_slli::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CompressedLoad::c_fldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                Fc1_bits = Mem;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_fldsp::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Fc1_bits = 0;
uint64_t sp = 0;
uint64_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                Fc1_bits = Mem;
            ;
        }

        if (fault == NoFault) {
            
        {
            uint64_t final_val = Fc1_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    C_fldsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
uint64_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    C_fldsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fc1_bits = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                Fc1_bits = Mem;
            ;
        }

        if (fault == NoFault) {
            
        {
            uint64_t final_val = Fc1_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// CompressedLoad::c_lwsp(['\n                offset = CIMM5<4:2> << 2 |\n                         CIMM1 << 5 |\n                         CIMM5<1:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = Mem_sw;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_lwsp::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
int64_t Rc1 = 0;
int32_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                if (RC1 == 0) {
                    fault = make_shared<IllegalInstFault>("source reg x0",
                                                          machInst);
                }
                Rc1 = Mem;
            ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    C_lwsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
int32_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    C_lwsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rc1 = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                if (RC1 == 0) {
                    fault = make_shared<IllegalInstFault>("source reg x0",
                                                          machInst);
                }
                Rc1 = Mem;
            ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// CompressedLoad::c_ldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = Mem_sd;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_ldsp::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
int64_t Rc1 = 0;
int64_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                if (RC1 == 0) {
                    fault = make_shared<IllegalInstFault>("source reg x0",
                                                          machInst);
                }
                Rc1 = Mem;
            ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    C_ldsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
int64_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    C_ldsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rc1 = 0;
int64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                if (RC1 == 0) {
                    fault = make_shared<IllegalInstFault>("source reg x0",
                                                          machInst);
                }
                Rc1 = Mem;
            ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Jump::c_jr((['\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    NPC = Rc1;\n                ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    C_jr::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rc1 = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rc1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    if (RC1 == 0) {
                        fault = make_shared<IllegalInstFault>("source reg x0",
                                                              machInst);
                    }
                    NPC = Rc1;
                ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    C_jr::branchTarget(ThreadContext *tc) const
    {
        PCState pc = tc->pcState();
        pc.set((tc->readIntReg(_srcRegIdx[0].index()) + imm)&~0x1);
        return pc;
    }

    std::string
    C_jr::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CROp::c_mv((['\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    Rc1 = Rc2;\n                '], {}))

    Fault
    C_mv::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rc1 = 0;
uint64_t Rc2 = 0;
;
        Rc2 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    if (RC1 == 0) {
                        fault = make_shared<IllegalInstFault>("source reg x0",
                                                              machInst);
                    }
                    Rc1 = Rc2;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// SystemOp::c_ebreak((['\n                    if (RC2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    fault = make_shared<BreakpointFault>(xc->pcState());\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'], {}))

    Fault
    C_ebreak::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        ;
        ;
        if (fault == NoFault) {
            
                    if (RC2 != 0) {
                        fault = make_shared<IllegalInstFault>("source reg x1",
                                                              machInst);
                    }
                    fault = make_shared<BreakpointFault>(xc->pcState());
                ;
            if (fault == NoFault) {
                ;
            }
        }
        return fault;
    }

// Jump::c_jalr((['\n                        if (RC1 == 0) {\n                            fault = make_shared<IllegalInstFault>\n                                                        ("source reg x0",\n                                                         machInst);\n                        }\n                        ra = NPC;\n                        NPC = Rc1;\n                    ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    C_jalr::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t ra = 0;
uint64_t Rc1 = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rc1 = xc->readIntRegOperand(this, 0);
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                        if (RC1 == 0) {
                            fault = make_shared<IllegalInstFault>
                                                        ("source reg x0",
                                                         machInst);
                        }
                        ra = NPC;
                        NPC = Rc1;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = ra;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }__parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    C_jalr::branchTarget(ThreadContext *tc) const
    {
        PCState pc = tc->pcState();
        pc.set((tc->readIntReg(_srcRegIdx[0].index()) + imm)&~0x1);
        return pc;
    }

    std::string
    C_jalr::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// ROp::c_add((['\n                        Rc1_sd = Rc1_sd + Rc2_sd;\n                    '], {}))

    Fault
    C_add::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rc1 = 0;
int64_t Rc2 = 0;
;
        Rc1 = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rc1 = Rc1 + Rc2;
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// CompressedStore::c_fsdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem_ud = Fc2_bits;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_fsdsp::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
uint64_t Fc2_bits = 0;
uint64_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
Fc2_bits = xc->readFloatRegOperandBits(this, 1);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Fc2_bits;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_fsdsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
uint64_t Fc2_bits = 0;
uint64_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
Fc2_bits = xc->readFloatRegOperandBits(this, 1);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Fc2_bits;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_fsdsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// CompressedStore::c_swsp(['\n                offset = CIMM6<5:2> << 2 |\n                         CIMM6<1:0> << 6;\n            ', '\n                Mem_uw = Rc2_uw;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_swsp::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
uint32_t Rc2 = 0;
uint32_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Rc2;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_swsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
uint32_t Rc2 = 0;
uint32_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Rc2;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_swsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// CompressedStore::c_sdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem = Rc2;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_sdsp::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
uint64_t Rc2 = 0;
uint64_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Rc2;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_sdsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t sp = 0;
uint64_t Rc2 = 0;
uint64_t Mem;
;
        sp = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                EA = sp + offset;
            ;

        if (fault == NoFault) {
            
                Mem = Rc2;
            ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    C_sdsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// Load::lb(['\n                    Rd_sd = Mem_sb;\n                '],{})

    Fault
    Lb::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int8_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Lb::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int8_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Lb::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int8_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Load::lh(['\n                    Rd_sd = Mem_sh;\n                '],{})

    Fault
    Lh::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int16_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Lh::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int16_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Lh::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int16_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Load::lw(['\n                    Rd_sd = Mem_sw;\n                '],{})

    Fault
    Lw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Lw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Lw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Load::ld(['\n                    Rd_sd = Mem_sd;\n                '],{})

    Fault
    Ld::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Ld::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Ld::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Load::lbu(['\n                    Rd = Mem_ub;\n                '],{})

    Fault
    Lbu::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint8_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Lbu::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint8_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Lbu::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint8_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Load::lhu(['\n                    Rd = Mem_uh;\n                '],{})

    Fault
    Lhu::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint16_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Lhu::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint16_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Lhu::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint16_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Load::lwu(['\n                    Rd = Mem_uw;\n                '],{})

    Fault
    Lwu::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Lwu::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Lwu::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Unknown::unknown(([], {}))

// Load::flw(['\n                    Fd_bits = (uint64_t)Mem_uw;\n                '],{'inst_flags': 'FloatMemReadOp'})

    Fault
    Flw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Fd_bits = (uint64_t)Mem;
                ;
        }

        if (fault == NoFault) {
            
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Flw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Flw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Fd_bits = (uint64_t)Mem;
                ;
        }

        if (fault == NoFault) {
            
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Load::fld(['\n                    Fd_bits = Mem;\n                '],{'inst_flags': 'FloatMemReadOp'})

    Fault
    Fld::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Fd_bits = Mem;
                ;
        }

        if (fault == NoFault) {
            
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Fld::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Fld::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Fd_bits = Mem;
                ;
        }

        if (fault == NoFault) {
            
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// Unknown::unknown(([], {}))

// IOp::fence(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsMemBarrier', 'No_OpClass'],{})

    Fault
    Fence::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        ;
        ;
        if (fault == NoFault) {
            
                ;
            if (fault == NoFault) {
                ;
            }
        }
        return fault;
    }

    std::string
    Fence::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::fence_i(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    Fault
    Fence_i::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        ;
        ;
        if (fault == NoFault) {
            
                ;
            if (fault == NoFault) {
                ;
            }
        }
        return fault;
    }

    std::string
    Fence_i::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// IOp::addi(['\n                    Rd_sd = Rs1_sd + imm;\n                '],{})

    Fault
    Addi::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = Rs1 + imm;
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Addi::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::slli(['\n                    Rd = Rs1 << SHAMT6;\n                '],{})

    Fault
    Slli::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = Rs1 << SHAMT6;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Slli::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::slti(['\n                    Rd = (Rs1_sd < imm) ? 1 : 0;\n                '],{})

    Fault
    Slti::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = (Rs1 < imm) ? 1 : 0;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Slti::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::sltiu(['\n                    Rd = (Rs1 < imm) ? 1 : 0;\n                ', 'uint64_t'],{})

    Fault
    Sltiu::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = (Rs1 < imm) ? 1 : 0;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Sltiu::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::xori(['\n                    Rd = Rs1 ^ imm;\n                ', 'uint64_t'],{})

    Fault
    Xori::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = Rs1 ^ imm;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Xori::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::srli(['\n                        Rd = Rs1 >> SHAMT6;\n                    '],{})

    Fault
    Srli::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 >> SHAMT6;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Srli::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::srai(['\n                        Rd_sd = Rs1_sd >> SHAMT6;\n                    '],{})

    Fault
    Srai::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 >> SHAMT6;
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Srai::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// IOp::ori(['\n                    Rd = Rs1 | imm;\n                ', 'uint64_t'],{})

    Fault
    Ori::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = Rs1 | imm;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Ori::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::andi(['\n                    Rd = Rs1 & imm;\n                ', 'uint64_t'],{})

    Fault
    Andi::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = Rs1 & imm;
                ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Andi::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// UOp::auipc((['\n            Rd = PC + imm;\n        '], {}))

    Fault
    Auipc::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t PC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
PC = __parserAutoPCState.pc();
;
        if (fault == NoFault) {
            
            Rd = PC + imm;
        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Auipc::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::addiw(['\n                    Rd_sd = Rs1_sw + imm;\n                ', 'int32_t'],{})

    Fault
    Addiw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = Rs1 + imm;
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Addiw::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::slliw(['\n                    Rd_sd = Rs1_sw << SHAMT5;\n                '],{})

    Fault
    Slliw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                    Rd = Rs1 << SHAMT5;
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Slliw::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::srliw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> SHAMT5);\n                    '],{})

    Fault
    Srliw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
uint32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                        Rd = (int32_t)(Rs1 >> SHAMT5);
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Srliw::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::sraiw(['\n                        Rd_sd = Rs1_sw >> SHAMT5;\n                    '],{})

    Fault
    Sraiw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 >> SHAMT5;
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Sraiw::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Store::sb(['\n                    Mem_ub = Rs2_ub;\n                '],{})

    Fault
    Sb::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint8_t Rs2 = 0;
uint8_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Sb::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint8_t Rs2 = 0;
uint8_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Sb::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Store::sh(['\n                    Mem_uh = Rs2_uh;\n                '],{})

    Fault
    Sh::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint16_t Rs2 = 0;
uint16_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Sh::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint16_t Rs2 = 0;
uint16_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Sh::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Store::sw(['\n                    Mem_uw = Rs2_uw;\n                '],{})

    Fault
    Sw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Sw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Sw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Store::sd(['\n                    Mem_ud = Rs2_ud;\n                '],{})

    Fault
    Sd::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Sd::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Sd::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// Store::fsw(['\n                    Mem_uw = (uint32_t)Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    Fault
    Fsw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Fs2_bits = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = (uint32_t)Fs2_bits;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Fsw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Fs2_bits = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = (uint32_t)Fs2_bits;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Fsw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Store::fsd(['\n                    Mem_ud = Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    Fault
    Fsd::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Fs2_bits = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Fs2_bits;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Fsd::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Fs2_bits = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        EA = Rs1 + offset;;

        if (fault == NoFault) {
            
                    Mem = Fs2_bits;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault
    Fsd::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// LoadReserved::lr_w((['\n                    Rd_sd = Mem_sw;\n                '], {'mem_flags': 'LLSC'}))

    Fault
    Lr_w::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Lr_w::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Lr_w::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// StoreCond::sc_w((['\n                    Mem_uw = Rs2_uw;\n                ', '\n                    Rd = result;\n                '], {'mem_flags': 'LLSC', 'inst_flags': 'IsStoreConditional'}))

    Fault Sc_w::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;
        uint64_t result;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                &result);
            // RISC-V has the opposite convention gem5 has for success flags,
            // so we invert the result here.
            result = !result;
        }

        if (fault == NoFault) {
            
                    Rd = result;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Sc_w::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
uint32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault Sc_w::completeAcc(Packet *pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
;

        // RISC-V has the opposite convention gem5 has for success flags,
        // so we invert the result here.
        uint64_t result = !pkt->req->getExtraData();

        if (fault == NoFault) {
            
                    Rd = result;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// AtomicMemOp::amoadd_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_sw + Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amoadd_w::Amoadd_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoadd_w::Amoadd_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoadd_w::Amoadd_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoadd_w::Amoadd_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2 + Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoadd_w::Amoadd_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2 + Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoadd_w::Amoadd_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amoswap_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amoswap_w::Amoswap_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoswap_w::Amoswap_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoswap_w::Amoswap_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoswap_w::Amoswap_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoswap_w::Amoswap_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoswap_w::Amoswap_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amoxor_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw^Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amoxor_w::Amoxor_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoxor_w::Amoxor_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoxor_w::Amoxor_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoxor_w::Amoxor_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2^Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoxor_w::Amoxor_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2^Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoxor_w::Amoxor_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amoor_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw | Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amoor_w::Amoor_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoor_w::Amoor_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoor_w::Amoor_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoor_w::Amoor_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2 | Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoor_w::Amoor_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2 | Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoor_w::Amoor_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amoand_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw&Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amoand_w::Amoand_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoand_w::Amoand_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoand_w::Amoand_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoand_w::Amoand_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2&Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoand_w::Amoand_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2&Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoand_w::Amoand_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amomin_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = min<int32_t>(Rs2_sw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amomin_w::Amomin_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomin_w::Amomin_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amomin_w::Amomin_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomin_w::Amomin_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = min<int32_t>(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomin_w::Amomin_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = min<int32_t>(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomin_w::Amomin_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amomax_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = max<int32_t>(Rs2_sw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amomax_w::Amomax_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomax_w::Amomax_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amomax_w::Amomax_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomax_w::Amomax_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = max<int32_t>(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomax_w::Amomax_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = max<int32_t>(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomax_w::Amomax_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amominu_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = min<uint32_t>(Rs2_uw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amominu_w::Amominu_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amominu_w::Amominu_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amominu_w::Amominu_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amominu_w::Amominu_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = min<uint32_t>(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amominu_w::Amominu_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = min<uint32_t>(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amominu_w::Amominu_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amomaxu_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = max<uint32_t>(Rs2_uw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amomaxu_w::Amomaxu_wLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomaxu_w::Amomaxu_wLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amomaxu_w::Amomaxu_wLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int32_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomaxu_w::Amomaxu_wStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = max<uint32_t>(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomaxu_w::Amomaxu_wStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int64_t Rt = 0;
int32_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = max<uint32_t>(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomaxu_w::Amomaxu_wStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// LoadReserved::lr_d((['\n                    Rd_sd = Mem_sd;\n                '], {'mem_flags': 'LLSC'}))

    Fault
    Lr_d::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Lr_d::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault
    Lr_d::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            
                    Rd = Mem;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// StoreCond::sc_d((['\n                    Mem = Rs2;\n                ', '\n                    Rd = result;\n                '], {'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'}))

    Fault Sc_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;
        uint64_t result;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                &result);
            // RISC-V has the opposite convention gem5 has for success flags,
            // so we invert the result here.
            result = !result;
        }

        if (fault == NoFault) {
            
                    Rd = result;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault
    Sc_d::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                    Mem = Rs2;
                ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
        }

        if (fault == NoFault) {
            ;
        }

        return fault;
    }

    Fault Sc_d::completeAcc(Packet *pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
;

        // RISC-V has the opposite convention gem5 has for success flags,
        // so we invert the result here.
        uint64_t result = !pkt->req->getExtraData();

        if (fault == NoFault) {
            
                    Rd = result;
                ;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

// AtomicMemOp::amoadd_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = Rs2_sd + Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amoadd_d::Amoadd_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoadd_d::Amoadd_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoadd_d::Amoadd_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoadd_d::Amoadd_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2 + Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoadd_d::Amoadd_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2 + Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoadd_d::Amoadd_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amoswap_d(['Rt = Mem;', '\n                        Mem = Rs2;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Fault Amoswap_d::Amoswap_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoswap_d::Amoswap_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoswap_d::Amoswap_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rt = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoswap_d::Amoswap_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoswap_d::Amoswap_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoswap_d::Amoswap_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amoxor_d(['Rt = Mem;', '\n                        Mem = Rs2^Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Fault Amoxor_d::Amoxor_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoxor_d::Amoxor_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoxor_d::Amoxor_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rt = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoxor_d::Amoxor_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2^Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoxor_d::Amoxor_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2^Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoxor_d::Amoxor_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amoor_d(['Rt = Mem;', '\n                        Mem = Rs2 | Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Fault Amoor_d::Amoor_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoor_d::Amoor_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoor_d::Amoor_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rt = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoor_d::Amoor_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2 | Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoor_d::Amoor_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2 | Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoor_d::Amoor_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amoand_d(['Rt = Mem;', '\n                        Mem = Rs2&Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Fault Amoand_d::Amoand_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoand_d::Amoand_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amoand_d::Amoand_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rt = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoand_d::Amoand_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2&Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoand_d::Amoand_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = Rs2&Rt;
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amoand_d::Amoand_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amomin_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = min(Rs2_sd, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amomin_d::Amomin_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomin_d::Amomin_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amomin_d::Amomin_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomin_d::Amomin_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = min(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomin_d::Amomin_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = min(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomin_d::Amomin_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amomax_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = max(Rs2_sd, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    Fault Amomax_d::Amomax_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomax_d::Amomax_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amomax_d::Amomax_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rt = 0;
int64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomax_d::Amomax_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = max(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomax_d::Amomax_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Rt = 0;
int64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = max(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomax_d::Amomax_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amominu_d(['Rt = Mem;', '\n                        Mem = min(Rs2, Rt);\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Fault Amominu_d::Amominu_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amominu_d::Amominu_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amominu_d::Amominu_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rt = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amominu_d::Amominu_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = min(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amominu_d::Amominu_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = min(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amominu_d::Amominu_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// AtomicMemOp::amomaxu_d(['Rt = Mem;', '\n                        Mem = max(Rs2, Rt);\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    Fault Amomaxu_d::Amomaxu_dLoad::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = readMemAtomic(xc, traceData, EA, Mem, memAccessFlags);
        }

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomaxu_d::Amomaxu_dLoad::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        if (fault == NoFault) {
            fault = initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
        }

        return fault;
    }

    Fault Amomaxu_d::Amomaxu_dLoad::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rt = 0;
uint64_t Mem;
;
        ;

        getMem(pkt, Mem, traceData);

        if (fault == NoFault) {
            Rt = Mem;;
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rt;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomaxu_d::Amomaxu_dStore::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = max(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemAtomic(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomaxu_d::Amomaxu_dStore::initiateAcc(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Rt = 0;
uint64_t Mem;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
Rt = xc->readIntRegOperand(this, 2);
;
        EA = Rs1;;

        if (fault == NoFault) {
            
                        Mem = max(Rs2, Rt);
                        Rd = Rt;
                    ;
        }

        if (fault == NoFault) {
            fault = writeMemTiming(xc, traceData, Mem, EA, memAccessFlags,
                nullptr);
        }

        if (fault == NoFault) {
            
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        }

        return fault;
    }

    Fault Amomaxu_d::Amomaxu_dStore::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// ROp::add(['\n                        Rd = Rs1_sd + Rs2_sd;\n                    '],{})

    Fault
    Add::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 + Rs2;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::mul(['\n                        Rd = Rs1_sd*Rs2_sd;\n                    ', 'IntMultOp'],{})

    Fault
    Mul::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1*Rs2;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::sub(['\n                        Rd = Rs1_sd - Rs2_sd;\n                    '],{})

    Fault
    Sub::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 - Rs2;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::sll(['\n                        Rd = Rs1 << Rs2<5:0>;\n                    '],{})

    Fault
    Sll::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 << bits(Rs2, 5, 0);
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::mulh(['\n                        bool negate = (Rs1_sd < 0) != (Rs2_sd < 0);\n\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)abs(Rs2_sd);\n                        uint64_t Rs2_hi = (uint64_t)abs(Rs2_sd) >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs2_lo*Rs1_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2_sd == 0 ? 1 : 0)\n                                    : res;\n                    ', 'IntMultOp'],{})

    Fault
    Mulh::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        bool negate = (Rs1 < 0) != (Rs2 < 0);

                        uint64_t Rs1_lo = (uint32_t)abs(Rs1);
                        uint64_t Rs1_hi = (uint64_t)abs(Rs1) >> 32;
                        uint64_t Rs2_lo = (uint32_t)abs(Rs2);
                        uint64_t Rs2_hi = (uint64_t)abs(Rs2) >> 32;

                        uint64_t hi = Rs1_hi*Rs2_hi;
                        uint64_t mid1 = Rs1_hi*Rs2_lo;
                        uint64_t mid2 = Rs1_lo*Rs2_hi;
                        uint64_t lo = Rs2_lo*Rs1_lo;
                        uint64_t carry = ((uint64_t)(uint32_t)mid1
                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;

                        uint64_t res = hi +
                                       (mid1 >> 32) +
                                       (mid2 >> 32) +
                                       carry;
                        Rd = negate ? ~res + (Rs1*Rs2 == 0 ? 1 : 0)
                                    : res;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::slt(['\n                        Rd = (Rs1_sd < Rs2_sd) ? 1 : 0;\n                    '],{})

    Fault
    Slt::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = (Rs1 < Rs2) ? 1 : 0;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::mulhsu(['\n                        bool negate = Rs1_sd < 0;\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2 == 0 ? 1 : 0) : res;\n                    ', 'IntMultOp'],{})

    Fault
    Mulhsu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
int64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        bool negate = Rs1 < 0;
                        uint64_t Rs1_lo = (uint32_t)abs(Rs1);
                        uint64_t Rs1_hi = (uint64_t)abs(Rs1) >> 32;
                        uint64_t Rs2_lo = (uint32_t)Rs2;
                        uint64_t Rs2_hi = Rs2 >> 32;

                        uint64_t hi = Rs1_hi*Rs2_hi;
                        uint64_t mid1 = Rs1_hi*Rs2_lo;
                        uint64_t mid2 = Rs1_lo*Rs2_hi;
                        uint64_t lo = Rs1_lo*Rs2_lo;
                        uint64_t carry = ((uint64_t)(uint32_t)mid1
                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;

                        uint64_t res = hi +
                                       (mid1 >> 32) +
                                       (mid2 >> 32) +
                                       carry;
                        Rd = negate ? ~res + (Rs1*Rs2 == 0 ? 1 : 0) : res;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::sltu(['\n                        Rd = (Rs1 < Rs2) ? 1 : 0;\n                    '],{})

    Fault
    Sltu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = (Rs1 < Rs2) ? 1 : 0;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::mulhu(['\n                        uint64_t Rs1_lo = (uint32_t)Rs1;\n                        uint64_t Rs1_hi = Rs1 >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;\n                    ', 'IntMultOp'],{})

    Fault
    Mulhu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        uint64_t Rs1_lo = (uint32_t)Rs1;
                        uint64_t Rs1_hi = Rs1 >> 32;
                        uint64_t Rs2_lo = (uint32_t)Rs2;
                        uint64_t Rs2_hi = Rs2 >> 32;

                        uint64_t hi = Rs1_hi*Rs2_hi;
                        uint64_t mid1 = Rs1_hi*Rs2_lo;
                        uint64_t mid2 = Rs1_lo*Rs2_hi;
                        uint64_t lo = Rs1_lo*Rs2_lo;
                        uint64_t carry = ((uint64_t)(uint32_t)mid1
                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;

                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::xor(['\n                        Rd = Rs1 ^ Rs2;\n                    '],{})

    Fault
    Xor::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 ^ Rs2;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::div(['\n                        if (Rs2_sd == 0) {\n                            Rd_sd = -1;\n                        } else if (Rs1_sd == numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                        } else {\n                            Rd_sd = Rs1_sd/Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Div::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        if (Rs2 == 0) {
                            Rd = -1;
                        } else if (Rs1 == numeric_limits<int64_t>::min()
                                && Rs2 == -1) {
                            Rd = numeric_limits<int64_t>::min();
                        } else {
                            Rd = Rs1/Rs2;
                        }
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::srl(['\n                        Rd = Rs1 >> Rs2<5:0>;\n                    '],{})

    Fault
    Srl::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 >> bits(Rs2, 5, 0);
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::divu(['\n                        if (Rs2 == 0) {\n                            Rd = numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd = Rs1/Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Divu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        if (Rs2 == 0) {
                            Rd = numeric_limits<uint64_t>::max();
                        } else {
                            Rd = Rs1/Rs2;
                        }
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::sra(['\n                        Rd_sd = Rs1_sd >> Rs2<5:0>;\n                    '],{})

    Fault
    Sra::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 >> bits(Rs2, 5, 0);
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::or(['\n                        Rd = Rs1 | Rs2;\n                    '],{})

    Fault
    Or::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 | Rs2;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::rem(['\n                        if (Rs2_sd == 0) {\n                            Rd = Rs1_sd;\n                        } else if (Rs1_sd == numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd = 0;\n                        } else {\n                            Rd = Rs1_sd%Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Rem::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        if (Rs2 == 0) {
                            Rd = Rs1;
                        } else if (Rs1 == numeric_limits<int64_t>::min()
                                && Rs2 == -1) {
                            Rd = 0;
                        } else {
                            Rd = Rs1%Rs2;
                        }
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::and(['\n                        Rd = Rs1 & Rs2;\n                    '],{})

    Fault
    And::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 & Rs2;
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::remu(['\n                        if (Rs2 == 0) {\n                            Rd = Rs1;\n                        } else {\n                            Rd = Rs1%Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Remu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        if (Rs2 == 0) {
                            Rd = Rs1;
                        } else {
                            Rd = Rs1%Rs2;
                        }
                    ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// UOp::lui((['\n            Rd = (uint64_t)imm;\n        '], {}))

    Fault
    Lui::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
;
        ;
        if (fault == NoFault) {
            
            Rd = (uint64_t)imm;
        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

    std::string
    Lui::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// ROp::addw(['\n                        Rd_sd = Rs1_sw + Rs2_sw;\n                    '],{})

    Fault
    Addw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 + Rs2;
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::mulw(['\n                        Rd_sd = (int32_t)(Rs1_sw*Rs2_sw);\n                    ', 'IntMultOp'],{})

    Fault
    Mulw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = (int32_t)(Rs1*Rs2);
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::subw(['\n                        Rd_sd = Rs1_sw - Rs2_sw;\n                    '],{})

    Fault
    Subw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 - Rs2;
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::sllw(['\n                    Rd_sd = Rs1_sw << Rs2<4:0>;\n                '],{})

    Fault
    Sllw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                    Rd = Rs1 << bits(Rs2, 4, 0);
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::divw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = -1;\n                    } else if (Rs1_sw == numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = numeric_limits<int32_t>::min();\n                    } else {\n                        Rd_sd = Rs1_sw/Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    Fault
    Divw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                    if (Rs2 == 0) {
                        Rd = -1;
                    } else if (Rs1 == numeric_limits<int32_t>::min()
                            && Rs2 == -1) {
                        Rd = numeric_limits<int32_t>::min();
                    } else {
                        Rd = Rs1/Rs2;
                    }
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::srlw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> Rs2<4:0>);\n                    '],{})

    Fault
    Srlw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
uint32_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = (int32_t)(Rs1 >> bits(Rs2, 4, 0));
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::divuw(['\n                        if (Rs2_uw == 0) {\n                            Rd_sd = numeric_limits<IntReg>::max();\n                        } else {\n                            Rd_sd = (int32_t)(Rs1_uw/Rs2_uw);\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Divuw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
uint32_t Rs1 = 0;
uint32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        if (Rs2 == 0) {
                            Rd = numeric_limits<IntReg>::max();
                        } else {
                            Rd = (int32_t)(Rs1/Rs2);
                        }
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::sraw(['\n                        Rd_sd = Rs1_sw >> Rs2<4:0>;\n                    '],{})

    Fault
    Sraw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                        Rd = Rs1 >> bits(Rs2, 4, 0);
                    ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// ROp::remw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = Rs1_sw;\n                    } else if (Rs1_sw == numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = 0;\n                    } else {\n                        Rd_sd = Rs1_sw%Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    Fault
    Remw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                    if (Rs2 == 0) {
                        Rd = Rs1;
                    } else if (Rs1 == numeric_limits<int32_t>::min()
                            && Rs2 == -1) {
                        Rd = 0;
                    } else {
                        Rd = Rs1%Rs2;
                    }
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// ROp::remuw(['\n                    if (Rs2_uw == 0) {\n                        Rd_sd = (int32_t)Rs1_uw;\n                    } else {\n                        Rd_sd = (int32_t)(Rs1_uw%Rs2_uw);\n                    }\n                ', 'IntDivOp'],{})

    Fault
    Remuw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
uint32_t Rs1 = 0;
uint32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        if (fault == NoFault) {
            
                    if (Rs2 == 0) {
                        Rd = (int32_t)Rs1;
                    } else {
                        Rd = (int32_t)(Rs1%Rs2);
                    }
                ;
            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = fs3;\n                        }\n                    } else {\n                        fd = fs1*fs2 + fs3;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    Fault Fmadd_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);
                    float fd;

                    if (std::isnan(fs1) || std::isnan(fs2) ||
                            std::isnan(fs3)) {
                        if (issignalingnan(fs1) || issignalingnan(fs2)
                                || issignalingnan(fs3)) {
                            FFLAGS |= FloatInvalid;
                        }
                        fd = numeric_limits<float>::quiet_NaN();
                    } else if (std::isinf(fs1) || std::isinf(fs2) ||
                            std::isinf(fs3)) {
                        if (signbit(fs1) == signbit(fs2)
                                && !std::isinf(fs3)) {
                            fd = numeric_limits<float>::infinity();
                        } else if (signbit(fs1) != signbit(fs2)
                                && !std::isinf(fs3)) {
                            fd = -numeric_limits<float>::infinity();
                        } else { // Fs3 is infinity
                            fd = fs3;
                        }
                    } else {
                        fd = fs1*fs2 + fs3;
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fmadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else {\n                            Fd = Fs3;\n                        }\n                    } else {\n                        Fd = Fs1*Fs2 + Fs3;\n                    }\n                ', 'FloatMultAccOp'],{})

    Fault Fmadd_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
double Fs3 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
Fs3 = xc->readFloatRegOperand(this, 2);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (std::isnan(Fs1) || std::isnan(Fs2) ||
                            std::isnan(Fs3)) {
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)
                                || issignalingnan(Fs3)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Fd = numeric_limits<double>::quiet_NaN();
                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||
                            std::isinf(Fs3)) {
                        if (signbit(Fs1) == signbit(Fs2)
                                && !std::isinf(Fs3)) {
                            Fd = numeric_limits<double>::infinity();
                        } else if (signbit(Fs1) != signbit(Fs2)
                                && !std::isinf(Fs3)) {
                            Fd = -numeric_limits<double>::infinity();
                        } else {
                            Fd = Fs3;
                        }
                    } else {
                        Fd = Fs1*Fs2 + Fs3;
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = -fs3;\n                        }\n                    } else {\n                        fd = fs1*fs2 - fs3;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    Fault Fmsub_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);
                    float fd;

                    if (std::isnan(fs1) || std::isnan(fs2) ||
                            std::isnan(fs3)) {
                        if (issignalingnan(fs1) || issignalingnan(fs2)
                                || issignalingnan(fs3)) {
                            FFLAGS |= FloatInvalid;
                        }
                        fd = numeric_limits<float>::quiet_NaN();
                    } else if (std::isinf(fs1) || std::isinf(fs2) ||
                            std::isinf(fs3)) {
                        if (signbit(fs1) == signbit(fs2)
                                && !std::isinf(fs3)) {
                            fd = numeric_limits<float>::infinity();
                        } else if (signbit(fs1) != signbit(fs2)
                                && !std::isinf(fs3)) {
                            fd = -numeric_limits<float>::infinity();
                        } else { // Fs3 is infinity
                            fd = -fs3;
                        }
                    } else {
                        fd = fs1*fs2 - fs3;
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fmsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else {\n                            Fd = -Fs3;\n                        }\n                    } else {\n                        Fd = Fs1*Fs2 - Fs3;\n                    }\n                ', 'FloatMultAccOp'],{})

    Fault Fmsub_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
double Fs3 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
Fs3 = xc->readFloatRegOperand(this, 2);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (std::isnan(Fs1) || std::isnan(Fs2) ||
                            std::isnan(Fs3)) {
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)
                                || issignalingnan(Fs3)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Fd = numeric_limits<double>::quiet_NaN();
                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||
                            std::isinf(Fs3)) {
                        if (signbit(Fs1) == signbit(Fs2)
                                && !std::isinf(Fs3)) {
                            Fd = numeric_limits<double>::infinity();
                        } else if (signbit(Fs1) != signbit(Fs2)
                                && !std::isinf(Fs3)) {
                            Fd = -numeric_limits<double>::infinity();
                        } else {
                            Fd = -Fs3;
                        }
                    } else {
                        Fd = Fs1*Fs2 - Fs3;
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fnmsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = fs3;\n                        }\n                    } else {\n                        fd = -(fs1*fs2 - fs3);\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    Fault Fnmsub_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);
                    float fd;

                    if (std::isnan(fs1) || std::isnan(fs2) ||
                            std::isnan(fs3)) {
                        if (issignalingnan(fs1) || issignalingnan(fs2)
                                || issignalingnan(fs3)) {
                            FFLAGS |= FloatInvalid;
                        }
                        fd = numeric_limits<float>::quiet_NaN();
                    } else if (std::isinf(fs1) || std::isinf(fs2) ||
                            std::isinf(fs3)) {
                        if (signbit(fs1) == signbit(fs2)
                                && !std::isinf(fs3)) {
                            fd = -numeric_limits<float>::infinity();
                        } else if (signbit(fs1) != signbit(fs2)
                                && !std::isinf(fs3)) {
                            fd = numeric_limits<float>::infinity();
                        } else { // Fs3 is infinity
                            fd = fs3;
                        }
                    } else {
                        fd = -(fs1*fs2 - fs3);
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fnmsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2)\n                            || std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else {\n                            Fd = Fs3;\n                        }\n                    } else {\n                        Fd = -(Fs1*Fs2 - Fs3);\n                    }\n                ', 'FloatMultAccOp'],{})

    Fault Fnmsub_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
double Fs3 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
Fs3 = xc->readFloatRegOperand(this, 2);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (std::isnan(Fs1) || std::isnan(Fs2) ||
                            std::isnan(Fs3)) {
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)
                                || issignalingnan(Fs3)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Fd = numeric_limits<double>::quiet_NaN();
                    } else if (std::isinf(Fs1) || std::isinf(Fs2)
                            || std::isinf(Fs3)) {
                        if (signbit(Fs1) == signbit(Fs2)
                                && !std::isinf(Fs3)) {
                            Fd = -numeric_limits<double>::infinity();
                        } else if (signbit(Fs1) != signbit(Fs2)
                                && !std::isinf(Fs3)) {
                            Fd = numeric_limits<double>::infinity();
                        } else {
                            Fd = Fs3;
                        }
                    } else {
                        Fd = -(Fs1*Fs2 - Fs3);
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fnmadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = -fs3;\n                        }\n                    } else {\n                        fd = -(fs1*fs2 + fs3);\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    Fault Fnmadd_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);
                    float fd;

                    if (std::isnan(fs1) || std::isnan(fs2) ||
                            std::isnan(fs3)) {
                        if (issignalingnan(fs1) || issignalingnan(fs2)
                                || issignalingnan(fs3)) {
                            FFLAGS |= FloatInvalid;
                        }
                        fd = numeric_limits<float>::quiet_NaN();
                    } else if (std::isinf(fs1) || std::isinf(fs2) ||
                            std::isinf(fs3)) {
                        if (signbit(fs1) == signbit(fs2)
                                && !std::isinf(fs3)) {
                            fd = -numeric_limits<float>::infinity();
                        } else if (signbit(fs1) != signbit(fs2)
                                && !std::isinf(fs3)) {
                            fd = numeric_limits<float>::infinity();
                        } else { // Fs3 is infinity
                            fd = -fs3;
                        }
                    } else {
                        fd = -(fs1*fs2 + fs3);
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fnmadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else {\n                            Fd = -Fs3;\n                        }\n                    } else {\n                        Fd = -(Fs1*Fs2 + Fs3);\n                    }\n                ', 'FloatMultAccOp'],{})

    Fault Fnmadd_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
double Fs3 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
Fs3 = xc->readFloatRegOperand(this, 2);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (std::isnan(Fs1) || std::isnan(Fs2) ||
                            std::isnan(Fs3)) {
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)
                                || issignalingnan(Fs3)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Fd = numeric_limits<double>::quiet_NaN();
                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||
                            std::isinf(Fs3)) {
                        if (signbit(Fs1) == signbit(Fs2)
                                && !std::isinf(Fs3)) {
                            Fd = -numeric_limits<double>::infinity();
                        } else if (signbit(Fs1) != signbit(Fs2)
                                && !std::isinf(Fs3)) {
                            Fd = numeric_limits<double>::infinity();
                        } else {
                            Fd = -Fs3;
                        }
                    } else {
                        Fd = -(Fs1*Fs2 + Fs3);
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1 + fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatAddOp'],{})

    Fault Fadd_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                    float fd;

                    if (std::isnan(fs1) || std::isnan(fs2)) {
                        if (issignalingnan(fs1) || issignalingnan(fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        fd = numeric_limits<float>::quiet_NaN();
                    } else {
                        fd = fs1 + fs2;
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1 + Fs2;\n                    }\n                ', 'FloatAddOp'],{})

    Fault Fadd_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (std::isnan(Fs1) || std::isnan(Fs2)) {
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Fd = numeric_limits<double>::quiet_NaN();
                    } else {
                        Fd = Fs1 + Fs2;
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1 - fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatAddOp'],{})

    Fault Fsub_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                    float fd;

                    if (std::isnan(fs1) || std::isnan(fs2)) {
                        if (issignalingnan(fs1) || issignalingnan(fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        fd = numeric_limits<float>::quiet_NaN();
                    } else {
                        fd = fs1 - fs2;
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1 - Fs2;\n                    }\n                ', 'FloatAddOp'],{})

    Fault Fsub_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (std::isnan(Fs1) || std::isnan(Fs2)) {
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Fd = numeric_limits<double>::quiet_NaN();
                    } else {
                        Fd = Fs1 - Fs2;
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fmul_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1*fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultOp'],{})

    Fault Fmul_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                    float fd;

                    if (std::isnan(fs1) || std::isnan(fs2)) {
                        if (issignalingnan(fs1) || issignalingnan(fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        fd = numeric_limits<float>::quiet_NaN();
                    } else {
                        fd = fs1*fs2;
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fmul_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1*Fs2;\n                    }\n                ', 'FloatMultOp'],{})

    Fault Fmul_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (std::isnan(Fs1) || std::isnan(Fs2)) {
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Fd = numeric_limits<double>::quiet_NaN();
                    } else {
                        Fd = Fs1*Fs2;
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fdiv_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1/fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatDivOp'],{})

    Fault Fdiv_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                    float fd;

                    if (std::isnan(fs1) || std::isnan(fs2)) {
                        if (issignalingnan(fs1) || issignalingnan(fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        fd = numeric_limits<float>::quiet_NaN();
                    } else {
                        fd = fs1/fs2;
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fdiv_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1/Fs2;\n                    }\n                ', 'FloatDivOp'],{})

    Fault Fdiv_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (std::isnan(Fs1) || std::isnan(Fs2)) {
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Fd = numeric_limits<double>::quiet_NaN();
                    } else {
                        Fd = Fs1/Fs2;
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsgnj_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = copysign(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnj_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                        float fd;

                        if (issignalingnan(fs1)) {
                            fd = numeric_limits<float>::signaling_NaN();
                            feclearexcept(FE_INVALID);
                        } else {
                            fd = copysign(fs1, fs2);
                        }
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsgnjn_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = copysign(fs1, -fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnjn_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                        float fd;

                        if (issignalingnan(fs1)) {
                            fd = numeric_limits<float>::signaling_NaN();
                            feclearexcept(FE_INVALID);
                        } else {
                            fd = copysign(fs1, -fs2);
                        }
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsgnjx_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = fs1*(signbit(fs2) ? -1.0 : 1.0);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnjx_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                        float fd;

                        if (issignalingnan(fs1)) {
                            fd = numeric_limits<float>::signaling_NaN();
                            feclearexcept(FE_INVALID);
                        } else {
                            fd = fs1*(signbit(fs2) ? -1.0 : 1.0);
                        }
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fsgnj_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = copysign(Fs1, Fs2);\n                        }\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnj_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (issignalingnan(Fs1)) {
                            Fd = numeric_limits<double>::signaling_NaN();
                            feclearexcept(FE_INVALID);
                        } else {
                            Fd = copysign(Fs1, Fs2);
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsgnjn_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = copysign(Fs1, -Fs2);\n                        }\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnjn_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (issignalingnan(Fs1)) {
                            Fd = numeric_limits<double>::signaling_NaN();
                            feclearexcept(FE_INVALID);
                        } else {
                            Fd = copysign(Fs1, -Fs2);
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsgnjx_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = Fs1*(signbit(Fs2) ? -1.0 : 1.0);\n                        }\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnjx_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (issignalingnan(Fs1)) {
                            Fd = numeric_limits<double>::signaling_NaN();
                            feclearexcept(FE_INVALID);
                        } else {
                            Fd = Fs1*(signbit(Fs2) ? -1.0 : 1.0);
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmin_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs2)) {\n                            fd = fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(fs1)) {\n                            fd = fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            fd = fmin(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatCmpOp'],{})

    Fault Fmin_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                        float fd;

                        if (issignalingnan(fs2)) {
                            fd = fs1;
                            FFLAGS |= FloatInvalid;
                        } else if (issignalingnan(fs1)) {
                            fd = fs2;
                            FFLAGS |= FloatInvalid;
                        } else {
                            fd = fmin(fs1, fs2);
                        }
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fmax_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs2)) {\n                            fd = fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(fs1)) {\n                            fd = fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            fd = fmax(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatCmpOp'],{})

    Fault Fmax_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);
                        float fd;

                        if (issignalingnan(fs2)) {
                            fd = fs1;
                            FFLAGS |= FloatInvalid;
                        } else if (issignalingnan(fs1)) {
                            fd = fs2;
                            FFLAGS |= FloatInvalid;
                        } else {
                            fd = fmax(fs1, fs2);
                        }
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmin_d(['\n                        if (issignalingnan(Fs2)) {\n                            Fd = Fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(Fs1)) {\n                            Fd = Fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Fd = fmin(Fs1, Fs2);\n                        }\n                    ', 'FloatCmpOp'],{})

    Fault Fmin_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (issignalingnan(Fs2)) {
                            Fd = Fs1;
                            FFLAGS |= FloatInvalid;
                        } else if (issignalingnan(Fs1)) {
                            Fd = Fs2;
                            FFLAGS |= FloatInvalid;
                        } else {
                            Fd = fmin(Fs1, Fs2);
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fmax_d(['\n                        if (issignalingnan(Fs2)) {\n                            Fd = Fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(Fs1)) {\n                            Fd = Fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Fd = fmax(Fs1, Fs2);\n                        }\n                    ', 'FloatCmpOp'],{})

    Fault Fmax_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (issignalingnan(Fs2)) {
                            Fd = Fs1;
                            FFLAGS |= FloatInvalid;
                        } else if (issignalingnan(Fs1)) {
                            Fd = Fs2;
                            FFLAGS |= FloatInvalid;
                        } else {
                            Fd = fmax(Fs1, Fs2);
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_d(['\n                    if (CONV_SGN != 1) {\n                        fault = make_shared<IllegalInstFault>("CONV_SGN != 1",\n                                                              machInst);\n                    }\n                    float fd;\n                    if (issignalingnan(Fs1)) {\n                        fd = numeric_limits<float>::quiet_NaN();\n                        FFLAGS |= FloatInvalid;\n                    } else {\n                        fd = (float)Fs1;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatCvtOp'],{})

    Fault Fcvt_s_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
double Fs1 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (CONV_SGN != 1) {
                        fault = make_shared<IllegalInstFault>("CONV_SGN != 1",
                                                              machInst);
                    }
                    float fd;
                    if (issignalingnan(Fs1)) {
                        fd = numeric_limits<float>::quiet_NaN();
                        FFLAGS |= FloatInvalid;
                    } else {
                        fd = (float)Fs1;
                    }
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_d_s(['\n                    if (CONV_SGN != 0) {\n                        fault = make_shared<IllegalInstFault>("CONV_SGN != 0",\n                                                              machInst);\n                    }\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                    if (issignalingnan(fs1)) {\n                        Fd = numeric_limits<double>::quiet_NaN();\n                        FFLAGS |= FloatInvalid;\n                    } else {\n                        Fd = (double)fs1;\n                    }\n                ', 'FloatCvtOp'],{})

    Fault Fcvt_d_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (CONV_SGN != 0) {
                        fault = make_shared<IllegalInstFault>("CONV_SGN != 0",
                                                              machInst);
                    }
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);

                    if (issignalingnan(fs1)) {
                        Fd = numeric_limits<double>::quiet_NaN();
                        FFLAGS |= FloatInvalid;
                    } else {
                        Fd = (double)fs1;
                    }
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsqrt_s(['\n                    if (RS2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fd;\n\n                    if (issignalingnan(Fs1_sf)) {\n                        FFLAGS |= FloatInvalid;\n                    }\n                    fd = sqrt(fs1);\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatSqrtOp'],{})

    Fault Fsqrt_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
float Fs1 = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs1 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (RS2 != 0) {
                        fault = make_shared<IllegalInstFault>("source reg x1",
                                                              machInst);
                    }
                    uint32_t temp;
                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                    float fd;

                    if (issignalingnan(Fs1)) {
                        FFLAGS |= FloatInvalid;
                    }
                    fd = sqrt(fs1);
                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fsqrt_d(['\n                    if (RS2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    Fd = sqrt(Fs1);\n                ', 'FloatSqrtOp'],{})

    Fault Fsqrt_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
double Fs1 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    if (RS2 != 0) {
                        fault = make_shared<IllegalInstFault>("source reg x1",
                                                              machInst);
                    }
                    Fd = sqrt(Fs1);
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fle_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (std::isnan(fs1) || std::isnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = fs1 <= fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    Fault Fle_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);

                        if (std::isnan(fs1) || std::isnan(fs2)) {
                            FFLAGS |= FloatInvalid;
                            Rd = 0;
                        } else {
                            Rd = fs1 <= fs2 ? 1 : 0;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::flt_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (std::isnan(fs1) || std::isnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = fs1 < fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    Fault Flt_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);

                        if (std::isnan(fs1) || std::isnan(fs2)) {
                            FFLAGS |= FloatInvalid;
                            Rd = 0;
                        } else {
                            Rd = fs1 < fs2 ? 1 : 0;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::feq_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Rd = fs1 == fs2 ? 1 : 0;\n                    ', 'FloatCmpOp'],{})

    Fault Feq_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);

                        if (issignalingnan(fs1) || issignalingnan(fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Rd = fs1 == fs2 ? 1 : 0;
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fle_d(['\n                        if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = Fs1 <= Fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    Fault Fle_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (std::isnan(Fs1) || std::isnan(Fs2)) {
                            FFLAGS |= FloatInvalid;
                            Rd = 0;
                        } else {
                            Rd = Fs1 <= Fs2 ? 1 : 0;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::flt_d(['\n                        if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = Fs1 < Fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    Fault Flt_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (std::isnan(Fs1) || std::isnan(Fs2)) {
                            FFLAGS |= FloatInvalid;
                            Rd = 0;
                        } else {
                            Rd = Fs1 < Fs2 ? 1 : 0;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::feq_d(['\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Rd = Fs1 == Fs2 ? 1 : 0;\n                    ', 'FloatCmpOp'],{})

    Fault Feq_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
double Fs1 = 0;
double Fs2 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
Fs2 = xc->readFloatRegOperand(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {
                            FFLAGS |= FloatInvalid;
                        }
                        Rd = Fs1 == Fs2 ? 1 : 0;
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 >= numeric_limits<int32_t>::max()) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 <= numeric_limits<int32_t>::min()) {\n                            Rd_sd = numeric_limits<int32_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int32_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_w_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);

                        if (std::isnan(fs1)) {
                            Rd = numeric_limits<int32_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (fs1 >= numeric_limits<int32_t>::max()) {
                            Rd = numeric_limits<int32_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (fs1 <= numeric_limits<int32_t>::min()) {
                            Rd = numeric_limits<int32_t>::min();
                            FFLAGS |= FloatInvalid;
                        } else {
                            Rd = (int32_t)fs1;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_wu_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < 0.0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<uint32_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint32_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_wu_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);

                        if (std::isnan(fs1)) {
                            Rd = numeric_limits<uint64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (fs1 < 0.0) {
                            Rd = 0;
                            FFLAGS |= FloatInvalid;
                        } else if (fs1 > numeric_limits<uint32_t>::max()) {
                            Rd = numeric_limits<uint64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else {
                            Rd = (uint32_t)fs1;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_l_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<int64_t>::max()) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < numeric_limits<int64_t>::min()) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int64_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_l_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);

                        if (std::isnan(fs1)) {
                            Rd = numeric_limits<int64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (fs1 > numeric_limits<int64_t>::max()) {
                            Rd = numeric_limits<int64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (fs1 < numeric_limits<int64_t>::min()) {
                            Rd = numeric_limits<int64_t>::min();
                            FFLAGS |= FloatInvalid;
                        } else {
                            Rd = (int64_t)fs1;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_lu_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < 0.0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<uint64_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint64_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_lu_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);

                        if (std::isnan(fs1)) {
                            Rd = numeric_limits<uint64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (fs1 < 0.0) {
                            Rd = 0;
                            FFLAGS |= FloatInvalid;
                        } else if (fs1 > numeric_limits<uint64_t>::max()) {
                            Rd = numeric_limits<uint64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else {
                            Rd = (uint64_t)fs1;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<int32_t>::max()) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < numeric_limits<int32_t>::min()) {\n                            Rd_sd = numeric_limits<int32_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int32_t)Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_w_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
double Fs1 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (std::isnan(Fs1)) {
                            Rd = numeric_limits<int32_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (Fs1 > numeric_limits<int32_t>::max()) {
                            Rd = numeric_limits<int32_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (Fs1 < numeric_limits<int32_t>::min()) {
                            Rd = numeric_limits<int32_t>::min();
                            FFLAGS |= FloatInvalid;
                        } else {
                            Rd = (int32_t)Fs1;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_wu_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < 0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<uint32_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint32_t)Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_wu_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
double Fs1 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (std::isnan(Fs1)) {
                            Rd = numeric_limits<uint64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (Fs1 < 0) {
                            Rd = 0;
                            FFLAGS |= FloatInvalid;
                        } else if (Fs1 > numeric_limits<uint32_t>::max()) {
                            Rd = numeric_limits<uint64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else {
                            Rd = (uint32_t)Fs1;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_l_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<int64_t>::max()) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < numeric_limits<int64_t>::min()) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_l_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rd = 0;
double Fs1 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (std::isnan(Fs1)) {
                            Rd = numeric_limits<int64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (Fs1 > numeric_limits<int64_t>::max()) {
                            Rd = numeric_limits<int64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (Fs1 < numeric_limits<int64_t>::min()) {
                            Rd = numeric_limits<int64_t>::min();
                            FFLAGS |= FloatInvalid;
                        } else {
                            Rd = Fs1;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_lu_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < 0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<uint64_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_lu_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
double Fs1 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        if (std::isnan(Fs1)) {
                            Rd = numeric_limits<uint64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else if (Fs1 < 0) {
                            Rd = 0;
                            FFLAGS |= FloatInvalid;
                        } else if (Fs1 > numeric_limits<uint64_t>::max()) {
                            Rd = numeric_limits<uint64_t>::max();
                            FFLAGS |= FloatInvalid;
                        } else {
                            Rd = Fs1;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_w(['\n                        float temp = (float)Rs1_sw;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_s_w::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        float temp = (float)Rs1;
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_s_wu(['\n                        float temp = (float)Rs1_uw;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_s_wu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        float temp = (float)Rs1;
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_s_l(['\n                        float temp = (float)Rs1_sd;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_s_l::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        float temp = (float)Rs1;
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_s_lu(['\n                        float temp = (float)Rs1;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_s_lu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        float temp = (float)Rs1;
                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_d_w(['\n                        Fd = (double)Rs1_sw;\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_d_w::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        Fd = (double)Rs1;
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_d_wu(['\n                        Fd = (double)Rs1_uw;\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_d_wu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
uint32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        Fd = (double)Rs1;
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_d_l(['\n                        Fd = (double)Rs1_sd;\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_d_l::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        Fd = (double)Rs1;
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fcvt_d_lu(['\n                        Fd = (double)Rs1;\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_d_lu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        double Fd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        Fd = (double)Rs1;
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            double final_val = Fd;
            xc->setFloatRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_x_s(['\n                        Rd = (uint32_t)Fs1_bits;\n                        if ((Rd&0x80000000) != 0) {\n                            Rd |= (0xFFFFFFFFULL << 32);\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fmv_x_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Rd = xc->readIntRegOperand(this, 0);
Fs1_bits = xc->readFloatRegOperandBits(this, 1);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        Rd = (uint32_t)Fs1_bits;
                        if ((Rd&0x80000000) != 0) {
                            Rd |= (0xFFFFFFFFULL << 32);
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fclass_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        switch (fpclassify(fs1)) {\n                          case FP_INFINITE:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 0;\n                            } else {\n                                Rd = 1 << 7;\n                            }\n                            break;\n                          case FP_NAN:\n                            if (issignalingnan(fs1)) {\n                                Rd = 1 << 8;\n                            } else {\n                                Rd = 1 << 9;\n                            }\n                            break;\n                          case FP_ZERO:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 3;\n                            } else {\n                                Rd = 1 << 4;\n                            }\n                            break;\n                          case FP_SUBNORMAL:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 2;\n                            } else {\n                                Rd = 1 << 5;\n                            }\n                            break;\n                          case FP_NORMAL:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 1;\n                            } else {\n                                Rd = 1 << 6;\n                            }\n                            break;\n                          default:\n                            panic("Unknown classification for operand.");\n                            break;\n                        }\n                    ', 'FloatMiscOp'],{})

    Fault Fclass_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        uint32_t temp;
                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);
                        switch (fpclassify(fs1)) {
                          case FP_INFINITE:
                            if (signbit(fs1)) {
                                Rd = 1 << 0;
                            } else {
                                Rd = 1 << 7;
                            }
                            break;
                          case FP_NAN:
                            if (issignalingnan(fs1)) {
                                Rd = 1 << 8;
                            } else {
                                Rd = 1 << 9;
                            }
                            break;
                          case FP_ZERO:
                            if (signbit(fs1)) {
                                Rd = 1 << 3;
                            } else {
                                Rd = 1 << 4;
                            }
                            break;
                          case FP_SUBNORMAL:
                            if (signbit(fs1)) {
                                Rd = 1 << 2;
                            } else {
                                Rd = 1 << 5;
                            }
                            break;
                          case FP_NORMAL:
                            if (signbit(fs1)) {
                                Rd = 1 << 1;
                            } else {
                                Rd = 1 << 6;
                            }
                            break;
                          default:
                            panic("Unknown classification for operand.");
                            break;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_x_d(['\n                        Rd = Fs1_bits;\n                    ', 'FloatCvtOp'],{})

    Fault Fmv_x_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        Rd = Fs1_bits;
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fclass_d(['\n                        switch (fpclassify(Fs1)) {\n                          case FP_INFINITE:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 0;\n                            } else {\n                                Rd = 1 << 7;\n                            }\n                            break;\n                          case FP_NAN:\n                            if (issignalingnan(Fs1)) {\n                                Rd = 1 << 8;\n                            } else {\n                                Rd = 1 << 9;\n                            }\n                            break;\n                          case FP_ZERO:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 3;\n                            } else {\n                                Rd = 1 << 4;\n                            }\n                            break;\n                          case FP_SUBNORMAL:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 2;\n                            } else {\n                                Rd = 1 << 5;\n                            }\n                            break;\n                          case FP_NORMAL:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 1;\n                            } else {\n                                Rd = 1 << 6;\n                            }\n                            break;\n                          default:\n                            panic("Unknown classification for operand.");\n                            break;\n                        }\n                    ', 'FloatMiscOp'],{})

    Fault Fclass_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
double Fs1 = 0;
;
        Fs1 = xc->readFloatRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                        switch (fpclassify(Fs1)) {
                          case FP_INFINITE:
                            if (signbit(Fs1)) {
                                Rd = 1 << 0;
                            } else {
                                Rd = 1 << 7;
                            }
                            break;
                          case FP_NAN:
                            if (issignalingnan(Fs1)) {
                                Rd = 1 << 8;
                            } else {
                                Rd = 1 << 9;
                            }
                            break;
                          case FP_ZERO:
                            if (signbit(Fs1)) {
                                Rd = 1 << 3;
                            } else {
                                Rd = 1 << 4;
                            }
                            break;
                          case FP_SUBNORMAL:
                            if (signbit(Fs1)) {
                                Rd = 1 << 2;
                            } else {
                                Rd = 1 << 5;
                            }
                            break;
                          case FP_NORMAL:
                            if (signbit(Fs1)) {
                                Rd = 1 << 1;
                            } else {
                                Rd = 1 << 6;
                            }
                            break;
                          default:
                            panic("Unknown classification for operand.");
                            break;
                        }
                    ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_s_x(['\n                    Fd_bits = (uint64_t)Rs1_uw;\n                ', 'FloatCvtOp'],{})

    Fault Fmv_s_x::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    Fd_bits = (uint64_t)Rs1;
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// FPROp::fmv_d_x(['\n                    Fd_bits = Rs1;\n                ', 'FloatCvtOp'],{})

    Fault Fmv_d_x::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        if (fault == NoFault) {
            switch (ROUND_MODE) {
            case 0x0:
                std::fesetround(FE_TONEAREST);
                break;
            case 0x1:
                std::fesetround(FE_TOWARDZERO);
                break;
            case 0x2:
                std::fesetround(FE_DOWNWARD);
                break;
            case 0x3:
                std::fesetround(FE_UPWARD);
                break;
            case 0x4:
                // Round to nearest, ties to max magnitude not implemented
                fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                break;
            case 0x7: {
                uint8_t frm = xc->readMiscReg(MISCREG_FRM);
                switch (frm) {
                case 0x0:
                    std::fesetround(FE_TONEAREST);
                    break;
                case 0x1:
                    std::fesetround(FE_TOWARDZERO);
                    break;
                case 0x2:
                    std::fesetround(FE_DOWNWARD);
                    break;
                case 0x3:
                    std::fesetround(FE_UPWARD);
                    break;
                case 0x4:
                    // Round to nearest, ties to max magnitude not implemented
                    fault = make_shared<IllegalFrmFault>(ROUND_MODE, machInst);
                    break;
                default:
                    fault = std::make_shared<IllegalFrmFault>(frm, machInst);
                    break;
                }
                break;
            }
            default:
                fault = std::make_shared<IllegalFrmFault>(ROUND_MODE,
                                                          machInst);
                break;
            }

            if (fault == NoFault) {
                MiscReg FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
                std::feclearexcept(FE_ALL_EXCEPT);
                
                    Fd_bits = Rs1;
                ;
                if (std::fetestexcept(FE_INEXACT)) {
                    FFLAGS |= FloatInexact;
                }
                if (std::fetestexcept(FE_UNDERFLOW)) {
                    FFLAGS |= FloatUnderflow;
                }
                if (std::fetestexcept(FE_OVERFLOW)) {
                    FFLAGS |= FloatOverflow;
                }
                if (std::fetestexcept(FE_DIVBYZERO)) {
                    FFLAGS |= FloatDivZero;
                }
                if (std::fetestexcept(FE_INVALID)) {
                    FFLAGS |= FloatInvalid;
                }
                xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);
            }

            if (fault == NoFault) {
                
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// BOp::beq(['\n                    if (Rs1 == Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Beq::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                    if (Rs1 == Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    Beq::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Beq::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_srcRegIdx[0],_srcRegIdx[1]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::bne(['\n                    if (Rs1 != Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Bne::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                    if (Rs1 != Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    Bne::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Bne::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_srcRegIdx[0],_srcRegIdx[1]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::blt(['\n                    if (Rs1_sd < Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Blt::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rs1 = 0;
int64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                    if (Rs1 < Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    Blt::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Blt::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_srcRegIdx[0],_srcRegIdx[1]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::bge(['\n                    if (Rs1_sd >= Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Bge::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        int64_t Rs1 = 0;
int64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                    if (Rs1 >= Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    Bge::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Bge::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_srcRegIdx[0],_srcRegIdx[1]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::bltu(['\n                    if (Rs1 < Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Bltu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                    if (Rs1 < Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    Bltu::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Bltu::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_srcRegIdx[0],_srcRegIdx[1]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::bgeu(['\n                    if (Rs1 >= Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Bgeu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                    if (Rs1 >= Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    Bgeu::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Bgeu::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_srcRegIdx[0],_srcRegIdx[1]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// Jump::jalr((['\n                Rd = NPC;\n                NPC = (imm + Rs1) & (~0x1);\n            ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    Jalr::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                Rd = NPC;
                NPC = (imm + Rs1) & (~0x1);
            ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }__parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    Jalr::branchTarget(ThreadContext *tc) const
    {
        PCState pc = tc->pcState();
        pc.set((tc->readIntReg(_srcRegIdx[0].index()) + imm)&~0x1);
        return pc;
    }

    std::string
    Jalr::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0],_srcRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// JOp::jal((['\n            Rd = NPC;\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    Jal::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
            Rd = NPC;
            NPC = PC + imm;
        ;
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }__parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

    RiscvISA::PCState
    Jal::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Jal::generateDisassembly(Addr pc,
            const SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {_destRegIdx[0]};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// SystemOp::ecall(['\n                        fault = make_shared<SyscallFault>(\n                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall', 'No_OpClass'],{})

    Fault
    Ecall::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        ;
        ;
        if (fault == NoFault) {
            
                        fault = make_shared<SyscallFault>(
                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));
                    ;
            if (fault == NoFault) {
                ;
            }
        }
        return fault;
    }

// SystemOp::ebreak(['\n                        fault = make_shared<BreakpointFault>(xc->pcState());\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Ebreak::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        ;
        ;
        if (fault == NoFault) {
            
                        fault = make_shared<BreakpointFault>(xc->pcState());
                    ;
            if (fault == NoFault) {
                ;
            }
        }
        return fault;
    }

// SystemOp::uret(['\n                        STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                        status.uie = status.upie;\n                        status.upie = 1;\n                        xc->setMiscReg(MISCREG_STATUS, status);\n                        NPC = xc->readMiscReg(MISCREG_UEPC);\n                    ', 'IsReturn'],{})

    Fault
    Uret::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
;
        if (fault == NoFault) {
            
                        STATUS status = xc->readMiscReg(MISCREG_STATUS);
                        status.uie = status.upie;
                        status.upie = 1;
                        xc->setMiscReg(MISCREG_STATUS, status);
                        NPC = xc->readMiscReg(MISCREG_UEPC);
                    ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

// SystemOp::sret(['\n                        if (xc->readMiscReg(MISCREG_PRV) == PRV_U) {\n                            fault = make_shared<IllegalInstFault>(\n                                        "sret in user mode", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.spp);\n                            status.sie = status.spie;\n                            status.spie = 1;\n                            status.spp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_SEPC);\n                        }\n                    ', 'IsReturn'],{})

    Fault
    Sret::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                        if (xc->readMiscReg(MISCREG_PRV) == PRV_U) {
                            fault = make_shared<IllegalInstFault>(
                                        "sret in user mode", machInst);
                            NPC = NPC;
                        } else {
                            STATUS status = xc->readMiscReg(MISCREG_STATUS);
                            xc->setMiscReg(MISCREG_PRV, status.spp);
                            status.sie = status.spie;
                            status.spie = 1;
                            status.spp = PRV_U;
                            xc->setMiscReg(MISCREG_STATUS, status);
                            NPC = xc->readMiscReg(MISCREG_SEPC);
                        }
                    ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

// SystemOp::mret(['\n                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {\n                            fault = make_shared<IllegalInstFault>(\n                                        "mret at lower privilege", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.mpp);\n                            status.mie = status.mpie;\n                            status.mpie = 1;\n                            status.mpp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_MEPC);\n                        }\n                    ', 'IsReturn'],{})

    Fault
    Mret::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
NPC = __parserAutoPCState.npc();
;
        if (fault == NoFault) {
            
                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {
                            fault = make_shared<IllegalInstFault>(
                                        "mret at lower privilege", machInst);
                            NPC = NPC;
                        } else {
                            STATUS status = xc->readMiscReg(MISCREG_STATUS);
                            xc->setMiscReg(MISCREG_PRV, status.mpp);
                            status.mie = status.mpie;
                            status.mpie = 1;
                            status.mpp = PRV_U;
                            xc->setMiscReg(MISCREG_STATUS, status);
                            NPC = xc->readMiscReg(MISCREG_MEPC);
                        }
                    ;
            if (fault == NoFault) {
                __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// CSROp::csrrw(['\n                    Rd = data;\n                    data = Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        MiscReg data, olddata;
        switch (csr) {
          case CSR_FCSR:
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
            break;
          default:
            if (CSRData.find(csr) != CSRData.end()) {
                olddata = xc->readMiscReg(CSRData.at(csr).physIndex);
            } else {
                std::string error = csprintf("Illegal CSR index %#x\n", csr);
                fault = make_shared<IllegalInstFault>(error, machInst);
                olddata = 0;
            }
            break;
        }
        auto mask = CSRMasks.find(csr);
        if (mask != CSRMasks.end())
            olddata &= mask->second;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", CSRData.at(csr).name,
                olddata);
        data = olddata;

        if (fault == NoFault) {
            
                    Rd = data;
                    data = Rs1;
                ;
            if (fault == NoFault) {
                if (mask != CSRMasks.end())
                    data &= mask->second;
                if (data != olddata) {
                    if (bits(csr, 11, 10) == 0x3) {
                        std::string error = csprintf("CSR %s is read-only\n",
                                                     CSRData.at(csr).name);
                        fault = make_shared<IllegalInstFault>(error, machInst);
                    } else {
                        DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n", data,
                                CSRData.at(csr).name);
                        switch (csr) {
                          case CSR_FCSR:
                            xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                            xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                            break;
                          default:
                            xc->setMiscReg(CSRData.at(csr).physIndex, data);
                            break;
                        }
                    }
                }
            }
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// CSROp::csrrs(['\n                    Rd = data;\n                    data |= Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrs::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        MiscReg data, olddata;
        switch (csr) {
          case CSR_FCSR:
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
            break;
          default:
            if (CSRData.find(csr) != CSRData.end()) {
                olddata = xc->readMiscReg(CSRData.at(csr).physIndex);
            } else {
                std::string error = csprintf("Illegal CSR index %#x\n", csr);
                fault = make_shared<IllegalInstFault>(error, machInst);
                olddata = 0;
            }
            break;
        }
        auto mask = CSRMasks.find(csr);
        if (mask != CSRMasks.end())
            olddata &= mask->second;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", CSRData.at(csr).name,
                olddata);
        data = olddata;

        if (fault == NoFault) {
            
                    Rd = data;
                    data |= Rs1;
                ;
            if (fault == NoFault) {
                if (mask != CSRMasks.end())
                    data &= mask->second;
                if (data != olddata) {
                    if (bits(csr, 11, 10) == 0x3) {
                        std::string error = csprintf("CSR %s is read-only\n",
                                                     CSRData.at(csr).name);
                        fault = make_shared<IllegalInstFault>(error, machInst);
                    } else {
                        DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n", data,
                                CSRData.at(csr).name);
                        switch (csr) {
                          case CSR_FCSR:
                            xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                            xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                            break;
                          default:
                            xc->setMiscReg(CSRData.at(csr).physIndex, data);
                            break;
                        }
                    }
                }
            }
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// CSROp::csrrc(['\n                    Rd = data;\n                    data &= ~Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrc::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        MiscReg data, olddata;
        switch (csr) {
          case CSR_FCSR:
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
            break;
          default:
            if (CSRData.find(csr) != CSRData.end()) {
                olddata = xc->readMiscReg(CSRData.at(csr).physIndex);
            } else {
                std::string error = csprintf("Illegal CSR index %#x\n", csr);
                fault = make_shared<IllegalInstFault>(error, machInst);
                olddata = 0;
            }
            break;
        }
        auto mask = CSRMasks.find(csr);
        if (mask != CSRMasks.end())
            olddata &= mask->second;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", CSRData.at(csr).name,
                olddata);
        data = olddata;

        if (fault == NoFault) {
            
                    Rd = data;
                    data &= ~Rs1;
                ;
            if (fault == NoFault) {
                if (mask != CSRMasks.end())
                    data &= mask->second;
                if (data != olddata) {
                    if (bits(csr, 11, 10) == 0x3) {
                        std::string error = csprintf("CSR %s is read-only\n",
                                                     CSRData.at(csr).name);
                        fault = make_shared<IllegalInstFault>(error, machInst);
                    } else {
                        DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n", data,
                                CSRData.at(csr).name);
                        switch (csr) {
                          case CSR_FCSR:
                            xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                            xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                            break;
                          default:
                            xc->setMiscReg(CSRData.at(csr).physIndex, data);
                            break;
                        }
                    }
                }
            }
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// CSROp::csrrwi(['\n                    Rd = data;\n                    data = uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrwi::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
;
        ;

        MiscReg data, olddata;
        switch (csr) {
          case CSR_FCSR:
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
            break;
          default:
            if (CSRData.find(csr) != CSRData.end()) {
                olddata = xc->readMiscReg(CSRData.at(csr).physIndex);
            } else {
                std::string error = csprintf("Illegal CSR index %#x\n", csr);
                fault = make_shared<IllegalInstFault>(error, machInst);
                olddata = 0;
            }
            break;
        }
        auto mask = CSRMasks.find(csr);
        if (mask != CSRMasks.end())
            olddata &= mask->second;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", CSRData.at(csr).name,
                olddata);
        data = olddata;

        if (fault == NoFault) {
            
                    Rd = data;
                    data = uimm;
                ;
            if (fault == NoFault) {
                if (mask != CSRMasks.end())
                    data &= mask->second;
                if (data != olddata) {
                    if (bits(csr, 11, 10) == 0x3) {
                        std::string error = csprintf("CSR %s is read-only\n",
                                                     CSRData.at(csr).name);
                        fault = make_shared<IllegalInstFault>(error, machInst);
                    } else {
                        DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n", data,
                                CSRData.at(csr).name);
                        switch (csr) {
                          case CSR_FCSR:
                            xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                            xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                            break;
                          default:
                            xc->setMiscReg(CSRData.at(csr).physIndex, data);
                            break;
                        }
                    }
                }
            }
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// CSROp::csrrsi(['\n                    Rd = data;\n                    data |= uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrsi::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
;
        ;

        MiscReg data, olddata;
        switch (csr) {
          case CSR_FCSR:
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
            break;
          default:
            if (CSRData.find(csr) != CSRData.end()) {
                olddata = xc->readMiscReg(CSRData.at(csr).physIndex);
            } else {
                std::string error = csprintf("Illegal CSR index %#x\n", csr);
                fault = make_shared<IllegalInstFault>(error, machInst);
                olddata = 0;
            }
            break;
        }
        auto mask = CSRMasks.find(csr);
        if (mask != CSRMasks.end())
            olddata &= mask->second;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", CSRData.at(csr).name,
                olddata);
        data = olddata;

        if (fault == NoFault) {
            
                    Rd = data;
                    data |= uimm;
                ;
            if (fault == NoFault) {
                if (mask != CSRMasks.end())
                    data &= mask->second;
                if (data != olddata) {
                    if (bits(csr, 11, 10) == 0x3) {
                        std::string error = csprintf("CSR %s is read-only\n",
                                                     CSRData.at(csr).name);
                        fault = make_shared<IllegalInstFault>(error, machInst);
                    } else {
                        DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n", data,
                                CSRData.at(csr).name);
                        switch (csr) {
                          case CSR_FCSR:
                            xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                            xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                            break;
                          default:
                            xc->setMiscReg(CSRData.at(csr).physIndex, data);
                            break;
                        }
                    }
                }
            }
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// CSROp::csrrci(['\n                    Rd = data;\n                    data &= ~uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrci::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Fault fault = NoFault;

        uint64_t Rd = 0;
;
        ;

        MiscReg data, olddata;
        switch (csr) {
          case CSR_FCSR:
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
            break;
          default:
            if (CSRData.find(csr) != CSRData.end()) {
                olddata = xc->readMiscReg(CSRData.at(csr).physIndex);
            } else {
                std::string error = csprintf("Illegal CSR index %#x\n", csr);
                fault = make_shared<IllegalInstFault>(error, machInst);
                olddata = 0;
            }
            break;
        }
        auto mask = CSRMasks.find(csr);
        if (mask != CSRMasks.end())
            olddata &= mask->second;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", CSRData.at(csr).name,
                olddata);
        data = olddata;

        if (fault == NoFault) {
            
                    Rd = data;
                    data &= ~uimm;
                ;
            if (fault == NoFault) {
                if (mask != CSRMasks.end())
                    data &= mask->second;
                if (data != olddata) {
                    if (bits(csr, 11, 10) == 0x3) {
                        std::string error = csprintf("CSR %s is read-only\n",
                                                     CSRData.at(csr).name);
                        fault = make_shared<IllegalInstFault>(error, machInst);
                    } else {
                        DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n", data,
                                CSRData.at(csr).name);
                        switch (csr) {
                          case CSR_FCSR:
                            xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                            xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                            break;
                          default:
                            xc->setMiscReg(CSRData.at(csr).physIndex, data);
                            break;
                        }
                    }
                }
            }
            if (fault == NoFault) {
                
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
            }
        }
        return fault;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

#endif
