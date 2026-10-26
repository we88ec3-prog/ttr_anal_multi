
void FUN_00818430(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  char ******ppppppcVar11;
  char *pcVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined1 *puVar17;
  int iVar18;
  uint in_stack_0000001c;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  int local_e0;
  uint local_dc;
  int local_d8;
  uint local_d4;
  uint local_d0;
  undefined4 *local_cc;
  undefined1 local_c8;
  undefined **local_c4 [19];
  uint local_78;
  undefined4 local_68;
  uint local_64;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  char *****local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00926263;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_e8 = param_1;
  local_8 = 0;
  local_14 = uVar7;
  FUN_0072ef00(local_c4,&param_2);
  local_8._0_1_ = 1;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    local_8 = (uint)local_8._1_3_ << 8;
    local_c4[0] = TiXmlDocument::vftable;
    if (0xf < local_64) {
      FUN_0089120c(local_78);
    }
    local_64 = 0xf;
    local_68 = 0;
    local_78 = local_78 & 0xffffff00;
    FUN_0072e040();
    if (0xf < in_stack_0000001c) {
      FUN_0089120c(param_2);
    }
  }
  else {
    iVar8 = FUN_0072e360(uVar7);
    if (iVar8 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      local_c4[0] = TiXmlDocument::vftable;
      if (0xf < local_64) {
        FUN_0089120c(local_78);
      }
      local_64 = 0xf;
      local_68 = 0;
      local_78 = local_78 & 0xffffff00;
      FUN_0072e040();
      if (0xf < in_stack_0000001c) {
        FUN_0089120c(param_2);
      }
    }
    else {
      iVar8 = FUN_0072e360(uVar7);
      while (iVar8 != 0) {
        iVar8 = FUN_007300a0("CharID");
        if (iVar8 == 0) {
LAB_008185b1:
          local_dc = 0;
        }
        else {
          puVar9 = (undefined4 *)(iVar8 + 0x30);
          if (0xf < *(uint *)(iVar8 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 == (undefined4 *)0x0) goto LAB_008185b1;
          local_dc = FUN_008917b4(puVar9);
        }
        local_d8 = FUN_0072e360();
        if (local_d8 != 0) {
          do {
            iVar18 = local_d8 + 0x44;
            for (iVar8 = *(int *)(local_d8 + 0x94); iVar8 != iVar18; iVar8 = *(int *)(iVar8 + 0x50))
            {
              pcVar12 = (char *)(iVar8 + 0x14);
              if (0xf < *(uint *)(iVar8 + 0x28)) {
                pcVar12 = *(char **)pcVar12;
              }
              iVar10 = __stricmp(pcVar12,"ID");
              if (iVar10 == 0) {
                if (iVar8 != 0) {
                  puVar9 = (undefined4 *)(iVar8 + 0x30);
                  if (0xf < *(uint *)(iVar8 + 0x44)) {
                    puVar9 = (undefined4 *)*puVar9;
                  }
                  if (puVar9 != (undefined4 *)0x0) {
                    local_e4 = FUN_008917b4(puVar9);
                    goto LAB_0081862b;
                  }
                }
                break;
              }
            }
            local_e4 = 0;
LAB_0081862b:
            uVar16 = local_e4;
            iVar8 = FUN_0072e360();
            if (iVar8 == 0) {
              puVar13 = (undefined1 *)FUN_00891268(0xc);
              local_c8 = (undefined1)uVar16;
              puVar17 = (undefined1 *)0x0;
              if (puVar13 != (undefined1 *)0x0) {
                *puVar13 = local_c8;
                puVar13[1] = (undefined1)local_dc;
                *(undefined2 *)(puVar13 + 4) = 0;
                *(undefined4 *)(puVar13 + 8) = 0;
                puVar13[6] = 0;
                puVar17 = puVar13;
              }
              local_d0 = local_dc & 0xffff;
              FUN_00819460(&local_d0);
              iVar8 = FUN_00819650();
              *(undefined1 **)(iVar8 + 4) = puVar17;
            }
            else {
              iVar8 = FUN_0072e360();
              local_cc = (undefined4 *)FUN_00891268(0xc);
              if (local_cc == (undefined4 *)0x0) {
                local_cc = (undefined4 *)0x0;
              }
              else {
                *(undefined1 *)local_cc = (undefined1)local_e4;
                *(undefined1 *)((int)local_cc + 1) = (undefined1)local_dc;
                *(undefined2 *)(local_cc + 1) = 0;
                *(undefined1 *)((int)local_cc + 6) = 0;
                local_cc[2] = 0;
              }
              while (iVar8 != 0) {
                local_38 = 0xf;
                local_3c = 0;
                local_4c = local_4c & 0xffffff00;
                FUN_00402a70(&DAT_00c408b8,4);
                local_8._0_1_ = 2;
                FUN_0072ecf0(&DAT_00bf2375);
                local_8 = CONCAT31(local_8._1_3_,4);
                if (0xf < local_38) {
                  FUN_0089120c(local_4c);
                }
                local_38 = 0xf;
                local_3c = 0;
                local_4c = local_4c & 0xffffff00;
                ppppppcVar11 = (char ******)local_30[0];
                if (local_1c < 0x10) {
                  ppppppcVar11 = local_30;
                }
                iVar18 = __stricmp((char *)ppppppcVar11,"Matrix");
                if (iVar18 == 0) {
                  for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                      iVar18 = *(int *)(iVar18 + 0x50)) {
                    pcVar12 = (char *)(iVar18 + 0x14);
                    if (0xf < *(uint *)(iVar18 + 0x28)) {
                      pcVar12 = *(char **)pcVar12;
                    }
                    iVar10 = __stricmp(pcVar12,"ID");
                    if (iVar10 == 0) {
                      if (iVar18 != 0) {
                        puVar9 = (undefined4 *)(iVar18 + 0x30);
                        if (0xf < *(uint *)(iVar18 + 0x44)) {
                          puVar9 = (undefined4 *)*puVar9;
                        }
                        if (puVar9 != (undefined4 *)0x0) {
                          uVar4 = FUN_008917b4(puVar9);
                          *(undefined1 *)(local_cc + 1) = uVar4;
                          goto LAB_00818924;
                        }
                      }
                      break;
                    }
                  }
                  *(undefined1 *)(local_cc + 1) = 0;
                }
                else {
                  ppppppcVar11 = (char ******)local_30[0];
                  if (local_1c < 0x10) {
                    ppppppcVar11 = local_30;
                  }
                  iVar18 = __stricmp((char *)ppppppcVar11,"CharLevel");
                  if (iVar18 == 0) {
                    for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                        iVar18 = *(int *)(iVar18 + 0x50)) {
                      pcVar12 = (char *)(iVar18 + 0x14);
                      if (0xf < *(uint *)(iVar18 + 0x28)) {
                        pcVar12 = *(char **)pcVar12;
                      }
                      iVar10 = __stricmp(pcVar12,"Value");
                      if (iVar10 == 0) {
                        if (iVar18 != 0) {
                          puVar9 = (undefined4 *)(iVar18 + 0x30);
                          if (0xf < *(uint *)(iVar18 + 0x44)) {
                            puVar9 = (undefined4 *)*puVar9;
                          }
                          if (puVar9 != (undefined4 *)0x0) {
                            uVar4 = FUN_008917b4(puVar9);
                            *(undefined1 *)((int)local_cc + 5) = uVar4;
                            goto LAB_00818924;
                          }
                        }
                        break;
                      }
                    }
                    *(undefined1 *)((int)local_cc + 5) = 0;
                  }
                  else {
                    ppppppcVar11 = (char ******)local_30[0];
                    if (local_1c < 0x10) {
                      ppppppcVar11 = local_30;
                    }
                    iVar18 = __stricmp((char *)ppppppcVar11,"ExpedLevel");
                    if (iVar18 == 0) {
                      for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                          iVar18 = *(int *)(iVar18 + 0x50)) {
                        pcVar12 = (char *)(iVar18 + 0x14);
                        if (0xf < *(uint *)(iVar18 + 0x28)) {
                          pcVar12 = *(char **)pcVar12;
                        }
                        iVar10 = __stricmp(pcVar12,"Value");
                        if (iVar10 == 0) {
                          if (iVar18 != 0) {
                            puVar9 = (undefined4 *)(iVar18 + 0x30);
                            if (0xf < *(uint *)(iVar18 + 0x44)) {
                              puVar9 = (undefined4 *)*puVar9;
                            }
                            if (puVar9 != (undefined4 *)0x0) {
                              uVar4 = FUN_008917b4(puVar9);
                              *(undefined1 *)((int)local_cc + 6) = uVar4;
                              goto LAB_00818924;
                            }
                          }
                          break;
                        }
                      }
                      *(undefined1 *)((int)local_cc + 6) = 0;
                    }
                    else {
                      ppppppcVar11 = (char ******)local_30[0];
                      if (local_1c < 0x10) {
                        ppppppcVar11 = local_30;
                      }
                      iVar18 = __stricmp((char *)ppppppcVar11,"SkillExp");
                      if (iVar18 == 0) {
                        for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                            iVar18 = *(int *)(iVar18 + 0x50)) {
                          pcVar12 = (char *)(iVar18 + 0x14);
                          if (0xf < *(uint *)(iVar18 + 0x28)) {
                            pcVar12 = *(char **)pcVar12;
                          }
                          iVar10 = __stricmp(pcVar12,"Value");
                          if (iVar10 == 0) {
                            if (iVar18 != 0) {
                              puVar9 = (undefined4 *)(iVar18 + 0x30);
                              if (0xf < *(uint *)(iVar18 + 0x44)) {
                                puVar9 = (undefined4 *)*puVar9;
                              }
                              if (puVar9 != (undefined4 *)0x0) {
                                uVar16 = FUN_008917b4(puVar9);
                                goto LAB_0081891b;
                              }
                            }
                            break;
                          }
                        }
                        uVar16 = 0;
LAB_0081891b:
                        local_cc[2] = uVar16;
                      }
                    }
                  }
                }
LAB_00818924:
                iVar8 = FUN_0072e3c0();
                local_8._0_1_ = 1;
                if (0xf < local_1c) {
                  FUN_0089120c(local_30[0]);
                }
              }
              local_d0 = local_dc & 0xffff;
              local_c8 = (undefined1)local_e4;
              FUN_00819460(&local_d0);
              iVar8 = FUN_00819650();
              *(undefined4 **)(iVar8 + 4) = local_cc;
            }
            local_cc = (undefined4 *)FUN_00891268(0x78);
            if (local_cc == (undefined4 *)0x0) {
              local_cc = (undefined4 *)0x0;
            }
            else {
              *local_cc = 0;
              local_cc[0x17] = 0;
              local_cc[0x18] = 0;
              *(undefined1 *)(local_cc + 0x19) = 0;
              local_cc[0x1a] = 0;
              local_cc[0x1b] = 0;
              local_cc[0x1c] = 0;
              puVar9 = local_cc;
              for (iVar8 = 0x16; puVar9 = puVar9 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
                *puVar9 = 0;
              }
            }
            iVar8 = FUN_0072e360();
            if (iVar8 != 0) {
              for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                  iVar18 = *(int *)(iVar18 + 0x50)) {
                pcVar12 = (char *)(iVar18 + 0x14);
                if (0xf < *(uint *)(iVar18 + 0x28)) {
                  pcVar12 = *(char **)pcVar12;
                }
                iVar10 = __stricmp(pcVar12,"ProductID");
                if (iVar10 == 0) {
                  if (iVar18 != 0) {
                    puVar9 = (undefined4 *)(iVar18 + 0x30);
                    if (0xf < *(uint *)(iVar18 + 0x44)) {
                      puVar9 = (undefined4 *)*puVar9;
                    }
                    if (puVar9 != (undefined4 *)0x0) {
                      uVar16 = FUN_008917b4(puVar9);
                      goto LAB_00818aa9;
                    }
                  }
                  break;
                }
              }
              uVar16 = 0;
LAB_00818aa9:
              for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                  iVar18 = *(int *)(iVar18 + 0x50)) {
                pcVar12 = (char *)(iVar18 + 0x14);
                if (0xf < *(uint *)(iVar18 + 0x28)) {
                  pcVar12 = *(char **)pcVar12;
                }
                iVar10 = __stricmp(pcVar12,"Qty");
                if (iVar10 == 0) {
                  if (iVar18 != 0) {
                    puVar9 = (undefined4 *)(iVar18 + 0x30);
                    if (0xf < *(uint *)(iVar18 + 0x44)) {
                      puVar9 = (undefined4 *)*puVar9;
                    }
                    if (puVar9 != (undefined4 *)0x0) {
                      uVar4 = FUN_008917b4(puVar9);
                      goto LAB_00818ada;
                    }
                  }
                  break;
                }
              }
              uVar4 = 0;
LAB_00818ada:
              local_cc[0x18] = uVar16;
              *(undefined1 *)(local_cc + 0x19) = uVar4;
            }
            iVar8 = FUN_0072e360();
            if (iVar8 != 0) {
              uVar7 = FUN_0072e360();
              while (local_d4 = uVar7, uVar7 != 0) {
                for (iVar8 = *(int *)(uVar7 + 0x94); iVar8 != uVar7 + 0x44;
                    iVar8 = *(int *)(iVar8 + 0x50)) {
                  pcVar12 = (char *)(iVar8 + 0x14);
                  if (0xf < *(uint *)(iVar8 + 0x28)) {
                    pcVar12 = *(char **)pcVar12;
                  }
                  iVar18 = __stricmp(pcVar12,"PracticeID");
                  if (iVar18 == 0) {
                    if (iVar8 != 0) {
                      puVar9 = (undefined4 *)(iVar8 + 0x30);
                      if (0xf < *(uint *)(iVar8 + 0x44)) {
                        puVar9 = (undefined4 *)*puVar9;
                      }
                      if (puVar9 != (undefined4 *)0x0) {
                        uVar16 = FUN_008917b4(puVar9);
                        goto LAB_00818b5b;
                      }
                    }
                    break;
                  }
                }
                uVar16 = 0;
LAB_00818b5b:
                for (iVar8 = *(int *)(uVar7 + 0x94); iVar8 != uVar7 + 0x44;
                    iVar8 = *(int *)(iVar8 + 0x50)) {
                  pcVar12 = (char *)(iVar8 + 0x14);
                  if (0xf < *(uint *)(iVar8 + 0x28)) {
                    pcVar12 = *(char **)pcVar12;
                  }
                  iVar18 = __stricmp(pcVar12,"Level");
                  if (iVar18 == 0) {
                    if (iVar8 != 0) {
                      puVar9 = (undefined4 *)(iVar8 + 0x30);
                      if (0xf < *(uint *)(iVar8 + 0x44)) {
                        puVar9 = (undefined4 *)*puVar9;
                      }
                      if (puVar9 != (undefined4 *)0x0) {
                        uVar4 = FUN_008917b4(puVar9);
                        goto LAB_00818b8c;
                      }
                    }
                    break;
                  }
                }
                uVar4 = 0;
LAB_00818b8c:
                puVar14 = local_cc;
                local_ec = CONCAT31(local_ec._1_3_,uVar4);
                puVar9 = (undefined4 *)local_cc[0x1b];
                local_f0 = uVar16;
                if (&local_f0 < puVar9) {
                  puVar1 = (undefined4 *)local_cc[0x1a];
                  if (&local_f0 < puVar1) goto LAB_00818cdc;
                  if (puVar9 == (undefined4 *)local_cc[0x1c]) {
                    uVar7 = (int)puVar9 - (int)puVar1 >> 3;
                    if (0x1ffffffe < uVar7) goto LAB_0081920b;
                    uVar7 = uVar7 + 1;
                    uVar15 = (int)local_cc[0x1c] - (int)puVar1 >> 3;
                    if (uVar15 < uVar7) {
                      if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                        uVar15 = 0;
                      }
                      else {
                        uVar15 = uVar15 + (uVar15 >> 1);
                      }
                      if (uVar15 < uVar7) {
                        uVar15 = uVar7;
                      }
                      FUN_004e7330(uVar15);
                    }
                  }
                  puVar2 = (undefined4 *)puVar14[0x1b];
                  puVar9 = (undefined4 *)(puVar14[0x1a] + ((int)&local_f0 - (int)puVar1 >> 3) * 8);
                  if (puVar2 != (undefined4 *)0x0) {
                    *puVar2 = *puVar9;
                    puVar2[1] = puVar9[1];
                  }
                }
                else {
LAB_00818cdc:
                  if (puVar9 == (undefined4 *)local_cc[0x1c]) {
                    uVar7 = (int)puVar9 - local_cc[0x1a] >> 3;
                    if (0x1ffffffe < uVar7) {
LAB_0081920b:
                    /* WARNING: Subroutine does not return */
                      FUN_0087db30("vector<T> too long");
                    }
                    uVar7 = uVar7 + 1;
                    uVar15 = (int)local_cc[0x1c] - local_cc[0x1a] >> 3;
                    if (uVar15 < uVar7) {
                      if (0x1fffffff - (uVar15 >> 1) < uVar15) {
                        uVar15 = 0;
                      }
                      else {
                        uVar15 = uVar15 + (uVar15 >> 1);
                      }
                      if (uVar15 < uVar7) {
                        uVar15 = uVar7;
                      }
                      FUN_004e7330(uVar15);
                    }
                  }
                  puVar9 = (undefined4 *)puVar14[0x1b];
                  if (puVar9 != (undefined4 *)0x0) {
                    *puVar9 = uVar16;
                    puVar9[1] = local_ec;
                  }
                }
                puVar14[0x1b] = puVar14[0x1b] + 8;
                uVar7 = FUN_0072e3c0();
              }
            }
            iVar8 = FUN_0072e360();
            if (iVar8 == 0) {
              local_d4 = FUN_0072e360();
              while (local_d4 != 0) {
                iVar8 = local_d4 + 0x44;
                for (iVar18 = *(int *)(local_d4 + 0x94); iVar18 != iVar8;
                    iVar18 = *(int *)(iVar18 + 0x50)) {
                  pcVar12 = (char *)(iVar18 + 0x14);
                  if (0xf < *(uint *)(iVar18 + 0x28)) {
                    pcVar12 = *(char **)pcVar12;
                  }
                  iVar10 = __stricmp(pcVar12,"tier");
                  if (iVar10 == 0) {
                    if (iVar18 != 0) {
                      puVar9 = (undefined4 *)(iVar18 + 0x30);
                      if (0xf < *(uint *)(iVar18 + 0x44)) {
                        puVar9 = (undefined4 *)*puVar9;
                      }
                      if (puVar9 != (undefined4 *)0x0) {
                        local_d0 = FUN_008917b4(puVar9);
                        goto LAB_00818fa3;
                      }
                    }
                    break;
                  }
                }
                local_d0 = 0;
LAB_00818fa3:
                iVar8 = FUN_0072e360();
                local_e0 = iVar8;
                if (iVar8 != 0) {
                  do {
                    local_e0 = iVar8;
                    for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                        iVar18 = *(int *)(iVar18 + 0x50)) {
                      pcVar12 = (char *)(iVar18 + 0x14);
                      if (0xf < *(uint *)(iVar18 + 0x28)) {
                        pcVar12 = *(char **)pcVar12;
                      }
                      iVar10 = __stricmp(pcVar12,"key");
                      if (iVar10 == 0) {
                        if (iVar18 != 0) {
                          puVar9 = (undefined4 *)(iVar18 + 0x30);
                          if (0xf < *(uint *)(iVar18 + 0x44)) {
                            puVar9 = (undefined4 *)*puVar9;
                          }
                          if (puVar9 != (undefined4 *)0x0) {
                            bVar5 = FUN_008917b4(puVar9);
                            goto LAB_00818ffb;
                          }
                        }
                        break;
                      }
                    }
                    bVar5 = 0;
LAB_00818ffb:
                    for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                        iVar18 = *(int *)(iVar18 + 0x50)) {
                      pcVar12 = (char *)(iVar18 + 0x14);
                      if (0xf < *(uint *)(iVar18 + 0x28)) {
                        pcVar12 = *(char **)pcVar12;
                      }
                      iVar10 = __stricmp(pcVar12,"skill");
                      if (iVar10 == 0) {
                        if (iVar18 != 0) {
                          puVar9 = (undefined4 *)(iVar18 + 0x30);
                          if (0xf < *(uint *)(iVar18 + 0x44)) {
                            puVar9 = (undefined4 *)*puVar9;
                          }
                          if (puVar9 != (undefined4 *)0x0) {
                            uVar6 = FUN_008917b4(puVar9);
                            goto LAB_0081902c;
                          }
                        }
                        break;
                      }
                    }
                    uVar6 = 0;
LAB_0081902c:
                    if (((byte)local_d0 < 4) && (bVar5 < 0xb)) {
                      *(undefined2 *)
                       ((int)local_cc + ((local_d0 & 0xff) * 0xb + (uint)bVar5) * 2 + 4) = uVar6;
                    }
                    iVar8 = FUN_0072e3c0();
                  } while (iVar8 != 0);
                  local_e0 = 0;
                }
                local_d4 = FUN_0072e3c0();
              }
            }
            else {
              local_d0 = FUN_0072e360();
              if (local_d0 != 0) {
                do {
                  iVar8 = local_d0 + 0x44;
                  for (iVar18 = *(int *)(local_d0 + 0x94); iVar18 != iVar8;
                      iVar18 = *(int *)(iVar18 + 0x50)) {
                    pcVar12 = (char *)(iVar18 + 0x14);
                    if (0xf < *(uint *)(iVar18 + 0x28)) {
                      pcVar12 = *(char **)pcVar12;
                    }
                    iVar10 = __stricmp(pcVar12,"tier");
                    if (iVar10 == 0) {
                      if (iVar18 != 0) {
                        puVar9 = (undefined4 *)(iVar18 + 0x30);
                        if (0xf < *(uint *)(iVar18 + 0x44)) {
                          puVar9 = (undefined4 *)*puVar9;
                        }
                        if (puVar9 != (undefined4 *)0x0) {
                          local_d4 = FUN_008917b4(puVar9);
                          goto LAB_00818dd2;
                        }
                      }
                      break;
                    }
                  }
                  local_d4 = 0;
LAB_00818dd2:
                  iVar8 = FUN_0072e360();
                  local_e0 = iVar8;
                  if (iVar8 != 0) {
                    do {
                      local_e0 = iVar8;
                      for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                          iVar18 = *(int *)(iVar18 + 0x50)) {
                        pcVar12 = (char *)(iVar18 + 0x14);
                        if (0xf < *(uint *)(iVar18 + 0x28)) {
                          pcVar12 = *(char **)pcVar12;
                        }
                        iVar10 = __stricmp(pcVar12,"key");
                        if (iVar10 == 0) {
                          if (iVar18 != 0) {
                            puVar9 = (undefined4 *)(iVar18 + 0x30);
                            if (0xf < *(uint *)(iVar18 + 0x44)) {
                              puVar9 = (undefined4 *)*puVar9;
                            }
                            if (puVar9 != (undefined4 *)0x0) {
                              bVar5 = FUN_008917b4(puVar9);
                              goto LAB_00818e2b;
                            }
                          }
                          break;
                        }
                      }
                      bVar5 = 0;
LAB_00818e2b:
                      for (iVar18 = *(int *)(iVar8 + 0x94); iVar18 != iVar8 + 0x44;
                          iVar18 = *(int *)(iVar18 + 0x50)) {
                        pcVar12 = (char *)(iVar18 + 0x14);
                        if (0xf < *(uint *)(iVar18 + 0x28)) {
                          pcVar12 = *(char **)pcVar12;
                        }
                        iVar10 = __stricmp(pcVar12,"skill");
                        if (iVar10 == 0) {
                          if (iVar18 != 0) {
                            puVar9 = (undefined4 *)(iVar18 + 0x30);
                            if (0xf < *(uint *)(iVar18 + 0x44)) {
                              puVar9 = (undefined4 *)*puVar9;
                            }
                            if (puVar9 != (undefined4 *)0x0) {
                              uVar6 = FUN_008917b4(puVar9);
                              goto LAB_00818e5c;
                            }
                          }
                          break;
                        }
                      }
                      uVar6 = 0;
LAB_00818e5c:
                      if (((byte)local_d4 < 4) && (bVar5 < 0xb)) {
                        *(undefined2 *)
                         ((int)local_cc + ((local_d4 & 0xff) * 0xb + (uint)bVar5) * 2 + 4) = uVar6;
                      }
                      iVar8 = FUN_0072e3c0();
                    } while (iVar8 != 0);
                    local_e0 = 0;
                  }
                  local_d0 = FUN_0072e3c0();
                } while (local_d0 != 0);
                local_d0 = 0;
              }
            }
            puVar9 = local_cc;
            FUN_0081a910(local_cc);
            local_d0 = local_dc & 0xffff;
            local_c8 = (undefined1)local_e4;
            FUN_00819460(&local_d0);
            puVar14 = (undefined4 *)FUN_00819650();
            *puVar14 = puVar9;
            local_d8 = FUN_0072e3c0();
          } while (local_d8 != 0);
          local_d8 = 0;
        }
        iVar8 = FUN_0072e3c0();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      local_c4[0] = TiXmlDocument::vftable;
      if (0xf < local_64) {
        FUN_0089120c(local_78);
      }
      local_64 = 0xf;
      local_68 = 0;
      local_78 = local_78 & 0xffffff00;
      FUN_0072e040();
      if (0xf < in_stack_0000001c) {
        FUN_0089120c(param_2);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

