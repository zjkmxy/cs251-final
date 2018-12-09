// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   riscv/isa/main.isa


StaticInstPtr
RiscvISA::Decoder::decodeInst(RiscvISA::ExtMachInst machInst)
{
    using namespace RiscvISAInst;
  switch (QUADRANT) {
    
    case 0x0: 
      switch (COPCODE) {
        
        case 0x0:   
          // CIOp::c_addi4spn((['\n            imm = CIMM8<1:1> << 2 |\n                  CIMM8<0:0> << 3 |\n                  CIMM8<7:6> << 4 |\n                  CIMM8<5:2> << 6;\n        ', '\n            if (machInst == 0)\n                fault = make_shared<IllegalInstFault>("zero instruction",\n                                                      machInst);\n            Rp2 = sp + imm;\n        ', 'uint64_t'], {}))
          
              return new C_addi4spn(machInst);
          break;
        
        case 0x1:   
          // CompressedLoad::c_fld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Fp2_bits = Mem;\n            ', '\n                EA = Rp1 + offset;\n            '],{})
          
              return new C_fld(machInst);
          break;
        
        case 0x2:   
          // CompressedLoad::c_lw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Rp2_sd = Mem_sw;\n            ', '\n                EA = Rp1 + offset;\n            '],{})
          
              return new C_lw(machInst);
          break;
        
        case 0x3:   
          // CompressedLoad::c_ld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Rp2_sd = Mem_sd;\n            ', '\n                EA = Rp1 + offset;\n            '],{})
          
              return new C_ld(machInst);
          break;
        
        case 0x5:   
          // CompressedStore::c_fsd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Mem = Fp2_bits;\n            ', '\n                EA = Rp1 + offset;\n            '],{})
          
              return new C_fsd(machInst);
          break;
        
        case 0x6:   
          // CompressedStore::c_sw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Mem_uw = Rp2_uw;\n            '],{'ea_code': '\n                EA = Rp1 + offset;\n            '})
          
              return new C_sw(machInst);
          break;
        
        case 0x7:   
          // CompressedStore::c_sd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                    Mem_ud = Rp2_ud;\n            ', '\n                EA = Rp1 + offset;\n            '],{})
          
              return new C_sd(machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          return new Unknown(machInst);
          break;
        }
      M5_UNREACHABLE;
    
    case 0x1: 
      switch (COPCODE) {
        
        case 0x0:   
          // CIOp::c_addi(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if ((RC1 == 0) != (imm == 0)) {\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    } else // imm == 0\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                }\n                Rc1_sd = Rc1_sd + imm;\n            '],{})
          
              return new C_addi(machInst);
          break;
        
        case 0x1:   
          // CIOp::c_addiw(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = (int32_t)Rc1_sd + imm;\n            '],{})
          
              return new C_addiw(machInst);
          break;
        
        case 0x2:   
          // CIOp::c_li(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = imm;\n            '],{})
          
              return new C_li(machInst);
          break;
        
        case 0x3: 
          switch (RC1) {
            
            case 0x2:   
              // CIOp::c_addi16sp(['\n                    imm = CIMM5<4:4> << 4 |\n                          CIMM5<0:0> << 5 |\n                          CIMM5<3:3> << 6 |\n                          CIMM5<2:1> << 7;\n                    if (CIMM1 > 0)\n                        imm |= ~((int64_t)0x1FF);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    sp_sd = sp_sd + imm;\n                '],{})
              
                  return new C_addi16sp(machInst);
              break;
            
            default:  
              // CIOp::c_lui(['\n                    imm = CIMM5 << 12;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1FFFF);\n                ', '\n                    if (RC1 == 0 || RC1 == 2) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rc1_sd = imm;\n                '],{})
              
                  return new C_lui(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x4: 
          switch (CFUNCT2HIGH) {
            
            case 0x0:   
              // CIOp::c_srli(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rp1 = Rp1 >> imm;\n                ', 'uint64_t'],{})
              
                  return new C_srli(machInst);
              break;
            
            case 0x1:   
              // CIOp::c_srai(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                              machInst);\n                    }\n                    Rp1_sd = Rp1_sd >> imm;\n                ', 'uint64_t'],{})
              
                  return new C_srai(machInst);
              break;
            
            case 0x2:   
              // CIOp::c_andi(['\n                    imm = CIMM5;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1F);\n                ', '\n                    Rp1 = Rp1 & imm;\n                ', 'uint64_t'],{})
              
                  return new C_andi(machInst);
              break;
            
            case 0x3: 
              switch (CFUNCT1) {
                
                case 0x0: 
                  switch (CFUNCT2LOW) {
                    
                    case 0x0:   
                      // ROp::c_sub(['\n                            Rp1 = Rp1 - Rp2;\n                        '],{})
                      
                          return new C_sub(machInst);
                      break;
                    
                    case 0x1:   
                      // ROp::c_xor(['\n                            Rp1 = Rp1 ^ Rp2;\n                        '],{})
                      
                          return new C_xor(machInst);
                      break;
                    
                    case 0x2:   
                      // ROp::c_or(['\n                            Rp1 = Rp1 | Rp2;\n                        '],{})
                      
                          return new C_or(machInst);
                      break;
                    
                    case 0x3:   
                      // ROp::c_and(['\n                            Rp1 = Rp1 & Rp2;\n                        '],{})
                      
                          return new C_and(machInst);
                      break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      return new Unknown(machInst);
                      break;
                    }
                  M5_UNREACHABLE;
                
                case 0x1: 
                  switch (CFUNCT2LOW) {
                    
                    case 0x0:   
                      // ROp::c_subw(['\n                            Rp1_sd = (int32_t)Rp1_sd - Rp2_sw;\n                        '],{})
                      
                          return new C_subw(machInst);
                      break;
                    
                    case 0x1:   
                      // ROp::c_addw(['\n                            Rp1_sd = (int32_t)Rp1_sd + Rp2_sw;\n                        '],{})
                      
                          return new C_addw(machInst);
                      break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      return new Unknown(machInst);
                      break;
                    }
                  M5_UNREACHABLE;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x5:   
          // JOp::c_j((['\n            int64_t offset = CJUMPIMM<3:1> << 1 |\n                             CJUMPIMM<9:9> << 4 |\n                             CJUMPIMM<0:0> << 5 |\n                             CJUMPIMM<5:5> << 6 |\n                             CJUMPIMM<4:4> << 7 |\n                             CJUMPIMM<8:7> << 8 |\n                             CJUMPIMM<6:6> << 10;\n            if (CJUMPIMM<10:10> > 0)\n                offset |= ~((int64_t)0x7FF);\n            NPC = PC + offset;\n        ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))
          
              return new C_j(machInst);
          break;
        
        case 0x6:   
          // CBOp::c_beqz(['\n                if (Rp1 == 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})
          
              return new C_beqz(machInst);
          break;
        
        case 0x7:   
          // CBOp::c_bnez(['\n                if (Rp1 != 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})
          
              return new C_bnez(machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          return new Unknown(machInst);
          break;
        }
      M5_UNREACHABLE;
    
    case 0x2: 
      switch (COPCODE) {
        
        case 0x0:   
          // CIOp::c_slli((['\n            imm = CIMM5 | (CIMM1 << 5);\n        ', '\n            if (imm == 0) {\n                fault = make_shared<IllegalInstFault>("immediate = 0",\n                                                      machInst);\n            }\n            if (RC1 == 0) {\n                fault = make_shared<IllegalInstFault>("source reg x0",\n                                                      machInst);\n            }\n            Rc1 = Rc1 << imm;\n        ', 'uint64_t'], {}))
          
              return new C_slli(machInst);
          break;
        
        case 0x1:   
          // CompressedLoad::c_fldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                Fc1_bits = Mem;\n            ', '\n                EA = sp + offset;\n            '],{})
          
              return new C_fldsp(machInst);
          break;
        
        case 0x2:   
          // CompressedLoad::c_lwsp(['\n                offset = CIMM5<4:2> << 2 |\n                         CIMM1 << 5 |\n                         CIMM5<1:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = Mem_sw;\n            ', '\n                EA = sp + offset;\n            '],{})
          
              return new C_lwsp(machInst);
          break;
        
        case 0x3:   
          // CompressedLoad::c_ldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    fault = make_shared<IllegalInstFault>("source reg x0",\n                                                          machInst);\n                }\n                Rc1_sd = Mem_sd;\n            ', '\n                EA = sp + offset;\n            '],{})
          
              return new C_ldsp(machInst);
          break;
        
        case 0x4: 
          switch (CFUNCT1) {
            
            case 0x0: 
              switch (RC2) {
                
                case 0x0:   
                  // Jump::c_jr((['\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    NPC = Rc1;\n                ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))
                  
                      return new C_jr(machInst);
                  break;
                
                default:  
                  // CROp::c_mv((['\n                    if (RC1 == 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x0",\n                                                              machInst);\n                    }\n                    Rc1 = Rc2;\n                '], {}))
                  
                      return new C_mv(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x1: 
              switch (RC1) {
                
                case 0x0:   
                  // SystemOp::c_ebreak((['\n                    if (RC2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    fault = make_shared<BreakpointFault>(xc->pcState());\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'], {}))
                  
                      return new C_ebreak(machInst);
                  break;
                
                default:
                  switch (RC2) {
                    
                    case 0x0:   
                      // Jump::c_jalr((['\n                        if (RC1 == 0) {\n                            fault = make_shared<IllegalInstFault>\n                                                        ("source reg x0",\n                                                         machInst);\n                        }\n                        ra = NPC;\n                        NPC = Rc1;\n                    ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))
                      
                          return new C_jalr(machInst);
                      break;
                    
                    default:  
                      // ROp::c_add((['\n                        Rc1_sd = Rc1_sd + Rc2_sd;\n                    '], {}))
                      
                          return new C_add(machInst);
                      break;
                    }
                  M5_UNREACHABLE;
                }
              M5_UNREACHABLE;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x5:   
          // CompressedStore::c_fsdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem_ud = Fc2_bits;\n            ', '\n                EA = sp + offset;\n            '],{})
          
              return new C_fsdsp(machInst);
          break;
        
        case 0x6:   
          // CompressedStore::c_swsp(['\n                offset = CIMM6<5:2> << 2 |\n                         CIMM6<1:0> << 6;\n            ', '\n                Mem_uw = Rc2_uw;\n            ', '\n                EA = sp + offset;\n            '],{})
          
              return new C_swsp(machInst);
          break;
        
        case 0x7:   
          // CompressedStore::c_sdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem = Rc2;\n            ', '\n                EA = sp + offset;\n            '],{})
          
              return new C_sdsp(machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          return new Unknown(machInst);
          break;
        }
      M5_UNREACHABLE;
    
    case 0x3: 
      switch (OPCODE) {
        
        case 0x0: 
          switch (FUNCT3) {
            
            case 0x0:   
              // Load::lb(['\n                    Rd_sd = Mem_sb;\n                '],{})
              
                  return new Lb(machInst);
              break;
            
            case 0x1:   
              // Load::lh(['\n                    Rd_sd = Mem_sh;\n                '],{})
              
                  return new Lh(machInst);
              break;
            
            case 0x2:   
              // Load::lw(['\n                    Rd_sd = Mem_sw;\n                '],{})
              
                  return new Lw(machInst);
              break;
            
            case 0x3:   
              // Load::ld(['\n                    Rd_sd = Mem_sd;\n                '],{})
              
                  return new Ld(machInst);
              break;
            
            case 0x4:   
              // Load::lbu(['\n                    Rd = Mem_ub;\n                '],{})
              
                  return new Lbu(machInst);
              break;
            
            case 0x5:   
              // Load::lhu(['\n                    Rd = Mem_uh;\n                '],{})
              
                  return new Lhu(machInst);
              break;
            
            case 0x6:   
              // Load::lwu(['\n                    Rd = Mem_uw;\n                '],{})
              
                  return new Lwu(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x1: 
          switch (FUNCT3) {
            
            case 0x2:   
              // Load::flw(['\n                    Fd_bits = (uint64_t)Mem_uw;\n                '],{'inst_flags': 'FloatMemReadOp'})
              
                  return new Flw(machInst);
              break;
            
            case 0x3:   
              // Load::fld(['\n                    Fd_bits = Mem;\n                '],{'inst_flags': 'FloatMemReadOp'})
              
                  return new Fld(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x3: 
          switch (FUNCT3) {
            
            case 0x0:   
              // IOp::fence(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsMemBarrier', 'No_OpClass'],{})
              
                  return new Fence(machInst);
              break;
            
            case 0x1:   
              // IOp::fence_i(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})
              
                  return new Fence_i(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x4: 
          switch (FUNCT3) {
            
            case 0x0:   
              // IOp::addi(['\n                    Rd_sd = Rs1_sd + imm;\n                '],{})
              
                  return new Addi(machInst);
              break;
            
            case 0x1:   
              // IOp::slli(['\n                    Rd = Rs1 << SHAMT6;\n                '],{})
              
                  return new Slli(machInst);
              break;
            
            case 0x2:   
              // IOp::slti(['\n                    Rd = (Rs1_sd < imm) ? 1 : 0;\n                '],{})
              
                  return new Slti(machInst);
              break;
            
            case 0x3:   
              // IOp::sltiu(['\n                    Rd = (Rs1 < imm) ? 1 : 0;\n                ', 'uint64_t'],{})
              
                  return new Sltiu(machInst);
              break;
            
            case 0x4:   
              // IOp::xori(['\n                    Rd = Rs1 ^ imm;\n                ', 'uint64_t'],{})
              
                  return new Xori(machInst);
              break;
            
            case 0x5: 
              switch (SRTYPE) {
                
                case 0x0:   
                  // IOp::srli(['\n                        Rd = Rs1 >> SHAMT6;\n                    '],{})
                  
                      return new Srli(machInst);
                  break;
                
                case 0x1:   
                  // IOp::srai(['\n                        Rd_sd = Rs1_sd >> SHAMT6;\n                    '],{})
                  
                      return new Srai(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x6:   
              // IOp::ori(['\n                    Rd = Rs1 | imm;\n                ', 'uint64_t'],{})
              
                  return new Ori(machInst);
              break;
            
            case 0x7:   
              // IOp::andi(['\n                    Rd = Rs1 & imm;\n                ', 'uint64_t'],{})
              
                  return new Andi(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x5:   
          // UOp::auipc((['\n            Rd = PC + imm;\n        '], {}))
          
              return new Auipc(machInst);
          break;
        
        case 0x6: 
          switch (FUNCT3) {
            
            case 0x0:   
              // IOp::addiw(['\n                    Rd_sd = Rs1_sw + imm;\n                ', 'int32_t'],{})
              
                  return new Addiw(machInst);
              break;
            
            case 0x1:   
              // IOp::slliw(['\n                    Rd_sd = Rs1_sw << SHAMT5;\n                '],{})
              
                  return new Slliw(machInst);
              break;
            
            case 0x5: 
              switch (SRTYPE) {
                
                case 0x0:   
                  // IOp::srliw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> SHAMT5);\n                    '],{})
                  
                      return new Srliw(machInst);
                  break;
                
                case 0x1:   
                  // IOp::sraiw(['\n                        Rd_sd = Rs1_sw >> SHAMT5;\n                    '],{})
                  
                      return new Sraiw(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x8: 
          switch (FUNCT3) {
            
            case 0x0:   
              // Store::sb(['\n                    Mem_ub = Rs2_ub;\n                '],{})
              
                  return new Sb(machInst);
              break;
            
            case 0x1:   
              // Store::sh(['\n                    Mem_uh = Rs2_uh;\n                '],{})
              
                  return new Sh(machInst);
              break;
            
            case 0x2:   
              // Store::sw(['\n                    Mem_uw = Rs2_uw;\n                '],{})
              
                  return new Sw(machInst);
              break;
            
            case 0x3:   
              // Store::sd(['\n                    Mem_ud = Rs2_ud;\n                '],{})
              
                  return new Sd(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x9: 
          switch (FUNCT3) {
            
            case 0x2:   
              // Store::fsw(['\n                    Mem_uw = (uint32_t)Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})
              
                  return new Fsw(machInst);
              break;
            
            case 0x3:   
              // Store::fsd(['\n                    Mem_ud = Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})
              
                  return new Fsd(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0xb: 
          switch (FUNCT3) {
            
            case 0x2: 
              switch (AMOFUNCT) {
                
                case 0x2:   
                  // LoadReserved::lr_w((['\n                    Rd_sd = Mem_sw;\n                '], {'mem_flags': 'LLSC'}))
                  
                      return new Lr_w(machInst);
                  break;
                
                case 0x3:   
                  // StoreCond::sc_w((['\n                    Mem_uw = Rs2_uw;\n                ', '\n                    Rd = result;\n                '], {'mem_flags': 'LLSC', 'inst_flags': 'IsStoreConditional'}))
                  
                      return new Sc_w(machInst);
                  break;
                
                case 0x0:   
                  // AtomicMemOp::amoadd_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_sw + Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoadd_w(machInst);
                  break;
                
                case 0x1:   
                  // AtomicMemOp::amoswap_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoswap_w(machInst);
                  break;
                
                case 0x4:   
                  // AtomicMemOp::amoxor_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw^Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoxor_w(machInst);
                  break;
                
                case 0x8:   
                  // AtomicMemOp::amoor_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw | Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoor_w(machInst);
                  break;
                
                case 0xc:   
                  // AtomicMemOp::amoand_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = Rs2_uw&Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoand_w(machInst);
                  break;
                
                case 0x10:   
                  // AtomicMemOp::amomin_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = min<int32_t>(Rs2_sw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amomin_w(machInst);
                  break;
                
                case 0x14:   
                  // AtomicMemOp::amomax_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = max<int32_t>(Rs2_sw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amomax_w(machInst);
                  break;
                
                case 0x18:   
                  // AtomicMemOp::amominu_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = min<uint32_t>(Rs2_uw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amominu_w(machInst);
                  break;
                
                case 0x1c:   
                  // AtomicMemOp::amomaxu_w(['Rt_sd = Mem_sw;', '\n                        Mem_sw = max<uint32_t>(Rs2_uw, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amomaxu_w(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x3: 
              switch (AMOFUNCT) {
                
                case 0x2:   
                  // LoadReserved::lr_d((['\n                    Rd_sd = Mem_sd;\n                '], {'mem_flags': 'LLSC'}))
                  
                      return new Lr_d(machInst);
                  break;
                
                case 0x3:   
                  // StoreCond::sc_d((['\n                    Mem = Rs2;\n                ', '\n                    Rd = result;\n                '], {'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'}))
                  
                      return new Sc_d(machInst);
                  break;
                
                case 0x0:   
                  // AtomicMemOp::amoadd_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = Rs2_sd + Rt_sd;\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoadd_d(machInst);
                  break;
                
                case 0x1:   
                  // AtomicMemOp::amoswap_d(['Rt = Mem;', '\n                        Mem = Rs2;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoswap_d(machInst);
                  break;
                
                case 0x4:   
                  // AtomicMemOp::amoxor_d(['Rt = Mem;', '\n                        Mem = Rs2^Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoxor_d(machInst);
                  break;
                
                case 0x8:   
                  // AtomicMemOp::amoor_d(['Rt = Mem;', '\n                        Mem = Rs2 | Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoor_d(machInst);
                  break;
                
                case 0xc:   
                  // AtomicMemOp::amoand_d(['Rt = Mem;', '\n                        Mem = Rs2&Rt;\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amoand_d(machInst);
                  break;
                
                case 0x10:   
                  // AtomicMemOp::amomin_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = min(Rs2_sd, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amomin_d(machInst);
                  break;
                
                case 0x14:   
                  // AtomicMemOp::amomax_d(['Rt_sd = Mem_sd;', '\n                        Mem_sd = max(Rs2_sd, Rt_sd);\n                        Rd_sd = Rt_sd;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amomax_d(machInst);
                  break;
                
                case 0x18:   
                  // AtomicMemOp::amominu_d(['Rt = Mem;', '\n                        Mem = min(Rs2, Rt);\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amominu_d(machInst);
                  break;
                
                case 0x1c:   
                  // AtomicMemOp::amomaxu_d(['Rt = Mem;', '\n                        Mem = max(Rs2, Rt);\n                        Rd = Rt;\n                    ', 'EA = Rs1;'],{})
                  
                      return new Amomaxu_d(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0xc: 
          switch (FUNCT3) {
            
            case 0x0: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::add(['\n                        Rd = Rs1_sd + Rs2_sd;\n                    '],{})
                  
                      return new Add(machInst);
                  break;
                
                case 0x1:   
                  // ROp::mul(['\n                        Rd = Rs1_sd*Rs2_sd;\n                    ', 'IntMultOp'],{})
                  
                      return new Mul(machInst);
                  break;
                
                case 0x20:   
                  // ROp::sub(['\n                        Rd = Rs1_sd - Rs2_sd;\n                    '],{})
                  
                      return new Sub(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x1: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::sll(['\n                        Rd = Rs1 << Rs2<5:0>;\n                    '],{})
                  
                      return new Sll(machInst);
                  break;
                
                case 0x1:   
                  // ROp::mulh(['\n                        bool negate = (Rs1_sd < 0) != (Rs2_sd < 0);\n\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)abs(Rs2_sd);\n                        uint64_t Rs2_hi = (uint64_t)abs(Rs2_sd) >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs2_lo*Rs1_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2_sd == 0 ? 1 : 0)\n                                    : res;\n                    ', 'IntMultOp'],{})
                  
                      return new Mulh(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x2: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::slt(['\n                        Rd = (Rs1_sd < Rs2_sd) ? 1 : 0;\n                    '],{})
                  
                      return new Slt(machInst);
                  break;
                
                case 0x1:   
                  // ROp::mulhsu(['\n                        bool negate = Rs1_sd < 0;\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2 == 0 ? 1 : 0) : res;\n                    ', 'IntMultOp'],{})
                  
                      return new Mulhsu(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x3: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::sltu(['\n                        Rd = (Rs1 < Rs2) ? 1 : 0;\n                    '],{})
                  
                      return new Sltu(machInst);
                  break;
                
                case 0x1:   
                  // ROp::mulhu(['\n                        uint64_t Rs1_lo = (uint32_t)Rs1;\n                        uint64_t Rs1_hi = Rs1 >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;\n                    ', 'IntMultOp'],{})
                  
                      return new Mulhu(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x4: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::xor(['\n                        Rd = Rs1 ^ Rs2;\n                    '],{})
                  
                      return new Xor(machInst);
                  break;
                
                case 0x1:   
                  // ROp::div(['\n                        if (Rs2_sd == 0) {\n                            Rd_sd = -1;\n                        } else if (Rs1_sd == numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                        } else {\n                            Rd_sd = Rs1_sd/Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})
                  
                      return new Div(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x5: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::srl(['\n                        Rd = Rs1 >> Rs2<5:0>;\n                    '],{})
                  
                      return new Srl(machInst);
                  break;
                
                case 0x1:   
                  // ROp::divu(['\n                        if (Rs2 == 0) {\n                            Rd = numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd = Rs1/Rs2;\n                        }\n                    ', 'IntDivOp'],{})
                  
                      return new Divu(machInst);
                  break;
                
                case 0x20:   
                  // ROp::sra(['\n                        Rd_sd = Rs1_sd >> Rs2<5:0>;\n                    '],{})
                  
                      return new Sra(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x6: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::or(['\n                        Rd = Rs1 | Rs2;\n                    '],{})
                  
                      return new Or(machInst);
                  break;
                
                case 0x1:   
                  // ROp::rem(['\n                        if (Rs2_sd == 0) {\n                            Rd = Rs1_sd;\n                        } else if (Rs1_sd == numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd = 0;\n                        } else {\n                            Rd = Rs1_sd%Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})
                  
                      return new Rem(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x7: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::and(['\n                        Rd = Rs1 & Rs2;\n                    '],{})
                  
                      return new And(machInst);
                  break;
                
                case 0x1:   
                  // ROp::remu(['\n                        if (Rs2 == 0) {\n                            Rd = Rs1;\n                        } else {\n                            Rd = Rs1%Rs2;\n                        }\n                    ', 'IntDivOp'],{})
                  
                      return new Remu(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0xd:   
          // UOp::lui((['\n            Rd = (uint64_t)imm;\n        '], {}))
          
              return new Lui(machInst);
          break;
        
        case 0xe: 
          switch (FUNCT3) {
            
            case 0x0: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::addw(['\n                        Rd_sd = Rs1_sw + Rs2_sw;\n                    '],{})
                  
                      return new Addw(machInst);
                  break;
                
                case 0x1:   
                  // ROp::mulw(['\n                        Rd_sd = (int32_t)(Rs1_sw*Rs2_sw);\n                    ', 'IntMultOp'],{})
                  
                      return new Mulw(machInst);
                  break;
                
                case 0x20:   
                  // ROp::subw(['\n                        Rd_sd = Rs1_sw - Rs2_sw;\n                    '],{})
                  
                      return new Subw(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x1:   
              // ROp::sllw(['\n                    Rd_sd = Rs1_sw << Rs2<4:0>;\n                '],{})
              
                  return new Sllw(machInst);
              break;
            
            case 0x4:   
              // ROp::divw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = -1;\n                    } else if (Rs1_sw == numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = numeric_limits<int32_t>::min();\n                    } else {\n                        Rd_sd = Rs1_sw/Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})
              
                  return new Divw(machInst);
              break;
            
            case 0x5: 
              switch (FUNCT7) {
                
                case 0x0:   
                  // ROp::srlw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> Rs2<4:0>);\n                    '],{})
                  
                      return new Srlw(machInst);
                  break;
                
                case 0x1:   
                  // ROp::divuw(['\n                        if (Rs2_uw == 0) {\n                            Rd_sd = numeric_limits<IntReg>::max();\n                        } else {\n                            Rd_sd = (int32_t)(Rs1_uw/Rs2_uw);\n                        }\n                    ', 'IntDivOp'],{})
                  
                      return new Divuw(machInst);
                  break;
                
                case 0x20:   
                  // ROp::sraw(['\n                        Rd_sd = Rs1_sw >> Rs2<4:0>;\n                    '],{})
                  
                      return new Sraw(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x6:   
              // ROp::remw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = Rs1_sw;\n                    } else if (Rs1_sw == numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = 0;\n                    } else {\n                        Rd_sd = Rs1_sw%Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})
              
                  return new Remw(machInst);
              break;
            
            case 0x7:   
              // ROp::remuw(['\n                    if (Rs2_uw == 0) {\n                        Rd_sd = (int32_t)Rs1_uw;\n                    } else {\n                        Rd_sd = (int32_t)(Rs1_uw%Rs2_uw);\n                    }\n                ', 'IntDivOp'],{})
              
                  return new Remuw(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x10: 
          switch (FUNCT2) {
            
            case 0x0:   
              // FPROp::fmadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = fs3;\n                        }\n                    } else {\n                        fd = fs1*fs2 + fs3;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})
              
                  return new Fmadd_s(machInst);
              break;
            
            case 0x1:   
              // FPROp::fmadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else {\n                            Fd = Fs3;\n                        }\n                    } else {\n                        Fd = Fs1*Fs2 + Fs3;\n                    }\n                ', 'FloatMultAccOp'],{})
              
                  return new Fmadd_d(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x11: 
          switch (FUNCT2) {
            
            case 0x0:   
              // FPROp::fmsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = -fs3;\n                        }\n                    } else {\n                        fd = fs1*fs2 - fs3;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})
              
                  return new Fmsub_s(machInst);
              break;
            
            case 0x1:   
              // FPROp::fmsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else {\n                            Fd = -Fs3;\n                        }\n                    } else {\n                        Fd = Fs1*Fs2 - Fs3;\n                    }\n                ', 'FloatMultAccOp'],{})
              
                  return new Fmsub_d(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x12: 
          switch (FUNCT2) {
            
            case 0x0:   
              // FPROp::fnmsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = fs3;\n                        }\n                    } else {\n                        fd = -(fs1*fs2 - fs3);\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})
              
                  return new Fnmsub_s(machInst);
              break;
            
            case 0x1:   
              // FPROp::fnmsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2)\n                            || std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else {\n                            Fd = Fs3;\n                        }\n                    } else {\n                        Fd = -(Fs1*Fs2 - Fs3);\n                    }\n                ', 'FloatMultAccOp'],{})
              
                  return new Fnmsub_d(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x13: 
          switch (FUNCT2) {
            
            case 0x0:   
              // FPROp::fnmadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fs3 = reinterpret_cast<float&>(temp = Fs3_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2) ||\n                            std::isnan(fs3)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)\n                                || issignalingnan(fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else if (std::isinf(fs1) || std::isinf(fs2) ||\n                            std::isinf(fs3)) {\n                        if (signbit(fs1) == signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = -numeric_limits<float>::infinity();\n                        } else if (signbit(fs1) != signbit(fs2)\n                                && !std::isinf(fs3)) {\n                            fd = numeric_limits<float>::infinity();\n                        } else { // Fs3_sf is infinity\n                            fd = -fs3;\n                        }\n                    } else {\n                        fd = -(fs1*fs2 + fs3);\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultAccOp'],{})
              
                  return new Fnmadd_s(machInst);
              break;
            
            case 0x1:   
              // FPROp::fnmadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2) ||\n                            std::isnan(Fs3)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)\n                                || issignalingnan(Fs3)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else if (std::isinf(Fs1) || std::isinf(Fs2) ||\n                            std::isinf(Fs3)) {\n                        if (signbit(Fs1) == signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = -numeric_limits<double>::infinity();\n                        } else if (signbit(Fs1) != signbit(Fs2)\n                                && !std::isinf(Fs3)) {\n                            Fd = numeric_limits<double>::infinity();\n                        } else {\n                            Fd = -Fs3;\n                        }\n                    } else {\n                        Fd = -(Fs1*Fs2 + Fs3);\n                    }\n                ', 'FloatMultAccOp'],{})
              
                  return new Fnmadd_d(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x14: 
          switch (FUNCT7) {
            
            case 0x0:   
              // FPROp::fadd_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1 + fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatAddOp'],{})
              
                  return new Fadd_s(machInst);
              break;
            
            case 0x1:   
              // FPROp::fadd_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1 + Fs2;\n                    }\n                ', 'FloatAddOp'],{})
              
                  return new Fadd_d(machInst);
              break;
            
            case 0x4:   
              // FPROp::fsub_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1 - fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatAddOp'],{})
              
                  return new Fsub_s(machInst);
              break;
            
            case 0x5:   
              // FPROp::fsub_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1 - Fs2;\n                    }\n                ', 'FloatAddOp'],{})
              
                  return new Fsub_d(machInst);
              break;
            
            case 0x8:   
              // FPROp::fmul_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1*fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatMultOp'],{})
              
                  return new Fmul_s(machInst);
              break;
            
            case 0x9:   
              // FPROp::fmul_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1*Fs2;\n                    }\n                ', 'FloatMultOp'],{})
              
                  return new Fmul_d(machInst);
              break;
            
            case 0xc:   
              // FPROp::fdiv_s(['\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                    float fd;\n\n                    if (std::isnan(fs1) || std::isnan(fs2)) {\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        fd = numeric_limits<float>::quiet_NaN();\n                    } else {\n                        fd = fs1/fs2;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatDivOp'],{})
              
                  return new Fdiv_s(machInst);
              break;
            
            case 0xd:   
              // FPROp::fdiv_d(['\n                    if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Fd = numeric_limits<double>::quiet_NaN();\n                    } else {\n                        Fd = Fs1/Fs2;\n                    }\n                ', 'FloatDivOp'],{})
              
                  return new Fdiv_d(machInst);
              break;
            
            case 0x10: 
              switch (ROUND_MODE) {
                
                case 0x0:   
                  // FPROp::fsgnj_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = copysign(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})
                  
                      return new Fsgnj_s(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fsgnjn_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = copysign(fs1, -fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})
                  
                      return new Fsgnjn_s(machInst);
                  break;
                
                case 0x2:   
                  // FPROp::fsgnjx_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs1)) {\n                            fd = numeric_limits<float>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            fd = fs1*(signbit(fs2) ? -1.0 : 1.0);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatMiscOp'],{})
                  
                      return new Fsgnjx_s(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x11: 
              switch (ROUND_MODE) {
                
                case 0x0:   
                  // FPROp::fsgnj_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = copysign(Fs1, Fs2);\n                        }\n                    ', 'FloatMiscOp'],{})
                  
                      return new Fsgnj_d(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fsgnjn_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = copysign(Fs1, -Fs2);\n                        }\n                    ', 'FloatMiscOp'],{})
                  
                      return new Fsgnjn_d(machInst);
                  break;
                
                case 0x2:   
                  // FPROp::fsgnjx_d(['\n                        if (issignalingnan(Fs1)) {\n                            Fd = numeric_limits<double>::signaling_NaN();\n                            feclearexcept(FE_INVALID);\n                        } else {\n                            Fd = Fs1*(signbit(Fs2) ? -1.0 : 1.0);\n                        }\n                    ', 'FloatMiscOp'],{})
                  
                      return new Fsgnjx_d(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x14: 
              switch (ROUND_MODE) {
                
                case 0x0:   
                  // FPROp::fmin_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs2)) {\n                            fd = fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(fs1)) {\n                            fd = fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            fd = fmin(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatCmpOp'],{})
                  
                      return new Fmin_s(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fmax_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n                        float fd;\n\n                        if (issignalingnan(fs2)) {\n                            fd = fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(fs1)) {\n                            fd = fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            fd = fmax(fs1, fs2);\n                        }\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                    ', 'FloatCmpOp'],{})
                  
                      return new Fmax_s(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x15: 
              switch (ROUND_MODE) {
                
                case 0x0:   
                  // FPROp::fmin_d(['\n                        if (issignalingnan(Fs2)) {\n                            Fd = Fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(Fs1)) {\n                            Fd = Fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Fd = fmin(Fs1, Fs2);\n                        }\n                    ', 'FloatCmpOp'],{})
                  
                      return new Fmin_d(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fmax_d(['\n                        if (issignalingnan(Fs2)) {\n                            Fd = Fs1;\n                            FFLAGS |= FloatInvalid;\n                        } else if (issignalingnan(Fs1)) {\n                            Fd = Fs2;\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Fd = fmax(Fs1, Fs2);\n                        }\n                    ', 'FloatCmpOp'],{})
                  
                      return new Fmax_d(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x20:   
              // FPROp::fcvt_s_d(['\n                    if (CONV_SGN != 1) {\n                        fault = make_shared<IllegalInstFault>("CONV_SGN != 1",\n                                                              machInst);\n                    }\n                    float fd;\n                    if (issignalingnan(Fs1)) {\n                        fd = numeric_limits<float>::quiet_NaN();\n                        FFLAGS |= FloatInvalid;\n                    } else {\n                        fd = (float)Fs1;\n                    }\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatCvtOp'],{})
              
                  return new Fcvt_s_d(machInst);
              break;
            
            case 0x21:   
              // FPROp::fcvt_d_s(['\n                    if (CONV_SGN != 0) {\n                        fault = make_shared<IllegalInstFault>("CONV_SGN != 0",\n                                                              machInst);\n                    }\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                    if (issignalingnan(fs1)) {\n                        Fd = numeric_limits<double>::quiet_NaN();\n                        FFLAGS |= FloatInvalid;\n                    } else {\n                        Fd = (double)fs1;\n                    }\n                ', 'FloatCvtOp'],{})
              
                  return new Fcvt_d_s(machInst);
              break;
            
            case 0x2c:   
              // FPROp::fsqrt_s(['\n                    if (RS2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    uint32_t temp;\n                    float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                    float fd;\n\n                    if (issignalingnan(Fs1_sf)) {\n                        FFLAGS |= FloatInvalid;\n                    }\n                    fd = sqrt(fs1);\n                    Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(fd);\n                ', 'FloatSqrtOp'],{})
              
                  return new Fsqrt_s(machInst);
              break;
            
            case 0x2d:   
              // FPROp::fsqrt_d(['\n                    if (RS2 != 0) {\n                        fault = make_shared<IllegalInstFault>("source reg x1",\n                                                              machInst);\n                    }\n                    Fd = sqrt(Fs1);\n                ', 'FloatSqrtOp'],{})
              
                  return new Fsqrt_d(machInst);
              break;
            
            case 0x50: 
              switch (ROUND_MODE) {
                
                case 0x0:   
                  // FPROp::fle_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (std::isnan(fs1) || std::isnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = fs1 <= fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})
                  
                      return new Fle_s(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::flt_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (std::isnan(fs1) || std::isnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = fs1 < fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})
                  
                      return new Flt_s(machInst);
                  break;
                
                case 0x2:   
                  // FPROp::feq_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        float fs2 = reinterpret_cast<float&>(temp = Fs2_bits);\n\n                        if (issignalingnan(fs1) || issignalingnan(fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Rd = fs1 == fs2 ? 1 : 0;\n                    ', 'FloatCmpOp'],{})
                  
                      return new Feq_s(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x51: 
              switch (ROUND_MODE) {
                
                case 0x0:   
                  // FPROp::fle_d(['\n                        if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = Fs1 <= Fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})
                  
                      return new Fle_d(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::flt_d(['\n                        if (std::isnan(Fs1) || std::isnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                            Rd = 0;\n                        } else {\n                            Rd = Fs1 < Fs2 ? 1 : 0;\n                        }\n                    ', 'FloatCmpOp'],{})
                  
                      return new Flt_d(machInst);
                  break;
                
                case 0x2:   
                  // FPROp::feq_d(['\n                        if (issignalingnan(Fs1) || issignalingnan(Fs2)) {\n                            FFLAGS |= FloatInvalid;\n                        }\n                        Rd = Fs1 == Fs2 ? 1 : 0;\n                    ', 'FloatCmpOp'],{})
                  
                      return new Feq_d(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x60: 
              switch (CONV_SGN) {
                
                case 0x0:   
                  // FPROp::fcvt_w_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 >= numeric_limits<int32_t>::max()) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 <= numeric_limits<int32_t>::min()) {\n                            Rd_sd = numeric_limits<int32_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int32_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_w_s(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fcvt_wu_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < 0.0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<uint32_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint32_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_wu_s(machInst);
                  break;
                
                case 0x2:   
                  // FPROp::fcvt_l_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<int64_t>::max()) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < numeric_limits<int64_t>::min()) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int64_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_l_s(machInst);
                  break;
                
                case 0x3:   
                  // FPROp::fcvt_lu_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n\n                        if (std::isnan(fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 < 0.0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (fs1 > numeric_limits<uint64_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint64_t)fs1;\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_lu_s(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x61: 
              switch (CONV_SGN) {
                
                case 0x0:   
                  // FPROp::fcvt_w_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<int32_t>::max()) {\n                            Rd_sd = numeric_limits<int32_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < numeric_limits<int32_t>::min()) {\n                            Rd_sd = numeric_limits<int32_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = (int32_t)Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_w_d(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fcvt_wu_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < 0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<uint32_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = (uint32_t)Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_wu_d(machInst);
                  break;
                
                case 0x2:   
                  // FPROp::fcvt_l_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<int64_t>::max()) {\n                            Rd_sd = numeric_limits<int64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < numeric_limits<int64_t>::min()) {\n                            Rd_sd = numeric_limits<int64_t>::min();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd_sd = Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_l_d(machInst);
                  break;
                
                case 0x3:   
                  // FPROp::fcvt_lu_d(['\n                        if (std::isnan(Fs1)) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 < 0) {\n                            Rd = 0;\n                            FFLAGS |= FloatInvalid;\n                        } else if (Fs1 > numeric_limits<uint64_t>::max()) {\n                            Rd = numeric_limits<uint64_t>::max();\n                            FFLAGS |= FloatInvalid;\n                        } else {\n                            Rd = Fs1;\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_lu_d(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x68: 
              switch (CONV_SGN) {
                
                case 0x0:   
                  // FPROp::fcvt_s_w(['\n                        float temp = (float)Rs1_sw;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_s_w(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fcvt_s_wu(['\n                        float temp = (float)Rs1_uw;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_s_wu(machInst);
                  break;
                
                case 0x2:   
                  // FPROp::fcvt_s_l(['\n                        float temp = (float)Rs1_sd;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_s_l(machInst);
                  break;
                
                case 0x3:   
                  // FPROp::fcvt_s_lu(['\n                        float temp = (float)Rs1;\n                        Fd_bits = (uint64_t)reinterpret_cast<uint32_t&>(temp);\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_s_lu(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x69: 
              switch (CONV_SGN) {
                
                case 0x0:   
                  // FPROp::fcvt_d_w(['\n                        Fd = (double)Rs1_sw;\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_d_w(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fcvt_d_wu(['\n                        Fd = (double)Rs1_uw;\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_d_wu(machInst);
                  break;
                
                case 0x2:   
                  // FPROp::fcvt_d_l(['\n                        Fd = (double)Rs1_sd;\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_d_l(machInst);
                  break;
                
                case 0x3:   
                  // FPROp::fcvt_d_lu(['\n                        Fd = (double)Rs1;\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fcvt_d_lu(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x70: 
              switch (ROUND_MODE) {
                
                case 0x0:   
                  // FPROp::fmv_x_s(['\n                        Rd = (uint32_t)Fs1_bits;\n                        if ((Rd&0x80000000) != 0) {\n                            Rd |= (0xFFFFFFFFULL << 32);\n                        }\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fmv_x_s(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fclass_s(['\n                        uint32_t temp;\n                        float fs1 = reinterpret_cast<float&>(temp = Fs1_bits);\n                        switch (fpclassify(fs1)) {\n                          case FP_INFINITE:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 0;\n                            } else {\n                                Rd = 1 << 7;\n                            }\n                            break;\n                          case FP_NAN:\n                            if (issignalingnan(fs1)) {\n                                Rd = 1 << 8;\n                            } else {\n                                Rd = 1 << 9;\n                            }\n                            break;\n                          case FP_ZERO:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 3;\n                            } else {\n                                Rd = 1 << 4;\n                            }\n                            break;\n                          case FP_SUBNORMAL:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 2;\n                            } else {\n                                Rd = 1 << 5;\n                            }\n                            break;\n                          case FP_NORMAL:\n                            if (signbit(fs1)) {\n                                Rd = 1 << 1;\n                            } else {\n                                Rd = 1 << 6;\n                            }\n                            break;\n                          default:\n                            panic("Unknown classification for operand.");\n                            break;\n                        }\n                    ', 'FloatMiscOp'],{})
                  
                      return new Fclass_s(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x71: 
              switch (ROUND_MODE) {
                
                case 0x0:   
                  // FPROp::fmv_x_d(['\n                        Rd = Fs1_bits;\n                    ', 'FloatCvtOp'],{})
                  
                      return new Fmv_x_d(machInst);
                  break;
                
                case 0x1:   
                  // FPROp::fclass_d(['\n                        switch (fpclassify(Fs1)) {\n                          case FP_INFINITE:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 0;\n                            } else {\n                                Rd = 1 << 7;\n                            }\n                            break;\n                          case FP_NAN:\n                            if (issignalingnan(Fs1)) {\n                                Rd = 1 << 8;\n                            } else {\n                                Rd = 1 << 9;\n                            }\n                            break;\n                          case FP_ZERO:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 3;\n                            } else {\n                                Rd = 1 << 4;\n                            }\n                            break;\n                          case FP_SUBNORMAL:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 2;\n                            } else {\n                                Rd = 1 << 5;\n                            }\n                            break;\n                          case FP_NORMAL:\n                            if (signbit(Fs1)) {\n                                Rd = 1 << 1;\n                            } else {\n                                Rd = 1 << 6;\n                            }\n                            break;\n                          default:\n                            panic("Unknown classification for operand.");\n                            break;\n                        }\n                    ', 'FloatMiscOp'],{})
                  
                      return new Fclass_d(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x78:   
              // FPROp::fmv_s_x(['\n                    Fd_bits = (uint64_t)Rs1_uw;\n                ', 'FloatCvtOp'],{})
              
                  return new Fmv_s_x(machInst);
              break;
            
            case 0x79:   
              // FPROp::fmv_d_x(['\n                    Fd_bits = Rs1;\n                ', 'FloatCvtOp'],{})
              
                  return new Fmv_d_x(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x18: 
          switch (FUNCT3) {
            
            case 0x0:   
              // BOp::beq(['\n                    if (Rs1 == Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})
              
                  return new Beq(machInst);
              break;
            
            case 0x1:   
              // BOp::bne(['\n                    if (Rs1 != Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})
              
                  return new Bne(machInst);
              break;
            
            case 0x4:   
              // BOp::blt(['\n                    if (Rs1_sd < Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})
              
                  return new Blt(machInst);
              break;
            
            case 0x5:   
              // BOp::bge(['\n                    if (Rs1_sd >= Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})
              
                  return new Bge(machInst);
              break;
            
            case 0x6:   
              // BOp::bltu(['\n                    if (Rs1 < Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})
              
                  return new Bltu(machInst);
              break;
            
            case 0x7:   
              // BOp::bgeu(['\n                    if (Rs1 >= Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})
              
                  return new Bgeu(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x19: 
          switch (FUNCT3) {
            
            case 0x0:   
              // Jump::jalr((['\n                Rd = NPC;\n                NPC = (imm + Rs1) & (~0x1);\n            ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))
              
                  return new Jalr(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        case 0x1b:   
          // JOp::jal((['\n            Rd = NPC;\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl', 'IsCall'], {}))
          
              return new Jal(machInst);
          break;
        
        case 0x1c: 
          switch (FUNCT3) {
            
            case 0x0: 
              switch (FUNCT12) {
                
                case 0x0:   
                  // SystemOp::ecall(['\n                        fault = make_shared<SyscallFault>(\n                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall', 'No_OpClass'],{})
                  
                      return new Ecall(machInst);
                  break;
                
                case 0x1:   
                  // SystemOp::ebreak(['\n                        fault = make_shared<BreakpointFault>(xc->pcState());\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})
                  
                      return new Ebreak(machInst);
                  break;
                
                case 0x2:   
                  // SystemOp::uret(['\n                        STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                        status.uie = status.upie;\n                        status.upie = 1;\n                        xc->setMiscReg(MISCREG_STATUS, status);\n                        NPC = xc->readMiscReg(MISCREG_UEPC);\n                    ', 'IsReturn'],{})
                  
                      return new Uret(machInst);
                  break;
                
                case 0x102:   
                  // SystemOp::sret(['\n                        if (xc->readMiscReg(MISCREG_PRV) == PRV_U) {\n                            fault = make_shared<IllegalInstFault>(\n                                        "sret in user mode", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.spp);\n                            status.sie = status.spie;\n                            status.spie = 1;\n                            status.spp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_SEPC);\n                        }\n                    ', 'IsReturn'],{})
                  
                      return new Sret(machInst);
                  break;
                
                case 0x302:   
                  // SystemOp::mret(['\n                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {\n                            fault = make_shared<IllegalInstFault>(\n                                        "mret at lower privilege", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.mpp);\n                            status.mie = status.mpie;\n                            status.mpie = 1;\n                            status.mpp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_MEPC);\n                        }\n                    ', 'IsReturn'],{})
                  
                      return new Mret(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  return new Unknown(machInst);
                  break;
                }
              M5_UNREACHABLE;
            
            case 0x1:   
              // CSROp::csrrw(['\n                    Rd = data;\n                    data = Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})
              
                  return new Csrrw(machInst);
              break;
            
            case 0x2:   
              // CSROp::csrrs(['\n                    Rd = data;\n                    data |= Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})
              
                  return new Csrrs(machInst);
              break;
            
            case 0x3:   
              // CSROp::csrrc(['\n                    Rd = data;\n                    data &= ~Rs1;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})
              
                  return new Csrrc(machInst);
              break;
            
            case 0x5:   
              // CSROp::csrrwi(['\n                    Rd = data;\n                    data = uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})
              
                  return new Csrrwi(machInst);
              break;
            
            case 0x6:   
              // CSROp::csrrsi(['\n                    Rd = data;\n                    data |= uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})
              
                  return new Csrrsi(machInst);
              break;
            
            case 0x7:   
              // CSROp::csrrci(['\n                    Rd = data;\n                    data &= ~uimm;\n                ', 'IsNonSpeculative', 'No_OpClass'],{})
              
                  return new Csrrci(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              return new Unknown(machInst);
              break;
            }
          M5_UNREACHABLE;
        
        default:
          
          // Unknown::unknown(([], {}))
          return new Unknown(machInst);
          break;
        }
      M5_UNREACHABLE;
    
    default:
      
      // Unknown::unknown(([], {}))
      return new Unknown(machInst);
      break;
    }
  }