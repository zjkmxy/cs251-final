// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   riscv/isa/main.isa

#undef QUADRANT
#define QUADRANT	bits(machInst,  1,  0)
#undef OPCODE
#define OPCODE	bits(machInst,  6,  2)
#undef ALL
#define ALL	bits(machInst, 31,  0)
#undef RD
#define RD	bits(machInst, 11,  7)
#undef FUNCT3
#define FUNCT3	bits(machInst, 14, 12)
#undef RS1
#define RS1	bits(machInst, 19, 15)
#undef RS2
#define RS2	bits(machInst, 24, 20)
#undef FUNCT7
#define FUNCT7	bits(machInst, 31, 25)
#undef SRTYPE
#define SRTYPE	bits(machInst, 30, 30)
#undef SHAMT5
#define SHAMT5	bits(machInst, 24, 20)
#undef SHAMT6
#define SHAMT6	bits(machInst, 25, 20)
#undef IMM12
#define IMM12	bits(machInst, 31, 20)
#undef IMM5
#define IMM5	bits(machInst, 11,  7)
#undef IMM7
#define IMM7	bits(machInst, 31, 25)
#undef IMM20
#define IMM20	bits(machInst, 31, 12)
#undef BIMM12BIT11
#define BIMM12BIT11	bits(machInst,  7,  7)
#undef BIMM12BITS4TO1
#define BIMM12BITS4TO1	bits(machInst, 11,  8)
#undef BIMM12BITS10TO5
#define BIMM12BITS10TO5	bits(machInst, 30, 25)
#undef IMMSIGN
#define IMMSIGN	bits(machInst, 31, 31)
#undef UJIMMBITS10TO1
#define UJIMMBITS10TO1	bits(machInst, 30, 21)
#undef UJIMMBIT11
#define UJIMMBIT11	bits(machInst, 20, 20)
#undef UJIMMBITS19TO12
#define UJIMMBITS19TO12	bits(machInst, 19, 12)
#undef FUNCT12
#define FUNCT12	bits(machInst, 31, 20)
#undef CSRIMM
#define CSRIMM	bits(machInst, 19, 15)
#undef FD
#define FD	bits(machInst, 11,  7)
#undef FS1
#define FS1	bits(machInst, 19, 15)
#undef FS2
#define FS2	bits(machInst, 24, 20)
#undef FS3
#define FS3	bits(machInst, 31, 27)
#undef ROUND_MODE
#define ROUND_MODE	bits(machInst, 14, 12)
#undef CONV_SGN
#define CONV_SGN	bits(machInst, 24, 20)
#undef FUNCT2
#define FUNCT2	bits(machInst, 26, 25)
#undef AMOFUNCT
#define AMOFUNCT	bits(machInst, 31, 27)
#undef AQ
#define AQ	bits(machInst, 26, 26)
#undef RL
#define RL	bits(machInst, 25, 25)
#undef COPCODE
#define COPCODE	bits(machInst, 15, 13)
#undef CFUNCT1
#define CFUNCT1	bits(machInst, 12, 12)
#undef CFUNCT2HIGH
#define CFUNCT2HIGH	bits(machInst, 11, 10)
#undef CFUNCT2LOW
#define CFUNCT2LOW	bits(machInst,  6,  5)
#undef RC1
#define RC1	bits(machInst, 11,  7)
#undef RC2
#define RC2	bits(machInst,  6,  2)
#undef RP1
#define RP1	bits(machInst,  9,  7)
#undef RP2
#define RP2	bits(machInst,  4,  2)
#undef FC1
#define FC1	bits(machInst, 11,  7)
#undef FC2
#define FC2	bits(machInst,  6,  2)
#undef FP2
#define FP2	bits(machInst,  4,  2)
#undef CJUMPIMM
#define CJUMPIMM	bits(machInst, 12,  2)
#undef CIMM8
#define CIMM8	bits(machInst, 12,  5)
#undef CIMM6
#define CIMM6	bits(machInst, 12,  7)
#undef CIMM5
#define CIMM5	bits(machInst,  6,  2)
#undef CIMM3
#define CIMM3	bits(machInst, 12, 10)
#undef CIMM2
#define CIMM2	bits(machInst,  6,  5)
#undef CIMM1
#define CIMM1	bits(machInst, 12, 12)

// CIOp::c_addi4spn((['\n            imm = CIMM8<1:1> << 2 |\n                  CIMM8<0:0> << 3 |\n                  CIMM8<7:6> << 4 |\n                  CIMM8<5:2> << 6;\n        ', '\n            if (machInst == 0)\n                fault = make_shared<IllegalInstFault>("zero instruction",\n                                                      machInst);\n            Rp2 = sp + imm;\n        ', 'uint64_t'], {}))

    //
    // Static instruction class for "c_addi4spn".
    //
    class C_addi4spn : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        C_addi4spn(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CompressedLoad::c_fld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Fp2_bits = Mem;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_fld".
     */
    class C_fld : public Load
    {
      public:
        /// Constructor.
        C_fld(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedLoad::c_lw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Rp2_sd = Mem_sw;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_lw".
     */
    class C_lw : public Load
    {
      public:
        /// Constructor.
        C_lw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedLoad::c_ld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Rp2_sd = Mem_sd;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_ld".
     */
    class C_ld : public Load
    {
      public:
        /// Constructor.
        C_ld(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_fsd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Mem = Fp2_bits;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_fsd".
     */
    class C_fsd : public Store
    {
      public:
        /// Constructor.
        C_fsd(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_sw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Mem_uw = Rp2_uw;\n            '],{'ea_code': '\n                EA = Rp1 + offset;\n            '})

    /**
     * Static instruction class for "c_sw".
     */
    class C_sw : public Store
    {
      public:
        /// Constructor.
        C_sw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_sd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                    Mem_ud = Rp2_ud;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_sd".
     */
    class C_sd : public Store
    {
      public:
        /// Constructor.
        C_sd(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// CIOp::c_addi(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if ((RC1 == 0) != (imm == 0)) {\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    } else // imm == 0\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                }\n                Rc1_sd = Rc1_sd + imm;\n            '],{})

    //
    // Static instruction class for "c_addi".
    //
    class C_addi : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_addi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CIOp::c_addiw(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = (int32_t)Rc1_sd + imm;\n            '],{})

    //
    // Static instruction class for "c_addiw".
    //
    class C_addiw : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_addiw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CIOp::c_li(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = imm;\n            '],{})

    //
    // Static instruction class for "c_li".
    //
    class C_li : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_li(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CIOp::c_addi16sp(['\n                    imm = CIMM5<4:4> << 4 |\n                          CIMM5<0:0> << 5 |\n                          CIMM5<3:3> << 6 |\n                          CIMM5<2:1> << 7;\n                    if (CIMM1 > 0)\n                        imm |= ~((int64_t)0x1FF);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    sp_sd = sp_sd + imm;\n                '],{})

    //
    // Static instruction class for "c_addi16sp".
    //
    class C_addi16sp : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_addi16sp(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CIOp::c_lui(['\n                    imm = CIMM5 << 12;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1FFFF);\n                ', '\n                    if (RC1 == 0 || RC1 == 2) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rc1_sd = imm;\n                '],{})

    //
    // Static instruction class for "c_lui".
    //
    class C_lui : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_lui(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CIOp::c_srli(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rp1 = Rp1 >> imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "c_srli".
    //
    class C_srli : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        C_srli(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CIOp::c_srai(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rp1_sd = Rp1_sd >> imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "c_srai".
    //
    class C_srai : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        C_srai(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CIOp::c_andi(['\n                    imm = CIMM5;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1F);\n                ', '\n                    Rp1 = Rp1 & imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "c_andi".
    //
    class C_andi : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        C_andi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// ROp::c_sub(['\n                            Rp1 = Rp1 - Rp2;\n                        '],{})

    //
    // Static instruction class for "c_sub".
    //
    class C_sub : public RegOp
    {
      public:
        /// Constructor.
        C_sub(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::c_xor(['\n                            Rp1 = Rp1 ^ Rp2;\n                        '],{})

    //
    // Static instruction class for "c_xor".
    //
    class C_xor : public RegOp
    {
      public:
        /// Constructor.
        C_xor(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::c_or(['\n                            Rp1 = Rp1 | Rp2;\n                        '],{})

    //
    // Static instruction class for "c_or".
    //
    class C_or : public RegOp
    {
      public:
        /// Constructor.
        C_or(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::c_and(['\n                            Rp1 = Rp1 & Rp2;\n                        '],{})

    //
    // Static instruction class for "c_and".
    //
    class C_and : public RegOp
    {
      public:
        /// Constructor.
        C_and(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::c_subw(['\n                            Rp1_sd = (int32_t)Rp1_sd - Rp2_sw;\n                        '],{})

    //
    // Static instruction class for "c_subw".
    //
    class C_subw : public RegOp
    {
      public:
        /// Constructor.
        C_subw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::c_addw(['\n                            Rp1_sd = (int32_t)Rp1_sd + Rp2_sw;\n                        '],{})

    //
    // Static instruction class for "c_addw".
    //
    class C_addw : public RegOp
    {
      public:
        /// Constructor.
        C_addw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// JOp::c_j((['\n            int64_t offset = CJUMPIMM<3:1> << 1 |\n                             CJUMPIMM<9:9> << 4 |\n                             CJUMPIMM<0:0> << 5 |\n                             CJUMPIMM<5:5> << 6 |\n                             CJUMPIMM<4:4> << 7 |\n                             CJUMPIMM<8:7> << 8 |\n                             CJUMPIMM<6:6> << 10;\n            if (CJUMPIMM<10:10> > 0)\n                offset |= ~((int64_t)0x7FF);\n            NPC = PC + offset;\n        ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "c_j".
    //
    class C_j : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_j(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// CBOp::c_beqz(['\n                if (Rp1 == 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "c_beqz".
    //
    class C_beqz : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_beqz(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// CBOp::c_bnez(['\n                if (Rp1 != 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "c_bnez".
    //
    class C_bnez : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_bnez(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// Unknown::unknown(([], {}))

// CIOp::c_slli((['\n            imm = CIMM5 | (CIMM1 << 5);\n        ', '\n            if (imm == 0) {\n                fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                      machInst);\n            }\n            if (RC1 == 0) {\n                fault = make_shared<IllegalInstFault>("source reg x0",\n                                                      machInst);\n            }\n            Rc1 = Rc1 << imm;\n        ', 'uint64_t'], {}))

    //
    // Static instruction class for "c_slli".
    //
    class C_slli : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        C_slli(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// CompressedLoad::c_fldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                Fc1_bits = Mem;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_fldsp".
     */
    class C_fldsp : public Load
    {
      public:
        /// Constructor.
        C_fldsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedLoad::c_lwsp(['\n                offset = CIMM5<4:2> << 2 |\n                         CIMM1 << 5 |\n                         CIMM5<1:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = Mem_sw;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_lwsp".
     */
    class C_lwsp : public Load
    {
      public:
        /// Constructor.
        C_lwsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedLoad::c_ldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = Mem_sd;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_ldsp".
     */
    class C_ldsp : public Load
    {
      public:
        /// Constructor.
        C_ldsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Jump::c_jr((['\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    NPC = Rc1;\n                ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "c_jr".
    //
    class C_jr : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_jr(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(ThreadContext *tc) const override;

        using StaticInst::branchTarget;
    };

// CROp::c_mv((['\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    Rc1 = Rc2;\n                '], {}))

    //
    // Static instruction class for "c_mv".
    //
    class C_mv : public CompRegOp
    {
      public:
        /// Constructor.
        C_mv(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CompRegOp::generateDisassembly;
    };

// SystemOp::c_ebreak((['\n                    if (RC2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    fault = make_shared<BreakpointFault>(xc->pcState());\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'], {}))

    //
    // Static instruction class for "c_ebreak".
    //
    class C_ebreak : public SystemOp
    {
      public:
        /// Constructor.
        C_ebreak(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// Jump::c_jalr((['\n                        if (RC1 == 0) {\n                            fault = make_shared<IllegalInstFault>\n                                                        ("source reg x0",\n                                                         machInst);\n                        }\n                        ra = NPC;\n                        NPC = Rc1;\n                    ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "c_jalr".
    //
    class C_jalr : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        C_jalr(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(ThreadContext *tc) const override;

        using StaticInst::branchTarget;
    };

// ROp::c_add((['\n                        Rc1_sd = Rc1_sd + Rc2_sd;\n                    '], {}))

    //
    // Static instruction class for "c_add".
    //
    class C_add : public RegOp
    {
      public:
        /// Constructor.
        C_add(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// CompressedStore::c_fsdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem_ud = Fc2_bits;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_fsdsp".
     */
    class C_fsdsp : public Store
    {
      public:
        /// Constructor.
        C_fsdsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_swsp(['\n                offset = CIMM6<5:2> << 2 |\n                         CIMM6<1:0> << 6;\n            ', '\n                Mem_uw = Rc2_uw;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_swsp".
     */
    class C_swsp : public Store
    {
      public:
        /// Constructor.
        C_swsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_sdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem = Rc2;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_sdsp".
     */
    class C_sdsp : public Store
    {
      public:
        /// Constructor.
        C_sdsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// Load::lb(['\n                    Rd_sd = Mem_sb;\n                '],{})

    /**
     * Static instruction class for "lb".
     */
    class Lb : public Load
    {
      public:
        /// Constructor.
        Lb(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lh(['\n                    Rd_sd = Mem_sh;\n                '],{})

    /**
     * Static instruction class for "lh".
     */
    class Lh : public Load
    {
      public:
        /// Constructor.
        Lh(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lw(['\n                    Rd_sd = Mem_sw;\n                '],{})

    /**
     * Static instruction class for "lw".
     */
    class Lw : public Load
    {
      public:
        /// Constructor.
        Lw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::ld(['\n                    Rd_sd = Mem_sd;\n                '],{})

    /**
     * Static instruction class for "ld".
     */
    class Ld : public Load
    {
      public:
        /// Constructor.
        Ld(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lbu(['\n                    Rd = Mem_ub;\n                '],{})

    /**
     * Static instruction class for "lbu".
     */
    class Lbu : public Load
    {
      public:
        /// Constructor.
        Lbu(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lhu(['\n                    Rd = Mem_uh;\n                '],{})

    /**
     * Static instruction class for "lhu".
     */
    class Lhu : public Load
    {
      public:
        /// Constructor.
        Lhu(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lwu(['\n                    Rd = Mem_uw;\n                '],{})

    /**
     * Static instruction class for "lwu".
     */
    class Lwu : public Load
    {
      public:
        /// Constructor.
        Lwu(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// Load::flw(['\n                    Fd_bits = (uint64_t)Mem_uw;\n                '],{'inst_flags': 'FloatMemReadOp'})

    /**
     * Static instruction class for "flw".
     */
    class Flw : public Load
    {
      public:
        /// Constructor.
        Flw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::fld(['\n                    Fd_bits = Mem;\n                '],{'inst_flags': 'FloatMemReadOp'})

    /**
     * Static instruction class for "fld".
     */
    class Fld : public Load
    {
      public:
        /// Constructor.
        Fld(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// IOp::fence(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsMemBarrier', 'No_OpClass'],{})

    //
    // Static instruction class for "fence".
    //
    class Fence : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        Fence(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::fence_i(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    //
    // Static instruction class for "fence_i".
    //
    class Fence_i : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        Fence_i(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// IOp::addi(['\n                    Rd_sd = Rs1_sd + imm;\n                '],{})

    //
    // Static instruction class for "addi".
    //
    class Addi : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Addi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::slli(['\n                    Rd = Rs1 << SHAMT6;\n                '],{})

    //
    // Static instruction class for "slli".
    //
    class Slli : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Slli(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::slti(['\n                    Rd = (Rs1_sd < imm) ? 1 : 0;\n                '],{})

    //
    // Static instruction class for "slti".
    //
    class Slti : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Slti(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::sltiu(['\n                    Rd = (Rs1 < imm) ? 1 : 0;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "sltiu".
    //
    class Sltiu : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        Sltiu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::xori(['\n                    Rd = Rs1 ^ imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "xori".
    //
    class Xori : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        Xori(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::srli(['\n                        Rd = Rs1 >> SHAMT6;\n                    '],{})

    //
    // Static instruction class for "srli".
    //
    class Srli : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Srli(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::srai(['\n                        Rd_sd = Rs1_sd >> SHAMT6;\n                    '],{})

    //
    // Static instruction class for "srai".
    //
    class Srai : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Srai(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// IOp::ori(['\n                    Rd = Rs1 | imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "ori".
    //
    class Ori : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        Ori(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::andi(['\n                    Rd = Rs1 & imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "andi".
    //
    class Andi : public ImmOp<uint64_t>
    {
      public:
        /// Constructor.
        Andi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// UOp::auipc((['\n            Rd = PC + imm;\n        '], {}))

    //
    // Static instruction class for "auipc".
    //
    class Auipc : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Auipc(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::addiw(['\n                    Rd_sd = Rs1_sw + imm;\n                ', 'int32_t'],{})

    //
    // Static instruction class for "addiw".
    //
    class Addiw : public ImmOp<int32_t>
    {
      public:
        /// Constructor.
        Addiw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::slliw(['\n                    Rd_sd = Rs1_sw << SHAMT5;\n                '],{})

    //
    // Static instruction class for "slliw".
    //
    class Slliw : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Slliw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::srliw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> SHAMT5);\n                    '],{})

    //
    // Static instruction class for "srliw".
    //
    class Srliw : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Srliw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// IOp::sraiw(['\n                        Rd_sd = Rs1_sw >> SHAMT5;\n                    '],{})

    //
    // Static instruction class for "sraiw".
    //
    class Sraiw : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Sraiw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Store::sb(['\n                    Mem_ub = Rs2_ub;\n                '],{})

    /**
     * Static instruction class for "sb".
     */
    class Sb : public Store
    {
      public:
        /// Constructor.
        Sb(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Store::sh(['\n                    Mem_uh = Rs2_uh;\n                '],{})

    /**
     * Static instruction class for "sh".
     */
    class Sh : public Store
    {
      public:
        /// Constructor.
        Sh(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Store::sw(['\n                    Mem_uw = Rs2_uw;\n                '],{})

    /**
     * Static instruction class for "sw".
     */
    class Sw : public Store
    {
      public:
        /// Constructor.
        Sw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Store::sd(['\n                    Mem_ud = Rs2_ud;\n                '],{})

    /**
     * Static instruction class for "sd".
     */
    class Sd : public Store
    {
      public:
        /// Constructor.
        Sd(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// Store::fsw(['\n                    Mem_uw = (uint32_t)Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    /**
     * Static instruction class for "fsw".
     */
    class Fsw : public Store
    {
      public:
        /// Constructor.
        Fsw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Store::fsd(['\n                    Mem_ud = Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    /**
     * Static instruction class for "fsd".
     */
    class Fsd : public Store
    {
      public:
        /// Constructor.
        Fsd(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// LoadReserved::lr_w((['\n                    Rd_sd = Mem_sw;\n                '], {'mem_flags': 'LLSC'}))

    /**
     * Static instruction class for "lr_w".
     */
    class Lr_w : public LoadReserved
    {
      public:
        /// Constructor.
        Lr_w(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// StoreCond::sc_w((['\n                    Mem_uw = Rs2_uw;\n                ', '\n                    Rd = result;\n                '], {'mem_flags': 'LLSC', 'inst_flags': 'IsStoreConditional'}))

    /**
     * Static instruction class for "sc_w".
     */
    class Sc_w : public StoreCond
    {
      public:
        /// Constructor.
        Sc_w(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoadd_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_sw + Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoadd_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoadd_w(ExtMachInst machInst);

    protected:

        class Amoadd_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoadd_wLoad(ExtMachInst machInst, Amoadd_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoadd_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoadd_wStore(ExtMachInst machInst, Amoadd_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amoswap_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoswap_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoswap_w(ExtMachInst machInst);

    protected:

        class Amoswap_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoswap_wLoad(ExtMachInst machInst, Amoswap_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoswap_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoswap_wStore(ExtMachInst machInst, Amoswap_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amoxor_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw^Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoxor_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoxor_w(ExtMachInst machInst);

    protected:

        class Amoxor_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoxor_wLoad(ExtMachInst machInst, Amoxor_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoxor_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoxor_wStore(ExtMachInst machInst, Amoxor_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amoor_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw | Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoor_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoor_w(ExtMachInst machInst);

    protected:

        class Amoor_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoor_wLoad(ExtMachInst machInst, Amoor_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoor_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoor_wStore(ExtMachInst machInst, Amoor_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amoand_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw&Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoand_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoand_w(ExtMachInst machInst);

    protected:

        class Amoand_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoand_wLoad(ExtMachInst machInst, Amoand_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoand_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoand_wStore(ExtMachInst machInst, Amoand_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amomin_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = min<int32_t>(Rs2_sw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomin_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amomin_w(ExtMachInst machInst);

    protected:

        class Amomin_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomin_wLoad(ExtMachInst machInst, Amomin_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amomin_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomin_wStore(ExtMachInst machInst, Amomin_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amomax_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = max<int32_t>(Rs2_sw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomax_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amomax_w(ExtMachInst machInst);

    protected:

        class Amomax_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomax_wLoad(ExtMachInst machInst, Amomax_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amomax_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomax_wStore(ExtMachInst machInst, Amomax_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amominu_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = min<uint32_t>(Rs2_uw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amominu_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amominu_w(ExtMachInst machInst);

    protected:

        class Amominu_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amominu_wLoad(ExtMachInst machInst, Amominu_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amominu_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amominu_wStore(ExtMachInst machInst, Amominu_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amomaxu_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = max<uint32_t>(Rs2_uw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomaxu_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amomaxu_w(ExtMachInst machInst);

    protected:

        class Amomaxu_wLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomaxu_wLoad(ExtMachInst machInst, Amomaxu_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amomaxu_wStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomaxu_wStore(ExtMachInst machInst, Amomaxu_w *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// Unknown::unknown(([], {}))

// LoadReserved::lr_d((['\n                    Rd_sd = Mem_sd;\n                '], {'mem_flags': 'LLSC'}))

    /**
     * Static instruction class for "lr_d".
     */
    class Lr_d : public LoadReserved
    {
      public:
        /// Constructor.
        Lr_d(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// StoreCond::sc_d((['\n                    Mem = Rs2;\n                ', '\n                    Rd = result;\n                '], {'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'}))

    /**
     * Static instruction class for "sc_d".
     */
    class Sc_d : public StoreCond
    {
      public:
        /// Constructor.
        Sc_d(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoadd_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = Rs2_sd + Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoadd_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoadd_d(ExtMachInst machInst);

    protected:

        class Amoadd_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoadd_dLoad(ExtMachInst machInst, Amoadd_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoadd_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoadd_dStore(ExtMachInst machInst, Amoadd_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amoswap_d(['Rt = Mem;', '\n                        Mem = Rs2;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoswap_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoswap_d(ExtMachInst machInst);

    protected:

        class Amoswap_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoswap_dLoad(ExtMachInst machInst, Amoswap_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoswap_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoswap_dStore(ExtMachInst machInst, Amoswap_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amoxor_d(['Rt = Mem;', '\n                        Mem = Rs2^Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoxor_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoxor_d(ExtMachInst machInst);

    protected:

        class Amoxor_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoxor_dLoad(ExtMachInst machInst, Amoxor_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoxor_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoxor_dStore(ExtMachInst machInst, Amoxor_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amoor_d(['Rt = Mem;', '\n                        Mem = Rs2 | Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoor_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoor_d(ExtMachInst machInst);

    protected:

        class Amoor_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoor_dLoad(ExtMachInst machInst, Amoor_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoor_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoor_dStore(ExtMachInst machInst, Amoor_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amoand_d(['Rt = Mem;', '\n                        Mem = Rs2&Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoand_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoand_d(ExtMachInst machInst);

    protected:

        class Amoand_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoand_dLoad(ExtMachInst machInst, Amoand_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amoand_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amoand_dStore(ExtMachInst machInst, Amoand_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amomin_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = min(Rs2_sd, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomin_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amomin_d(ExtMachInst machInst);

    protected:

        class Amomin_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomin_dLoad(ExtMachInst machInst, Amomin_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amomin_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomin_dStore(ExtMachInst machInst, Amomin_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amomax_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = max(Rs2_sd, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomax_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amomax_d(ExtMachInst machInst);

    protected:

        class Amomax_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomax_dLoad(ExtMachInst machInst, Amomax_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amomax_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomax_dStore(ExtMachInst machInst, Amomax_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amominu_d(['Rt = Mem;', '\n                        Mem = min(Rs2, Rt);\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amominu_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amominu_d(ExtMachInst machInst);

    protected:

        class Amominu_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amominu_dLoad(ExtMachInst machInst, Amominu_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amominu_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amominu_dStore(ExtMachInst machInst, Amominu_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// AtomicMemOp::amomaxu_d(['Rt = Mem;', '\n                        Mem = max(Rs2, Rt);\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomaxu_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amomaxu_d(ExtMachInst machInst);

    protected:

        class Amomaxu_dLoad : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomaxu_dLoad(ExtMachInst machInst, Amomaxu_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };

        class Amomaxu_dStore : public AtomicMemOpMicro
        {
          public:
            // Constructor
            Amomaxu_dStore(ExtMachInst machInst, Amomaxu_d *_p);

            Fault execute(ExecContext *, Trace::InstRecord *) const override;
            Fault initiateAcc(ExecContext *,
                              Trace::InstRecord *) const override;
            Fault completeAcc(PacketPtr, ExecContext *,
                              Trace::InstRecord *) const override;
        };
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// ROp::add(['\n                        Rd = Rs1_sd + Rs2_sd;\n                    '],{})

    //
    // Static instruction class for "add".
    //
    class Add : public RegOp
    {
      public:
        /// Constructor.
        Add(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mul(['\n                        Rd = Rs1_sd*Rs2_sd;\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mul".
    //
    class Mul : public RegOp
    {
      public:
        /// Constructor.
        Mul(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::sub(['\n                        Rd = Rs1_sd - Rs2_sd;\n                    '],{})

    //
    // Static instruction class for "sub".
    //
    class Sub : public RegOp
    {
      public:
        /// Constructor.
        Sub(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::sll(['\n                        Rd = Rs1 << Rs2<5:0>;\n                    '],{})

    //
    // Static instruction class for "sll".
    //
    class Sll : public RegOp
    {
      public:
        /// Constructor.
        Sll(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mulh(['\n                        bool negate = (Rs1_sd < 0) != (Rs2_sd < 0);\n\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)abs(Rs2_sd);\n                        uint64_t Rs2_hi = (uint64_t)abs(Rs2_sd) >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs2_lo*Rs1_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2_sd == 0 ? 1 : 0)\n                                    : res;\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mulh".
    //
    class Mulh : public RegOp
    {
      public:
        /// Constructor.
        Mulh(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::slt(['\n                        Rd = (Rs1_sd < Rs2_sd) ? 1 : 0;\n                    '],{})

    //
    // Static instruction class for "slt".
    //
    class Slt : public RegOp
    {
      public:
        /// Constructor.
        Slt(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mulhsu(['\n                        bool negate = Rs1_sd < 0;\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2 == 0 ? 1 : 0) : res;\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mulhsu".
    //
    class Mulhsu : public RegOp
    {
      public:
        /// Constructor.
        Mulhsu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::sltu(['\n                        Rd = (Rs1 < Rs2) ? 1 : 0;\n                    '],{})

    //
    // Static instruction class for "sltu".
    //
    class Sltu : public RegOp
    {
      public:
        /// Constructor.
        Sltu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mulhu(['\n                        uint64_t Rs1_lo = (uint32_t)Rs1;\n                        uint64_t Rs1_hi = Rs1 >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mulhu".
    //
    class Mulhu : public RegOp
    {
      public:
        /// Constructor.
        Mulhu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::xor(['\n                        Rd = Rs1 ^ Rs2;\n                    '],{})

    //
    // Static instruction class for "xor".
    //
    class Xor : public RegOp
    {
      public:
        /// Constructor.
        Xor(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::div(['\n                        if (Rs2_sd == 0) {\n                            Rd_sd = -1;\n                        } else if (Rs1_sd == numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                        } else {\n                            Rd_sd = Rs1_sd/Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "div".
    //
    class Div : public RegOp
    {
      public:
        /// Constructor.
        Div(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::srl(['\n                        Rd = Rs1 >> Rs2<5:0>;\n                    '],{})

    //
    // Static instruction class for "srl".
    //
    class Srl : public RegOp
    {
      public:
        /// Constructor.
        Srl(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::divu(['\n                        if (Rs2 == 0) {\n                            Rd = numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd = Rs1/Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "divu".
    //
    class Divu : public RegOp
    {
      public:
        /// Constructor.
        Divu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::sra(['\n                        Rd_sd = Rs1_sd >> Rs2<5:0>;\n                    '],{})

    //
    // Static instruction class for "sra".
    //
    class Sra : public RegOp
    {
      public:
        /// Constructor.
        Sra(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::or(['\n                        Rd = Rs1 | Rs2;\n                    '],{})

    //
    // Static instruction class for "or".
    //
    class Or : public RegOp
    {
      public:
        /// Constructor.
        Or(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::rem(['\n                        if (Rs2_sd == 0) {\n                            Rd = Rs1_sd;\n                        } else if (Rs1_sd == numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd = 0;\n                        } else {\n                            Rd = Rs1_sd%Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "rem".
    //
    class Rem : public RegOp
    {
      public:
        /// Constructor.
        Rem(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::and(['\n                        Rd = Rs1 & Rs2;\n                    '],{})

    //
    // Static instruction class for "and".
    //
    class And : public RegOp
    {
      public:
        /// Constructor.
        And(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::remu(['\n                        if (Rs2 == 0) {\n                            Rd = Rs1;\n                        } else {\n                            Rd = Rs1%Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "remu".
    //
    class Remu : public RegOp
    {
      public:
        /// Constructor.
        Remu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// UOp::lui((['\n            Rd = (uint64_t)imm;\n        '], {}))

    //
    // Static instruction class for "lui".
    //
    class Lui : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Lui(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const SymbolTable *symtab) const override;
    };

// ROp::addw(['\n                        Rd_sd = Rs1_sw + Rs2_sw;\n                    '],{})

    //
    // Static instruction class for "addw".
    //
    class Addw : public RegOp
    {
      public:
        /// Constructor.
        Addw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mulw(['\n                        Rd_sd = (int32_t)(Rs1_sw*Rs2_sw);\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mulw".
    //
    class Mulw : public RegOp
    {
      public:
        /// Constructor.
        Mulw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::subw(['\n                        Rd_sd = Rs1_sw - Rs2_sw;\n                    '],{})

    //
    // Static instruction class for "subw".
    //
    class Subw : public RegOp
    {
      public:
        /// Constructor.
        Subw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::sllw(['\n                    Rd_sd = Rs1_sw << Rs2<4:0>;\n                '],{})

    //
    // Static instruction class for "sllw".
    //
    class Sllw : public RegOp
    {
      public:
        /// Constructor.
        Sllw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::divw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = -1;\n                    } else if (Rs1_sw == numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = numeric_limits<int32_t>::min();\n                    } else {\n                        Rd_sd = Rs1_sw/Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    //
    // Static instruction class for "divw".
    //
    class Divw : public RegOp
    {
      public:
        /// Constructor.
        Divw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::srlw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> Rs2<4:0>);\n                    '],{})

    //
    // Static instruction class for "srlw".
    //
    class Srlw : public RegOp
    {
      public:
        /// Constructor.
        Srlw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::divuw(['\n                        if (Rs2_uw == 0) {\n                            Rd_sd = numeric_limits<IntReg>::max();\n                        } else {\n                            Rd_sd = (int32_t)(Rs1_uw/Rs2_uw);\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "divuw".
    //
    class Divuw : public RegOp
    {
      public:
        /// Constructor.
        Divuw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::sraw(['\n                        Rd_sd = Rs1_sw >> Rs2<4:0>;\n                    '],{})

    //
    // Static instruction class for "sraw".
    //
    class Sraw : public RegOp
    {
      public:
        /// Constructor.
        Sraw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::remw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = Rs1_sw;\n                    } else if (Rs1_sw == numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = 0;\n                    } else {\n                        Rd_sd = Rs1_sw%Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    //
    // Static instruction class for "remw".
    //
    class Remw : public RegOp
    {
      public:
        /// Constructor.
        Remw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::remuw(['\n                    if (Rs2_uw == 0) {\n                        Rd_sd = (int32_t)Rs1_uw;\n                    } else {\n                        Rd_sd = (int32_t)(Rs1_uw%Rs2_uw);\n                    }\n                ', 'IntDivOp'],{})

    //
    // Static instruction class for "remuw".
    //
    class Remuw : public RegOp
    {
      public:
        /// Constructor.
        Remuw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = fs3;\n                        }\n                    } else {\n                        fd = fs1*fs2 + fs3;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fmadd_s".
    //
    class Fmadd_s : public RegOp
    {
      public:
        /// Constructor.
        Fmadd_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else {\n                            Fd = Fs3;\n                        }\n                    } else {\n                        Fd = Fs1*Fs2 + Fs3;\n                    }\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fmadd_d".
    //
    class Fmadd_d : public RegOp
    {
      public:
        /// Constructor.
        Fmadd_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = -fs3;\n                        }\n                    } else {\n                        fd = fs1*fs2 - fs3;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fmsub_s".
    //
    class Fmsub_s : public RegOp
    {
      public:
        /// Constructor.
        Fmsub_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else {\n                            Fd = -Fs3;\n                        }\n                    } else {\n                        Fd = Fs1*Fs2 - Fs3;\n                    }\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fmsub_d".
    //
    class Fmsub_d : public RegOp
    {
      public:
        /// Constructor.
        Fmsub_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fnmsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = fs3;\n                        }\n                    } else {\n                        fd = -(fs1*fs2 - fs3);\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fnmsub_s".
    //
    class Fnmsub_s : public RegOp
    {
      public:
        /// Constructor.
        Fnmsub_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fnmsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2)\n                            || std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else {\n                            Fd = Fs3;\n                        }\n                    } else {\n                        Fd = -(Fs1*Fs2 - Fs3);\n                    }\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fnmsub_d".
    //
    class Fnmsub_d : public RegOp
    {
      public:
        /// Constructor.
        Fnmsub_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fnmadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = -fs3;\n                        }\n                    } else {\n                        fd = -(fs1*fs2 + fs3);\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fnmadd_s".
    //
    class Fnmadd_s : public RegOp
    {
      public:
        /// Constructor.
        Fnmadd_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fnmadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else {\n                            Fd = -Fs3;\n                        }\n                    } else {\n                        Fd = -(Fs1*Fs2 + Fs3);\n                    }\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fnmadd_d".
    //
    class Fnmadd_d : public RegOp
    {
      public:
        /// Constructor.
        Fnmadd_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1 + fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatAddOp'],{})

    //
    // Static instruction class for "fadd_s".
    //
    class Fadd_s : public RegOp
    {
      public:
        /// Constructor.
        Fadd_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1 + Fs2;\n                    }\n                ', 'FloatAddOp'],{})

    //
    // Static instruction class for "fadd_d".
    //
    class Fadd_d : public RegOp
    {
      public:
        /// Constructor.
        Fadd_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1 - fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatAddOp'],{})

    //
    // Static instruction class for "fsub_s".
    //
    class Fsub_s : public RegOp
    {
      public:
        /// Constructor.
        Fsub_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1 - Fs2;\n                    }\n                ', 'FloatAddOp'],{})

    //
    // Static instruction class for "fsub_d".
    //
    class Fsub_d : public RegOp
    {
      public:
        /// Constructor.
        Fsub_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmul_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1*fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultOp'],{})

    //
    // Static instruction class for "fmul_s".
    //
    class Fmul_s : public RegOp
    {
      public:
        /// Constructor.
        Fmul_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmul_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1*Fs2;\n                    }\n                ', 'FloatMultOp'],{})

    //
    // Static instruction class for "fmul_d".
    //
    class Fmul_d : public RegOp
    {
      public:
        /// Constructor.
        Fmul_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fdiv_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1/fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatDivOp'],{})

    //
    // Static instruction class for "fdiv_s".
    //
    class Fdiv_s : public RegOp
    {
      public:
        /// Constructor.
        Fdiv_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fdiv_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1/Fs2;\n                    }\n                ', 'FloatDivOp'],{})

    //
    // Static instruction class for "fdiv_d".
    //
    class Fdiv_d : public RegOp
    {
      public:
        /// Constructor.
        Fdiv_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnj_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = copysign(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnj_s".
    //
    class Fsgnj_s : public RegOp
    {
      public:
        /// Constructor.
        Fsgnj_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnjn_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = copysign(fs1, -fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnjn_s".
    //
    class Fsgnjn_s : public RegOp
    {
      public:
        /// Constructor.
        Fsgnjn_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnjx_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = fs1*(signbit(fs2) ? -1.0 : 1.0);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnjx_s".
    //
    class Fsgnjx_s : public RegOp
    {
      public:
        /// Constructor.
        Fsgnjx_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fsgnj_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = copysign(Fs1, Fs2);\n                        }\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnj_d".
    //
    class Fsgnj_d : public RegOp
    {
      public:
        /// Constructor.
        Fsgnj_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnjn_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = copysign(Fs1, -Fs2);\n                        }\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnjn_d".
    //
    class Fsgnjn_d : public RegOp
    {
      public:
        /// Constructor.
        Fsgnjn_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnjx_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = Fs1*(signbit(Fs2) ? -1.0 : 1.0);\n                        }\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnjx_d".
    //
    class Fsgnjx_d : public RegOp
    {
      public:
        /// Constructor.
        Fsgnjx_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmin_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs2)) {\n                            fd = fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(fs1)) {\n                            fd = fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            fd = fmin(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fmin_s".
    //
    class Fmin_s : public RegOp
    {
      public:
        /// Constructor.
        Fmin_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmax_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs2)) {\n                            fd = fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(fs1)) {\n                            fd = fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            fd = fmax(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fmax_s".
    //
    class Fmax_s : public RegOp
    {
      public:
        /// Constructor.
        Fmax_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmin_d(['\n                        if (issignalingnan(Fs2)) {\n                            Fd = Fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(Fs1)) {\n                            Fd = Fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Fd = fmin(Fs1, Fs2);\n                        }\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fmin_d".
    //
    class Fmin_d : public RegOp
    {
      public:
        /// Constructor.
        Fmin_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmax_d(['\n                        if (issignalingnan(Fs2)) {\n                            Fd = Fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(Fs1)) {\n                            Fd = Fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Fd = fmax(Fs1, Fs2);\n                        }\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fmax_d".
    //
    class Fmax_d : public RegOp
    {
      public:
        /// Constructor.
        Fmax_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_d(['\n                    if (CONV_SGN != 1) {\n                        fault = make_shared<IllegalInstFault>("CONV_SGN != 1",\n                                                              machInst);\n                    }\n                    float fd;\n                    if (issignalingnan(Fs1)) {\n                        fd = numeric_limits<float>::quiet_NaN();\n                        FFLAGS |= FloatInvalid;\n                    } else {\n                        fd = (float)Fs1;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_d".
    //
    class Fcvt_s_d : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_s_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_d_s(['\n                    if (CONV_SGN != 0) {\n                        fault = make_shared<IllegalInstFault>("CONV_SGN != 0",\n                                                              machInst);\n                    }\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                    if (issignalingnan(fs1)) {\n                        Fd = numeric_limits<double>::quiet_NaN();\n                        FFLAGS |= FloatInvalid;\n                    } else {\n                        Fd = (double)fs1;\n                    }\n                ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_s".
    //
    class Fcvt_d_s : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_d_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsqrt_s(['\n                    if (RS2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fd;\n\n                    if (issignalingnan(Fs1_sf)) {\n                        FFLAGS |= FloatInvalid;\n                    }\n                    fd = sqrt(fs1);\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatSqrtOp'],{})

    //
    // Static instruction class for "fsqrt_s".
    //
    class Fsqrt_s : public RegOp
    {
      public:
        /// Constructor.
        Fsqrt_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsqrt_d(['\n                    if (RS2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    Fd = sqrt(Fs1);\n                ', 'FloatSqrtOp'],{})

    //
    // Static instruction class for "fsqrt_d".
    //
    class Fsqrt_d : public RegOp
    {
      public:
        /// Constructor.
        Fsqrt_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fle_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (std::isnan(fs1) || std::isnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = fs1 <= fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fle_s".
    //
    class Fle_s : public RegOp
    {
      public:
        /// Constructor.
        Fle_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::flt_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (std::isnan(fs1) || std::isnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = fs1 < fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "flt_s".
    //
    class Flt_s : public RegOp
    {
      public:
        /// Constructor.
        Flt_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::feq_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Rd = fs1 == fs2 ? 1 : 0;\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "feq_s".
    //
    class Feq_s : public RegOp
    {
      public:
        /// Constructor.
        Feq_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fle_d(['\n                        if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = Fs1 <= Fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fle_d".
    //
    class Fle_d : public RegOp
    {
      public:
        /// Constructor.
        Fle_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::flt_d(['\n                        if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = Fs1 < Fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "flt_d".
    //
    class Flt_d : public RegOp
    {
      public:
        /// Constructor.
        Flt_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::feq_d(['\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Rd = Fs1 == Fs2 ? 1 : 0;\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "feq_d".
    //
    class Feq_d : public RegOp
    {
      public:
        /// Constructor.
        Feq_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 >= numeric_limits<int32_t>::max()) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 <= numeric_limits<int32_t>::min()) {\n                            Rd_sd = numeric_limits<int32_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int32_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_w_s".
    //
    class Fcvt_w_s : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_w_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_wu_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < 0.0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<uint32_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint32_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_wu_s".
    //
    class Fcvt_wu_s : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_wu_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_l_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<int64_t>::max()) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < numeric_limits<int64_t>::min()) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int64_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_l_s".
    //
    class Fcvt_l_s : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_l_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_lu_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < 0.0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<uint64_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint64_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_lu_s".
    //
    class Fcvt_lu_s : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_lu_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<int32_t>::max()) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < numeric_limits<int32_t>::min()) {\n                            Rd_sd = numeric_limits<int32_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int32_t)Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_w_d".
    //
    class Fcvt_w_d : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_w_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_wu_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < 0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<uint32_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint32_t)Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_wu_d".
    //
    class Fcvt_wu_d : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_wu_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_l_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<int64_t>::max()) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < numeric_limits<int64_t>::min()) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_l_d".
    //
    class Fcvt_l_d : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_l_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_lu_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < 0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<uint64_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_lu_d".
    //
    class Fcvt_lu_d : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_lu_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_w(['\n                        float temp = (float)Rs1_sw;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_w".
    //
    class Fcvt_s_w : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_s_w(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_s_wu(['\n                        float temp = (float)Rs1_uw;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_wu".
    //
    class Fcvt_s_wu : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_s_wu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_s_l(['\n                        float temp = (float)Rs1_sd;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_l".
    //
    class Fcvt_s_l : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_s_l(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_s_lu(['\n                        float temp = (float)Rs1;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_lu".
    //
    class Fcvt_s_lu : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_s_lu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_d_w(['\n                        Fd = (double)Rs1_sw;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_w".
    //
    class Fcvt_d_w : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_d_w(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_d_wu(['\n                        Fd = (double)Rs1_uw;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_wu".
    //
    class Fcvt_d_wu : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_d_wu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_d_l(['\n                        Fd = (double)Rs1_sd;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_l".
    //
    class Fcvt_d_l : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_d_l(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_d_lu(['\n                        Fd = (double)Rs1;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_lu".
    //
    class Fcvt_d_lu : public RegOp
    {
      public:
        /// Constructor.
        Fcvt_d_lu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmv_x_s(['\n                        Rd = (uint32_t)Fs1_bits;\n                        if ((Rd&0x80000000) != 0) {\n                            Rd |= (0xFFFFFFFFULL << 32);\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fmv_x_s".
    //
    class Fmv_x_s : public RegOp
    {
      public:
        /// Constructor.
        Fmv_x_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fclass_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        switch (fpclassify(fs1)) {\n                          case FP_INFINITE:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 0;\n                            } else {\n                                Rd = 1 << 7;\n                            }\n                            break;\n                          case FP_NAN:\n                            if (issignalingnan(fs1)) {\n                                Rd = 1 << 8;\n                            } else {\n                                Rd = 1 << 9;\n                            }\n                            break;\n                          case FP_ZERO:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 3;\n                            } else {\n                                Rd = 1 << 4;\n                            }\n                            break;\n                          case FP_SUBNORMAL:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 2;\n                            } else {\n                                Rd = 1 << 5;\n                            }\n                            break;\n                          case FP_NORMAL:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 1;\n                            } else {\n                                Rd = 1 << 6;\n                            }\n                            break;\n                          default:\n                            panic("Unknown classification for operand.");\n                            break;\n                        }\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fclass_s".
    //
    class Fclass_s : public RegOp
    {
      public:
        /// Constructor.
        Fclass_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmv_x_d(['\n                        Rd = Fs1_bits;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fmv_x_d".
    //
    class Fmv_x_d : public RegOp
    {
      public:
        /// Constructor.
        Fmv_x_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fclass_d(['\n                        switch (fpclassify(Fs1)) {\n                          case FP_INFINITE:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 0;\n                            } else {\n                                Rd = 1 << 7;\n                            }\n                            break;\n                          case FP_NAN:\n                            if (issignalingnan(Fs1)) {\n                                Rd = 1 << 8;\n                            } else {\n                                Rd = 1 << 9;\n                            }\n                            break;\n                          case FP_ZERO:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 3;\n                            } else {\n                                Rd = 1 << 4;\n                            }\n                            break;\n                          case FP_SUBNORMAL:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 2;\n                            } else {\n                                Rd = 1 << 5;\n                            }\n                            break;\n                          case FP_NORMAL:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 1;\n                            } else {\n                                Rd = 1 << 6;\n                            }\n                            break;\n                          default:\n                            panic("Unknown classification for operand.");\n                            break;\n                        }\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fclass_d".
    //
    class Fclass_d : public RegOp
    {
      public:
        /// Constructor.
        Fclass_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmv_s_x(['\n                    Fd_bits = (uint64_t)Rs1_uw;\n                ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fmv_s_x".
    //
    class Fmv_s_x : public RegOp
    {
      public:
        /// Constructor.
        Fmv_s_x(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmv_d_x(['\n                    Fd_bits = Rs1;\n                ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fmv_d_x".
    //
    class Fmv_d_x : public RegOp
    {
      public:
        /// Constructor.
        Fmv_d_x(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// BOp::beq(['\n                    if (Rs1 == Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "beq".
    //
    class Beq : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Beq(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::bne(['\n                    if (Rs1 != Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "bne".
    //
    class Bne : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Bne(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::blt(['\n                    if (Rs1_sd < Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "blt".
    //
    class Blt : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Blt(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::bge(['\n                    if (Rs1_sd >= Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "bge".
    //
    class Bge : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Bge(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::bltu(['\n                    if (Rs1 < Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "bltu".
    //
    class Bltu : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Bltu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::bgeu(['\n                    if (Rs1 >= Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "bgeu".
    //
    class Bgeu : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Bgeu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// Unknown::unknown(([], {}))

// Jump::jalr((['\n                Rd = NPC;\n                NPC = (imm + Rs1) & (~0x1);\n            ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "jalr".
    //
    class Jalr : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Jalr(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(ThreadContext *tc) const override;

        using StaticInst::branchTarget;
    };

// Unknown::unknown(([], {}))

// JOp::jal((['\n            Rd = NPC;\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "jal".
    //
    class Jal : public ImmOp<int64_t>
    {
      public:
        /// Constructor.
        Jal(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(Addr pc, const SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// SystemOp::ecall(['\n                        fault = make_shared<SyscallFault>(\n                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall', 'No_OpClass'],{})

    //
    // Static instruction class for "ecall".
    //
    class Ecall : public SystemOp
    {
      public:
        /// Constructor.
        Ecall(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// SystemOp::ebreak(['\n                        fault = make_shared<BreakpointFault>(xc->pcState());\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "ebreak".
    //
    class Ebreak : public SystemOp
    {
      public:
        /// Constructor.
        Ebreak(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// SystemOp::uret(['\n                        STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                        status.uie = status.upie;\n                        status.upie = 1;\n                        xc->setMiscReg(MISCREG_STATUS, status);\n                        NPC = xc->readMiscReg(MISCREG_UEPC);\n                    ', 'IsReturn'],{})

    //
    // Static instruction class for "uret".
    //
    class Uret : public SystemOp
    {
      public:
        /// Constructor.
        Uret(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// SystemOp::sret(['\n                        if (xc->readMiscReg(MISCREG_PRV) == PRV_U) {\n                            fault = make_shared<IllegalInstFault>(\n                                        "sret in user mode", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.spp);\n                            status.sie = status.spie;\n                            status.spie = 1;\n                            status.spp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_SEPC);\n                        }\n                    ', 'IsReturn'],{})

    //
    // Static instruction class for "sret".
    //
    class Sret : public SystemOp
    {
      public:
        /// Constructor.
        Sret(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// SystemOp::mret(['\n                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {\n                            fault = make_shared<IllegalInstFault>(\n                                        "mret at lower privilege", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.mpp);\n                            status.mie = status.mpie;\n                            status.mpie = 1;\n                            status.mpp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_MEPC);\n                        }\n                    ', 'IsReturn'],{})

    //
    // Static instruction class for "mret".
    //
    class Mret : public SystemOp
    {
      public:
        /// Constructor.
        Mret(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// CSROp::csrrw(['\n                    Rd = data;\n                    data = Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrw".
    //
    class Csrrw : public CSROp
    {
      public:
        /// Constructor.
        Csrrw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrs(['\n                    Rd = data;\n                    data |= Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrs".
    //
    class Csrrs : public CSROp
    {
      public:
        /// Constructor.
        Csrrs(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrc(['\n                    Rd = data;\n                    data &= ~Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrc".
    //
    class Csrrc : public CSROp
    {
      public:
        /// Constructor.
        Csrrc(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrwi(['\n                    Rd = data;\n                    data = uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrwi".
    //
    class Csrrwi : public CSROp
    {
      public:
        /// Constructor.
        Csrrwi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrsi(['\n                    Rd = data;\n                    data |= uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrsi".
    //
    class Csrrsi : public CSROp
    {
      public:
        /// Constructor.
        Csrrsi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrci(['\n                    Rd = data;\n                    data &= ~uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrci".
    //
    class Csrrci : public CSROp
    {
      public:
        /// Constructor.
        Csrrci(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))
