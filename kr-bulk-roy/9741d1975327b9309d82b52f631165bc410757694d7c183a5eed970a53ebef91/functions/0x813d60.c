
void FUN_00813d60(uint *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  float fVar13;
  float *pfVar14;
  float *pfVar15;
  undefined4 *puVar16;
  char *******pppppppcVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  char *pcVar20;
  float *pfVar21;
  int iVar22;
  float10 fVar23;
  double dVar24;
  undefined1 auStack_21c [12];
  undefined4 uStack_210;
  uint *puStack_20c;
  undefined **local_1dc [4];
  undefined **local_1cc [6];
  uint local_1b4;
  uint local_1b0;
  uint local_1ac;
  uint *local_1a8;
  undefined4 *local_1a4;
  int local_1a0;
  undefined4 local_19c;
  char *local_194;
  undefined4 local_190;
  uint *local_188;
  undefined4 *local_184;
  undefined4 local_180;
  undefined4 *local_17c;
  uint *local_178;
  int local_174;
  int local_170;
  undefined1 local_16a;
  undefined1 local_169;
  uint local_168;
  float *local_164;
  undefined4 *local_160;
  uint local_15c;
  uint local_158;
  undefined4 *local_154;
  undefined **local_150;
  uint local_104;
  undefined4 local_f4;
  uint local_f0;
  char ******local_bc [4];
  undefined4 local_ac;
  uint local_a8;
  char ******local_a0 [4];
  undefined4 local_90;
  uint local_8c;
  uint local_84 [4];
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  char ******local_34 [5];
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a3fc;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_188 = param_1;
  FUN_0072ee30();
  local_8 = 0;
  cVar2 = FUN_0072f110();
  if (cVar2 == '\0') {
    puStack_20c = (uint *)0x813de9;
    FUN_006edb60();
    local_8 = 0xffffffff;
    local_150 = TiXmlDocument::vftable;
    if (0xf < local_f0) {
      FUN_0089120c();
    }
    local_f0 = 0xf;
    local_f4 = 0;
    local_104 = local_104 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_0072e360();
    local_174 = FUN_0072e360();
    while (local_174 != 0) {
      iVar7 = FUN_007300a0();
      if (iVar7 == 0) {
LAB_00813ea1:
        local_168 = 0;
      }
      else {
        puVar8 = (undefined4 *)(iVar7 + 0x30);
        if (0xf < *(uint *)(iVar7 + 0x44)) {
          puVar8 = (undefined4 *)*puVar8;
        }
        if (puVar8 == (undefined4 *)0x0) goto LAB_00813ea1;
        local_168 = FUN_008917b4();
      }
      uVar10 = local_188[1];
      local_15c = local_168;
      puVar9 = (uint *)FUN_0082ef00();
      if (*puVar9 == uVar10) {
        iVar7 = FUN_007300a0();
        if (iVar7 == 0) {
LAB_00813f34:
          uVar5 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00813f34;
          uVar5 = FUN_008917b4();
        }
        iVar7 = FUN_007300a0();
        if (iVar7 == 0) {
LAB_00813f5e:
          uVar10 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_00813f5e;
          uVar10 = FUN_008917b4();
        }
        local_15c = uVar10 & 0xffff;
        piVar11 = (int *)FUN_00831f50();
        if (*piVar11 != 0) {
          local_15c = local_168;
          FUN_004a8680();
        }
        local_178 = (uint *)FUN_00891268();
        if (local_178 == (uint *)0x0) {
          local_178 = (uint *)0x0;
        }
        else {
          *local_178 = 0;
          local_178[2] = 0;
          local_178[3] = 1;
          *(undefined2 *)(local_178 + 4) = 0;
          local_178[5] = 0;
          local_178[6] = 0;
          local_178[7] = 0;
        }
        puVar9 = local_178;
        *(undefined2 *)(local_178 + 4) = uVar5;
        *local_178 = uVar10 & 0xffff;
        local_8c = 0xf;
        local_90 = 0;
        local_a0[0] = (char ******)((uint)local_a0[0] & 0xffffff00);
        puStack_20c = (uint *)0x81400d;
        FUN_00402a70();
        local_8._0_1_ = 1;
        FUN_0072ecf0();
        local_8 = (uint)local_8._1_3_ << 8;
        if (0xf < local_8c) {
          FUN_0089120c();
        }
        pppppppcVar17 = (char *******)local_bc[0];
        if (local_a8 < 0x10) {
          pppppppcVar17 = local_bc;
        }
        puStack_20c = (uint *)0x81406c;
        iVar7 = __stricmp("ActiveSkill",(char *)pppppppcVar17);
        if (iVar7 == 0) {
          puVar9[2] = 1;
        }
        else {
          pppppppcVar17 = (char *******)local_bc[0];
          if (local_a8 < 0x10) {
            pppppppcVar17 = local_bc;
          }
          puStack_20c = (uint *)0x81409b;
          iVar7 = __stricmp("Talent",(char *)pppppppcVar17);
          if (iVar7 == 0) {
            puVar9[2] = 2;
          }
        }
        if (0xf < local_a8) {
          FUN_0089120c();
        }
        local_170 = FUN_0072e360();
        uVar10 = local_1ac;
        puVar9 = local_1a8;
        local_1a8 = local_178;
        local_1ac = local_168;
        while (local_178 = local_1a8, local_168 = local_1ac, local_170 != 0) {
          iVar22 = local_170 + 0x44;
          for (iVar7 = *(int *)(local_170 + 0x94); local_1a8 = puVar9, local_1ac = uVar10,
              iVar7 != iVar22; iVar7 = *(int *)(iVar7 + 0x50)) {
            pcVar20 = (char *)(iVar7 + 0x14);
            if (0xf < *(uint *)(iVar7 + 0x28)) {
              pcVar20 = *(char **)pcVar20;
            }
            puStack_20c = (uint *)0x814115;
            iVar12 = __stricmp(pcVar20,"Level");
            if (iVar12 == 0) {
              if (iVar7 != 0) {
                puVar8 = (undefined4 *)(iVar7 + 0x30);
                if (0xf < *(uint *)(iVar7 + 0x44)) {
                  puVar8 = (undefined4 *)*puVar8;
                }
                if (puVar8 != (undefined4 *)0x0) {
                  local_180 = FUN_008917b4();
                  goto LAB_00814131;
                }
              }
              break;
            }
            uVar10 = local_1ac;
            puVar9 = local_1a8;
          }
          local_180 = 0;
LAB_00814131:
          iVar7 = FUN_0072e360();
          if (iVar7 != 0) {
            puStack_20c = local_188;
            uStack_210 = 0x81415f;
            FUN_008166a0();
          }
          iVar7 = FUN_0072e360();
          if (iVar7 != 0) {
            puVar8 = (undefined4 *)FUN_0072e360();
            local_154 = puVar8;
            while (puVar8 != (undefined4 *)0x0) {
              local_70 = 0xf;
              local_74 = 0;
              local_84[0] = local_84[0] & 0xffffff00;
              puStack_20c = (uint *)0x8141b3;
              FUN_00402a70();
              local_8._0_1_ = 2;
              FUN_0072ecf0();
              local_8 = CONCAT31(local_8._1_3_,4);
              if (0xf < local_70) {
                FUN_0089120c();
              }
              local_70 = 0xf;
              local_74 = 0;
              local_84[0] = local_84[0] & 0xffffff00;
              pppppppcVar17 = (char *******)local_34[0];
              if (local_20 < 0x10) {
                pppppppcVar17 = local_34;
              }
              puStack_20c = (uint *)0x814206;
              iVar7 = __stricmp((char *)pppppppcVar17,"CharStat");
              if (iVar7 == 0) {
                for (puVar16 = (undefined4 *)puVar8[0x25]; puVar16 != puVar8 + 0x11;
                    puVar16 = (undefined4 *)puVar16[0x14]) {
                  pcVar20 = (char *)(puVar16 + 5);
                  if (0xf < (uint)puVar16[10]) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814236;
                  iVar7 = __stricmp(pcVar20,"StatID");
                  if (iVar7 == 0) {
                    if (puVar16 != (undefined4 *)0x0) {
                      puVar19 = puVar16 + 0xc;
                      if (0xf < (uint)puVar16[0x11]) {
                        puVar19 = (undefined4 *)*puVar19;
                      }
                      if (puVar19 != (undefined4 *)0x0) {
                        uVar3 = FUN_008917b4();
                        goto LAB_0081424a;
                      }
                    }
                    break;
                  }
                }
                uVar3 = 0;
LAB_0081424a:
                for (puVar16 = (undefined4 *)puVar8[0x25]; puVar16 != puVar8 + 0x11;
                    puVar16 = (undefined4 *)puVar16[0x14]) {
                  pcVar20 = (char *)(puVar16 + 5);
                  if (0xf < (uint)puVar16[10]) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814267;
                  iVar7 = __stricmp(pcVar20,"Value");
                  if (iVar7 == 0) {
                    if (puVar16 != (undefined4 *)0x0) {
                      puVar8 = puVar16 + 0xc;
                      if (0xf < (uint)puVar16[0x11]) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar6 = FUN_008917b4();
                        goto LAB_0081427b;
                      }
                    }
                    break;
                  }
                }
                uVar6 = 0;
LAB_0081427b:
                puVar8 = (undefined4 *)FUN_00891268();
                if (puVar8 == (undefined4 *)0x0) {
                  uRam00000004 = CONCAT11(uRam00000004._1_1_,uVar3);
                  uVar5 = uRam00000004;
                  uRam00000006 = uVar6;
                  uVar6 = uRam00000008;
                }
                else {
                  *puVar8 = CCharStatusModifier::vftable;
                  *(undefined1 *)(puVar8 + 1) = uVar3;
                  *(undefined2 *)((int)puVar8 + 6) = uVar6;
                  uVar5 = uRam00000004;
                  uVar6 = uRam00000008;
                }
              }
              else {
                pppppppcVar17 = (char *******)local_34[0];
                if (local_20 < 0x10) {
                  pppppppcVar17 = local_34;
                }
                puStack_20c = (uint *)0x814357;
                iVar7 = __stricmp((char *)pppppppcVar17,"SkillLevel");
                if (iVar7 == 0) {
                  for (puVar16 = (undefined4 *)puVar8[0x25]; puVar16 != puVar8 + 0x11;
                      puVar16 = (undefined4 *)puVar16[0x14]) {
                    pcVar20 = (char *)(puVar16 + 5);
                    if (0xf < (uint)puVar16[10]) {
                      pcVar20 = *(char **)pcVar20;
                    }
                    puStack_20c = (uint *)0x814386;
                    iVar7 = __stricmp(pcVar20,"TargetSkillID");
                    if (iVar7 == 0) {
                      if (puVar16 != (undefined4 *)0x0) {
                        puVar19 = puVar16 + 0xc;
                        if (0xf < (uint)puVar16[0x11]) {
                          puVar19 = (undefined4 *)*puVar19;
                        }
                        if (puVar19 != (undefined4 *)0x0) {
                          local_158 = FUN_008917b4();
                          goto LAB_008143a7;
                        }
                      }
                      break;
                    }
                  }
                  local_158 = 0;
LAB_008143a7:
                  local_15c = local_158;
                  for (puVar16 = (undefined4 *)puVar8[0x25]; puVar16 != puVar8 + 0x11;
                      puVar16 = (undefined4 *)puVar16[0x14]) {
                    pcVar20 = (char *)(puVar16 + 5);
                    if (0xf < (uint)puVar16[10]) {
                      pcVar20 = *(char **)pcVar20;
                    }
                    puStack_20c = (uint *)0x8143d5;
                    iVar7 = __stricmp(pcVar20,"Value");
                    if (iVar7 == 0) {
                      if (puVar16 != (undefined4 *)0x0) {
                        puVar8 = puVar16 + 0xc;
                        if (0xf < (uint)puVar16[0x11]) {
                          puVar8 = (undefined4 *)*puVar8;
                        }
                        if (puVar8 != (undefined4 *)0x0) {
                          uVar5 = FUN_008917b4();
                          goto LAB_008143e8;
                        }
                      }
                      break;
                    }
                  }
                  uVar5 = 1;
LAB_008143e8:
                  puVar8 = (undefined4 *)FUN_00891268();
                  if (puVar8 == (undefined4 *)0x0) {
                    puVar8 = (undefined4 *)0x0;
                  }
                  else {
                    *(undefined2 *)(puVar8 + 1) = 0;
                    *puVar8 = CSkillModifier_SkillLevel::vftable;
                  }
                  *(undefined2 *)(puVar8 + 1) = (undefined2)local_158;
                  *(undefined2 *)(puVar8 + 2) = uVar5;
                  uVar5 = uRam00000004;
                  uVar6 = uRam00000008;
                  if ((local_178[2] == 1) &&
                     (uVar10 = local_188[9], puVar9 = (uint *)FUN_008438c0(), uVar5 = uRam00000004,
                     uVar6 = uRam00000008, *puVar9 == uVar10)) {
                    local_1b4 = local_158;
                    local_1b0 = local_168;
                    FUN_0057ef20();
                    puStack_20c = (uint *)0x8144c5;
                    FUN_0057e850();
                    uVar5 = uRam00000004;
                    uVar6 = uRam00000008;
                  }
                }
                else {
                  pppppppcVar17 = (char *******)local_34[0];
                  if (local_20 < 0x10) {
                    pppppppcVar17 = local_34;
                  }
                  puStack_20c = (uint *)0x8144e8;
                  iVar7 = __stricmp((char *)pppppppcVar17,"SkillScriptLevel");
                  if (iVar7 == 0) {
                    for (puVar16 = (undefined4 *)puVar8[0x25]; puVar16 != puVar8 + 0x11;
                        puVar16 = (undefined4 *)puVar16[0x14]) {
                      pcVar20 = (char *)(puVar16 + 5);
                      if (0xf < (uint)puVar16[10]) {
                        pcVar20 = *(char **)pcVar20;
                      }
                      puStack_20c = (uint *)0x814516;
                      iVar7 = __stricmp(pcVar20,"TargetSkillID");
                      if (iVar7 == 0) {
                        if (puVar16 != (undefined4 *)0x0) {
                          puVar19 = puVar16 + 0xc;
                          if (0xf < (uint)puVar16[0x11]) {
                            puVar19 = (undefined4 *)*puVar19;
                          }
                          if (puVar19 != (undefined4 *)0x0) {
                            uVar5 = FUN_008917b4();
                            goto LAB_00814526;
                          }
                        }
                        break;
                      }
                    }
                    uVar5 = 0;
LAB_00814526:
                    for (puVar16 = (undefined4 *)puVar8[0x25]; puVar16 != puVar8 + 0x11;
                        puVar16 = (undefined4 *)puVar16[0x14]) {
                      pcVar20 = (char *)(puVar16 + 5);
                      if (0xf < (uint)puVar16[10]) {
                        pcVar20 = *(char **)pcVar20;
                      }
                      puStack_20c = (uint *)0x814546;
                      iVar7 = __stricmp(pcVar20,"Level");
                      if (iVar7 == 0) {
                        if (puVar16 != (undefined4 *)0x0) {
                          puVar8 = puVar16 + 0xc;
                          if (0xf < (uint)puVar16[0x11]) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 != (undefined4 *)0x0) {
                            uVar6 = FUN_008917b4();
                            goto LAB_00814556;
                          }
                        }
                        break;
                      }
                    }
                    uVar6 = 0;
LAB_00814556:
                    puVar8 = (undefined4 *)FUN_00891268();
                    if (puVar8 != (undefined4 *)0x0) {
                      *(undefined2 *)(puVar8 + 1) = 0;
                      *puVar8 = CSkillModifier_SkillScriptType::vftable;
                      *(undefined2 *)(puVar8 + 1) = uVar5;
                      *(undefined2 *)(puVar8 + 2) = uVar6;
                      uVar5 = uRam00000004;
                      uVar6 = uRam00000008;
                    }
                  }
                  else {
                    pppppppcVar17 = (char *******)local_34[0];
                    if (local_20 < 0x10) {
                      pppppppcVar17 = local_34;
                    }
                    puStack_20c = (uint *)0x8145ef;
                    __stricmp((char *)pppppppcVar17,"Dispell");
                    uVar5 = uRam00000004;
                    uVar6 = uRam00000008;
                  }
                }
              }
              uRam00000008 = uVar6;
              uRam00000004 = uVar5;
              puStack_20c = local_178;
              uStack_210 = 0x814606;
              FUN_0081aab0();
              puVar8 = (undefined4 *)FUN_0072e3c0();
              local_8 = local_8 & 0xffffff00;
              local_154 = puVar8;
              if (0xf < local_20) {
                FUN_0089120c();
              }
            }
          }
          iVar7 = FUN_0072e360();
          if (iVar7 != 0) {
            local_15c = 0;
            uVar10 = FUN_0072e360();
            local_158 = uVar10;
            while (uVar10 != 0) {
              local_8c = 0xf;
              local_90 = 0;
              local_a0[0] = (char ******)((uint)local_a0[0] & 0xffffff00);
              puStack_20c = (uint *)0x81469f;
              FUN_00402a70();
              local_8._0_1_ = 5;
              FUN_0072ecf0();
              local_8._0_1_ = 7;
              if (0xf < local_8c) {
                FUN_0089120c();
              }
              local_8c = 0xf;
              local_90 = 0;
              local_a0[0] = (char ******)((uint)local_a0[0] & 0xffffff00);
              local_a8 = 0xf;
              local_ac = 0;
              local_bc[0] = (char ******)((uint)local_bc[0] & 0xffffff00);
              puStack_20c = (uint *)0x814711;
              FUN_00402a70();
              local_8._0_1_ = 8;
              FUN_0072ecf0();
              local_8 = CONCAT31(local_8._1_3_,10);
              if (0xf < local_a8) {
                FUN_0089120c();
              }
              local_164 = (float *)auStack_21c;
              puStack_20c = (uint *)0x0;
              local_a8 = 0xf;
              local_ac = 0;
              local_bc[0] = (char ******)((uint)local_bc[0] & 0xffffff00);
              auStack_21c[0] = 0;
              FUN_00403040(local_84,0,0xffffffff);
              uVar5 = FUN_00816ea0();
              local_154 = (undefined4 *)FUN_00891268();
              if (local_154 == (undefined4 *)0x0) {
                local_154 = (undefined4 *)0x0;
              }
              else {
                *(undefined2 *)(local_154 + 1) = 0;
                *local_154 = CSkillInterrupt::vftable;
                local_154[2] = 0;
                local_154[3] = 0;
                local_154[4] = 0;
                local_154[6] = 0;
                local_154[7] = 0;
                local_154[8] = 0;
              }
              *(undefined2 *)(local_154 + 1) = uVar5;
              iVar7 = FUN_0072e360();
              if (iVar7 != 0) {
                for (iVar22 = *(int *)(iVar7 + 0x94); iVar22 != iVar7 + 0x44;
                    iVar22 = *(int *)(iVar22 + 0x50)) {
                  pcVar20 = (char *)(iVar22 + 0x14);
                  if (0xf < *(uint *)(iVar22 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814805;
                  iVar12 = __stricmp(pcVar20,"Effect");
                  if (iVar12 == 0) {
                    if (iVar22 != 0) {
                      puVar8 = (undefined4 *)(iVar22 + 0x30);
                      if (0xf < *(uint *)(iVar22 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar18 = FUN_008917b4();
                        goto LAB_00814819;
                      }
                    }
                    break;
                  }
                }
                uVar18 = 0;
LAB_00814819:
                for (iVar22 = *(int *)(iVar7 + 0x94); iVar22 != iVar7 + 0x44;
                    iVar22 = *(int *)(iVar22 + 0x50)) {
                  pcVar20 = (char *)(iVar22 + 0x14);
                  if (0xf < *(uint *)(iVar22 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814836;
                  iVar12 = __stricmp(pcVar20,"NeedMessage");
                  if (iVar12 == 0) {
                    if (iVar22 != 0) {
                      pcVar20 = (char *)(iVar22 + 0x30);
                      if (0xf < *(uint *)(iVar22 + 0x44)) {
                        pcVar20 = *(char **)pcVar20;
                      }
                      if (pcVar20 != (char *)0x0) {
                        puStack_20c = (uint *)0x814974;
                        iVar7 = __stricmp(pcVar20,"true");
                        uVar10 = (uint)(iVar7 == 0);
                        goto LAB_0081484a;
                      }
                    }
                    break;
                  }
                }
                uVar10 = 0;
LAB_0081484a:
                local_154[8] = uVar18;
                local_154[7] = uVar10;
                uVar10 = local_158;
              }
              iVar7 = FUN_0072e360();
              if (iVar7 != 0) {
                FUN_008159e0();
              }
              pppppppcVar17 = (char *******)local_34[0];
              if (local_20 < 0x10) {
                pppppppcVar17 = local_34;
              }
              puStack_20c = (uint *)0x814896;
              iVar7 = __stricmp((char *)pppppppcVar17,"Consume");
              if (iVar7 == 0) {
                puVar8 = (undefined4 *)FUN_00891268();
                local_160 = puVar8;
                if (puVar8 == (undefined4 *)0x0) {
                  local_17c = (undefined4 *)0x0;
                }
                else {
                  puVar8[1] = 1;
                  local_8 = CONCAT31(local_8._1_3_,0xc);
                  *puVar8 = CSkillInterrupt_Consume::vftable;
                  puVar8[2] = 0;
                  puVar8[3] = 0;
                  puVar8[4] = 0;
                  puVar8[7] = 0;
                  iVar7 = FUN_00891268();
                  if (iVar7 == 0) {
                    local_164 = (float *)0x0;
                    std::exception::exception((exception *)local_1dc,(char **)&local_164);
                    local_1dc[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                    puStack_20c = (uint *)0x8159a6;
                    __CxxThrowException_8();
                  }
                  puVar8[6] = iVar7;
                  *(int *)iVar7 = iVar7;
                  *(undefined4 *)(puVar8[6] + 4) = puVar8[6];
                  *(undefined4 *)(puVar8[6] + 8) = puVar8[6];
                  *(undefined1 *)(puVar8[6] + 0x10) = 1;
                  *(undefined1 *)(puVar8[6] + 0x11) = 1;
                  puVar8[0xb] = 0;
                  puVar8[9] = 0;
                  puVar8[10] = 0;
                  local_17c = puVar8;
                }
                local_8._0_1_ = 10;
                *(undefined2 *)(local_154 + 1) = 1;
                local_5c = 0;
                local_58 = 0.0;
                local_54 = 0.0;
                local_48 = 0.0;
                fVar13 = (float)FUN_00891268();
                uVar10 = local_158;
                if (fVar13 == 0.0) {
                  local_194 = (char *)0x0;
                  std::exception::exception((exception *)local_1cc,&local_194);
                  local_1cc[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                  puStack_20c = (uint *)&UNK_008159d9;
                  __CxxThrowException_8();
                }
                *(float *)fVar13 = fVar13;
                *(float *)((int)fVar13 + 4) = fVar13;
                *(float *)((int)fVar13 + 8) = fVar13;
                *(undefined1 *)((int)fVar13 + 0x10) = 1;
                *(undefined1 *)((int)fVar13 + 0x11) = 1;
                local_38 = (undefined4 *)0x0;
                local_40 = 0;
                local_3c = 0;
                iVar22 = local_158 + 0x44;
                local_8 = CONCAT31(local_8._1_3_,0xd);
                local_4c = fVar13;
                for (iVar7 = *(int *)(local_158 + 0x94); iVar7 != iVar22;
                    iVar7 = *(int *)(iVar7 + 0x50)) {
                  pcVar20 = (char *)(iVar7 + 0x14);
                  if (0xf < *(uint *)(iVar7 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814a16;
                  iVar12 = __stricmp(pcVar20,"HP");
                  if (iVar12 == 0) {
                    if (iVar7 != 0) {
                      puVar8 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar5 = FUN_008917b4();
                        goto LAB_00814a2a;
                      }
                    }
                    break;
                  }
                }
                uVar5 = 0;
LAB_00814a2a:
                iVar7 = *(int *)(uVar10 + 0x94);
                local_5c = CONCAT22(local_5c._2_2_,uVar5);
                for (; iVar7 != iVar22; iVar7 = *(int *)(iVar7 + 0x50)) {
                  pcVar20 = (char *)(iVar7 + 0x14);
                  if (0xf < *(uint *)(iVar7 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814a4a;
                  iVar12 = __stricmp(pcVar20,"SP");
                  if (iVar12 == 0) {
                    if (iVar7 != 0) {
                      puVar8 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar5 = FUN_008917b4();
                        goto LAB_00814a5e;
                      }
                    }
                    break;
                  }
                }
                uVar5 = 0;
LAB_00814a5e:
                iVar7 = *(int *)(uVar10 + 0x94);
                local_5c = CONCAT22(uVar5,(undefined2)local_5c);
                for (; iVar7 != iVar22; iVar7 = *(int *)(iVar7 + 0x50)) {
                  pcVar20 = (char *)(iVar7 + 0x14);
                  if (0xf < *(uint *)(iVar7 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814a85;
                  iVar12 = __stricmp(pcVar20,"MP");
                  if (iVar12 == 0) {
                    if (iVar7 != 0) {
                      puVar8 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar5 = FUN_008917b4();
                        goto LAB_00814a99;
                      }
                    }
                    break;
                  }
                }
                uVar5 = 0;
LAB_00814a99:
                iVar7 = *(int *)(uVar10 + 0x94);
                local_58 = (float)CONCAT22(local_58._2_2_,uVar5);
                for (; iVar7 != iVar22; iVar7 = *(int *)(iVar7 + 0x50)) {
                  pcVar20 = (char *)(iVar7 + 0x14);
                  if (0xf < *(uint *)(iVar7 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814ab9;
                  iVar12 = __stricmp(pcVar20,"HPPercent");
                  if (iVar12 == 0) {
                    if (iVar7 != 0) {
                      puVar8 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar5 = FUN_008917b4();
                        goto LAB_00814acd;
                      }
                    }
                    break;
                  }
                }
                uVar5 = 0;
LAB_00814acd:
                iVar7 = *(int *)(uVar10 + 0x94);
                local_58 = (float)CONCAT22(uVar5,(undefined2)local_58);
                for (; iVar7 != iVar22; iVar7 = *(int *)(iVar7 + 0x50)) {
                  pcVar20 = (char *)(iVar7 + 0x14);
                  if (0xf < *(uint *)(iVar7 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814aed;
                  iVar12 = __stricmp(pcVar20,"SPPercent");
                  if (iVar12 == 0) {
                    if (iVar7 != 0) {
                      puVar8 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar5 = FUN_008917b4();
                        goto LAB_00814b01;
                      }
                    }
                    break;
                  }
                }
                uVar5 = 0;
LAB_00814b01:
                iVar7 = *(int *)(uVar10 + 0x94);
                local_54 = (float)CONCAT22(local_54._2_2_,uVar5);
                for (; iVar7 != iVar22; iVar7 = *(int *)(iVar7 + 0x50)) {
                  pcVar20 = (char *)(iVar7 + 0x14);
                  if (0xf < *(uint *)(iVar7 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814b25;
                  iVar12 = __stricmp(pcVar20,"MPPercent");
                  if (iVar12 == 0) {
                    if (iVar7 != 0) {
                      puVar8 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        uVar5 = FUN_008917b4();
                        goto LAB_00814b39;
                      }
                    }
                    break;
                  }
                }
                uVar5 = 0;
LAB_00814b39:
                local_54 = (float)CONCAT22(uVar5,(undefined2)local_54);
                FUN_0072e360();
                for (iVar7 = *(int *)(uVar10 + 0x94); iVar7 != iVar22;
                    iVar7 = *(int *)(iVar7 + 0x50)) {
                  pcVar20 = (char *)(iVar7 + 0x14);
                  if (0xf < *(uint *)(iVar7 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814b75;
                  iVar12 = __stricmp(pcVar20,"Cooltime");
                  if (iVar12 == 0) {
                    if (iVar7 != 0) {
                      puVar8 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar8 = (undefined4 *)*puVar8;
                      }
                      if (puVar8 != (undefined4 *)0x0) {
                        local_3c = FUN_008917b4();
                        goto LAB_00814b89;
                      }
                    }
                    break;
                  }
                }
                local_3c = 0;
LAB_00814b89:
                for (iVar7 = *(int *)(uVar10 + 0x94); iVar7 != iVar22;
                    iVar7 = *(int *)(iVar7 + 0x50)) {
                  pcVar20 = (char *)(iVar7 + 0x14);
                  if (0xf < *(uint *)(iVar7 + 0x28)) {
                    pcVar20 = *(char **)pcVar20;
                  }
                  puStack_20c = (uint *)0x814ba8;
                  iVar12 = __stricmp(pcVar20,"CooltimeRatio");
                  if (iVar12 == 0) {
                    if (iVar7 != 0) {
                      pcVar20 = (char *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        pcVar20 = *(char **)pcVar20;
                      }
                      if (pcVar20 != (char *)0x0) {
                        dVar24 = _atof(pcVar20);
                        local_184 = (undefined4 *)(float)dVar24;
                        goto LAB_00814bc2;
                      }
                    }
                    break;
                  }
                }
                local_184 = (undefined4 *)0x0;
LAB_00814bc2:
                puVar8 = local_17c;
                local_38 = local_184;
                *(undefined2 *)(local_17c + 2) = (undefined2)local_5c;
                *(undefined2 *)((int)local_17c + 10) = local_5c._2_2_;
                *(undefined2 *)(local_17c + 3) = (undefined2)local_58;
                *(undefined2 *)((int)local_17c + 0xe) = local_58._2_2_;
                *(undefined2 *)(local_17c + 4) = (undefined2)local_54;
                *(undefined2 *)((int)local_17c + 0x12) = local_54._2_2_;
                if ((float *)(local_17c + 5) != &local_50) {
                  puStack_20c = (uint *)0x814c1f;
                  FUN_004ca160();
                  FUN_005cfc80();
                }
                puVar8[9] = local_40;
                puVar8[10] = local_3c;
                local_164 = &local_50;
                puVar8[0xb] = local_38;
                local_154[6] = puVar8;
                local_8._0_1_ = 0xe;
                puStack_20c = (uint *)0x814c67;
                FUN_004ca160();
                local_8 = CONCAT31(local_8._1_3_,10);
                FUN_0089120c();
              }
              else {
                pppppppcVar17 = (char *******)local_34[0];
                if (local_20 < 0x10) {
                  pppppppcVar17 = local_34;
                }
                puStack_20c = (uint *)0x814dd8;
                iVar7 = __stricmp((char *)pppppppcVar17,"Skillcast");
                if (iVar7 == 0) {
                  local_184 = (undefined4 *)FUN_00891268();
                  if (local_184 == (undefined4 *)0x0) {
                    local_184 = (undefined4 *)0x0;
                  }
                  else {
                    local_184[1] = 6;
                    *local_184 = CSkillInterrupt_SkillInvoker::vftable;
                  }
                  pfVar15 = (float *)(uVar10 + 0x44);
                  local_164 = pfVar15;
                  for (pfVar21 = *(float **)(uVar10 + 0x94); pfVar21 != pfVar15;
                      pfVar21 = (float *)pfVar21[0x14]) {
                    pfVar14 = pfVar21 + 5;
                    if (0xf < (uint)pfVar21[10]) {
                      pfVar14 = (float *)*pfVar14;
                    }
                    puStack_20c = (uint *)0x814e38;
                    iVar7 = __stricmp((char *)pfVar14,"SkillID");
                    if (iVar7 == 0) {
                      if (pfVar21 != (float *)0x0) {
                        pfVar14 = pfVar21 + 0xc;
                        if (0xf < (uint)pfVar21[0x11]) {
                          pfVar14 = (float *)*pfVar14;
                        }
                        if (pfVar14 != (float *)0x0) {
                          local_17c = (undefined4 *)FUN_008917b4();
                          goto LAB_00814e59;
                        }
                      }
                      break;
                    }
                  }
                  local_17c = (undefined4 *)0x0;
LAB_00814e59:
                  for (pfVar21 = *(float **)(uVar10 + 0x94); pfVar21 != pfVar15;
                      pfVar21 = (float *)pfVar21[0x14]) {
                    pfVar14 = pfVar21 + 5;
                    if (0xf < (uint)pfVar21[10]) {
                      pfVar14 = (float *)*pfVar14;
                    }
                    puStack_20c = (uint *)0x814e75;
                    iVar7 = __stricmp((char *)pfVar14,"SkillLevel");
                    if (iVar7 == 0) {
                      if (pfVar21 != (float *)0x0) {
                        pfVar14 = pfVar21 + 0xc;
                        if (0xf < (uint)pfVar21[0x11]) {
                          pfVar14 = (float *)*pfVar14;
                        }
                        if (pfVar14 != (float *)0x0) {
                          local_160 = (undefined4 *)FUN_008917b4();
                          goto LAB_00814e91;
                        }
                      }
                      break;
                    }
                  }
                  local_160 = (undefined4 *)0x0;
LAB_00814e91:
                  for (pfVar21 = *(float **)(uVar10 + 0x94); pfVar21 != pfVar15;
                      pfVar21 = (float *)pfVar21[0x14]) {
                    pfVar14 = pfVar21 + 5;
                    if (0xf < (uint)pfVar21[10]) {
                      pfVar14 = (float *)*pfVar14;
                    }
                    puStack_20c = (uint *)0x814ead;
                    iVar7 = __stricmp((char *)pfVar14,"SkillScriptLevel");
                    if (iVar7 == 0) {
                      if (pfVar21 != (float *)0x0) {
                        pfVar14 = pfVar21 + 0xc;
                        if (0xf < (uint)pfVar21[0x11]) {
                          pfVar14 = (float *)*pfVar14;
                        }
                        if (pfVar14 != (float *)0x0) {
                          uVar3 = FUN_008917b4();
                          goto LAB_00814ec1;
                        }
                      }
                      break;
                    }
                  }
                  uVar3 = 0;
LAB_00814ec1:
                  pfVar21 = *(float **)(uVar10 + 0x94);
                  if (pfVar21 != pfVar15) {
                    do {
                      pfVar15 = pfVar21 + 5;
                      if (0xf < (uint)pfVar21[10]) {
                        pfVar15 = (float *)*pfVar15;
                      }
                      puStack_20c = (uint *)0x814ee5;
                      iVar7 = __stricmp((char *)pfVar15,"SkillLook");
                      if (iVar7 == 0) {
                        if (pfVar21 != (float *)0x0) {
                          pfVar15 = pfVar21 + 0xc;
                          if (0xf < (uint)pfVar21[0x11]) {
                            pfVar15 = (float *)*pfVar15;
                          }
                          if (pfVar15 != (float *)0x0) {
                            uVar5 = FUN_008917b4();
                            goto LAB_00814efd;
                          }
                        }
                        break;
                      }
                      pfVar21 = (float *)pfVar21[0x14];
                    } while (pfVar21 != local_164);
                  }
                  uVar5 = 0;
LAB_00814efd:
                  *(undefined2 *)(local_184 + 3) = uVar5;
                  *(undefined2 *)(local_184 + 2) = local_17c._0_2_;
                  *(undefined1 *)((int)local_184 + 10) = local_160._0_1_;
                  *(undefined1 *)((int)local_184 + 0xb) = uVar3;
                  local_154[6] = local_184;
                }
                else {
                  pppppppcVar17 = (char *******)local_34[0];
                  if (local_20 < 0x10) {
                    pppppppcVar17 = local_34;
                  }
                  puStack_20c = (uint *)0x814ff5;
                  iVar7 = __stricmp((char *)pppppppcVar17,"SkillLevel");
                  if (iVar7 == 0) {
                    puVar8 = (undefined4 *)FUN_00891268();
                    if (puVar8 == (undefined4 *)0x0) {
                      puVar8 = (undefined4 *)0x0;
                    }
                    else {
                      puVar8[1] = 2;
                      *puVar8 = CSkillInterrupt_SkillLevel::vftable;
                    }
                    *(undefined2 *)(local_154 + 1) = 1;
                    iVar7 = FUN_007300a0();
                    if (iVar7 == 0) {
LAB_00815063:
                      uVar5 = 0;
                    }
                    else {
                      puVar16 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar16 = (undefined4 *)*puVar16;
                      }
                      if (puVar16 == (undefined4 *)0x0) goto LAB_00815063;
                      uVar5 = FUN_008917b4();
                    }
                    iVar7 = FUN_007300a0();
                    if (iVar7 != 0) {
                      puVar16 = (undefined4 *)(iVar7 + 0x30);
                      if (0xf < *(uint *)(iVar7 + 0x44)) {
                        puVar16 = (undefined4 *)*puVar16;
                      }
                      if (puVar16 != (undefined4 *)0x0) {
                        uVar3 = FUN_008917b4();
                        *(undefined1 *)((int)puVar8 + 10) = uVar3;
                        *(undefined2 *)(puVar8 + 2) = uVar5;
                        local_154[6] = puVar8;
                        goto LAB_008157df;
                      }
                    }
                    *(undefined1 *)((int)puVar8 + 10) = 0;
                    *(undefined2 *)(puVar8 + 2) = uVar5;
                    local_154[6] = puVar8;
                  }
                  else {
                    pppppppcVar17 = (char *******)local_34[0];
                    if (local_20 < 0x10) {
                      pppppppcVar17 = local_34;
                    }
                    puStack_20c = (uint *)0x8150cd;
                    iVar7 = __stricmp((char *)pppppppcVar17,"SkillData");
                    if (iVar7 == 0) {
                      puVar8 = (undefined4 *)FUN_00891268();
                      if (puVar8 == (undefined4 *)0x0) {
                        puVar8 = (undefined4 *)0x0;
                      }
                      else {
                        puVar8[1] = 3;
                        *puVar8 = CSkillInterrupt_SkillData::vftable;
                        *(undefined1 *)(puVar8 + 2) = 0;
                      }
                      *(undefined2 *)(local_154 + 1) = 1;
                      iVar7 = FUN_007300a0();
                      if (iVar7 != 0) {
                        puVar16 = (undefined4 *)(iVar7 + 0x30);
                        if (0xf < *(uint *)(iVar7 + 0x44)) {
                          puVar16 = (undefined4 *)*puVar16;
                        }
                        if (puVar16 != (undefined4 *)0x0) {
                          uVar3 = FUN_008917b4();
                          *(undefined1 *)(puVar8 + 2) = uVar3;
                          local_154[6] = puVar8;
                          goto LAB_008157df;
                        }
                      }
                      *(undefined1 *)(puVar8 + 2) = 0;
                      local_154[6] = puVar8;
                    }
                    else {
                      pppppppcVar17 = (char *******)local_34[0];
                      if (local_20 < 0x10) {
                        pppppppcVar17 = local_34;
                      }
                      puStack_20c = (uint *)0x81516f;
                      iVar7 = __stricmp((char *)pppppppcVar17,"AttackFactor");
                      if (iVar7 == 0) {
                        iVar7 = FUN_00891268();
                        if (iVar7 == 0) {
                          local_160 = (undefined4 *)0x0;
                        }
                        else {
                          local_160 = (undefined4 *)FUN_0082cb30();
                        }
                        *(undefined2 *)(local_154 + 1) = 3;
                        local_44 = 0;
                        local_40 = 0;
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_008151e0:
                          local_68._0_2_ = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_008151e0;
                          local_68._0_2_ = FUN_008917b4();
                        }
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_0081520d:
                          local_68._2_2_ = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_0081520d;
                          local_68._2_2_ = FUN_008917b4();
                        }
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_0081523a:
                          local_64 = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_0081523a;
                          local_64 = FUN_008917b4();
                        }
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_00815266:
                          local_63 = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_00815266;
                          local_63 = FUN_008917b4();
                        }
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_00815292:
                          local_62 = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_00815292;
                          local_62 = FUN_008917b4();
                        }
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_008152be:
                          local_60 = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_008152be;
                          local_60 = FUN_008917b4();
                        }
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_008152ea:
                          local_5c = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_008152ea;
                          local_5c = FUN_008917b4();
                        }
                        fVar23 = (float10)FUN_0072e690();
                        local_58 = (float)fVar23;
                        fVar23 = (float10)FUN_0072e690();
                        local_54 = (float)fVar23;
                        fVar23 = (float10)FUN_0072e690();
                        local_50 = (float)fVar23;
                        fVar23 = (float10)FUN_0072e690();
                        local_4c = (float)fVar23;
                        fVar23 = (float10)FUN_0072e690();
                        local_48 = (float)fVar23;
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_0081537f:
                          uVar5 = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_0081537f;
                          uVar5 = FUN_008917b4();
                        }
                        local_3c = CONCAT22(local_3c._2_2_,uVar5);
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_008153ac:
                          uVar5 = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_008153ac;
                          uVar5 = FUN_008917b4();
                        }
                        local_3c = CONCAT22(uVar5,(undefined2)local_3c);
                        iVar7 = FUN_007300a0();
                        if (iVar7 == 0) {
LAB_008153d9:
                          uVar5 = 0;
                        }
                        else {
                          puVar8 = (undefined4 *)(iVar7 + 0x30);
                          if (0xf < *(uint *)(iVar7 + 0x44)) {
                            puVar8 = (undefined4 *)*puVar8;
                          }
                          if (puVar8 == (undefined4 *)0x0) goto LAB_008153d9;
                          uVar5 = FUN_008917b4();
                        }
                        local_38 = (undefined4 *)CONCAT22(local_38._2_2_,uVar5);
                        puVar8 = &local_68;
                        puVar16 = local_160 + 2;
                        for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
                          *puVar16 = *puVar8;
                          puVar8 = puVar8 + 1;
                          puVar16 = puVar16 + 1;
                        }
                        local_154[6] = local_160;
                      }
                      else {
                        pppppppcVar17 = (char *******)local_34[0];
                        if (local_20 < 0x10) {
                          pppppppcVar17 = local_34;
                        }
                        puStack_20c = (uint *)0x815416;
                        iVar7 = __stricmp((char *)pppppppcVar17,"HealFactor");
                        if (iVar7 == 0) {
                          puVar16 = (undefined4 *)FUN_00891268();
                          puVar8 = local_154;
                          if (puVar16 == (undefined4 *)0x0) {
                            puVar16 = (undefined4 *)0x0;
                          }
                          else {
                            puVar16[1] = 5;
                            *puVar16 = CSkillInterrupt_HealFactor::vftable;
                            puVar16[2] = 0;
                          }
                          *(undefined2 *)(local_154 + 1) = 10;
                          uVar5 = FUN_0072e650();
                          local_190 = CONCAT22(local_190._2_2_,uVar5);
                          uVar5 = FUN_0072e650();
                          local_190 = CONCAT22(uVar5,(undefined2)local_190);
                          puVar16[2] = local_190;
                          puVar8[6] = puVar16;
                        }
                        else {
                          pppppppcVar17 = (char *******)local_34[0];
                          if (local_20 < 0x10) {
                            pppppppcVar17 = local_34;
                          }
                          puStack_20c = (uint *)0x8154a7;
                          iVar7 = __stricmp((char *)pppppppcVar17,"Buffcast");
                          if (iVar7 == 0) {
                            puVar8 = (undefined4 *)FUN_00891268();
                            if (puVar8 == (undefined4 *)0x0) {
                              puVar8 = (undefined4 *)0x0;
                            }
                            else {
                              puVar8[1] = 7;
                              *puVar8 = CSkillInterrupt_BuffInvoker::vftable;
                            }
                            bVar4 = FUN_0072e650();
                            local_169 = FUN_0072e650();
                            local_16a = FUN_0072e650();
                            uVar5 = FUN_0072e650();
                            puVar8[2] = (uint)bVar4;
                            *(undefined1 *)(puVar8 + 3) = local_169;
                            *(undefined1 *)((int)puVar8 + 0xd) = local_16a;
                            *(undefined2 *)((int)puVar8 + 0xe) = uVar5;
                            local_154[6] = puVar8;
                          }
                          else {
                            pppppppcVar17 = (char *******)local_34[0];
                            if (local_20 < 0x10) {
                              pppppppcVar17 = local_34;
                            }
                            puStack_20c = (uint *)0x815561;
                            iVar7 = __stricmp((char *)pppppppcVar17,"BuffEnhance");
                            if (iVar7 == 0) {
                              puVar8 = (undefined4 *)FUN_00891268();
                              if (puVar8 == (undefined4 *)0x0) {
                                puVar8 = (undefined4 *)0x0;
                              }
                              else {
                                puVar8[1] = 8;
                                *puVar8 = CSkillInterrupt_BuffEnhancer::vftable;
                              }
                              uVar5 = FUN_0072e650();
                              uVar6 = FUN_0072e650();
                              uVar10 = FUN_0072e650();
                              local_164 = (float *)(uVar10 & 0xffff);
                              FUN_0072e650();
                              *(undefined2 *)(puVar8 + 2) = uVar5;
                              *(undefined2 *)((int)puVar8 + 10) = uVar6;
                              *(undefined2 *)(puVar8 + 3) = local_164._0_2_;
                              local_154[6] = puVar8;
                            }
                            else {
                              pppppppcVar17 = (char *******)local_34[0];
                              if (local_20 < 0x10) {
                                pppppppcVar17 = local_34;
                              }
                              puStack_20c = (uint *)0x815618;
                              iVar7 = __stricmp((char *)pppppppcVar17,"SkillcooltimeReset");
                              if (iVar7 == 0) {
                                puVar8 = (undefined4 *)FUN_00891268();
                                if (puVar8 == (undefined4 *)0x0) {
                                  puVar8 = (undefined4 *)0x0;
                                }
                                else {
                                  puVar8[1] = 9;
                                  *puVar8 = CSkillInterrupt_CooltimeReset::vftable;
                                  puVar8[3] = 0;
                                  puVar8[4] = 0;
                                  puVar8[5] = 0;
                                }
                                FUN_00402b70();
                                local_8._0_1_ = 0xf;
                                FUN_0072ecf0();
                                FUN_00402c50();
                                pppppppcVar17 = (char *******)local_a0[0];
                                if (local_8c < 0x10) {
                                  pppppppcVar17 = local_a0;
                                }
                                puStack_20c = (uint *)0x8156a8;
                                iVar7 = __stricmp("AllSkill",(char *)pppppppcVar17);
                                if (iVar7 == 0) {
                                  puVar8[2] = 1;
                                }
                                else {
                                  puVar8[2] = 0;
                                  local_1a4 = (undefined4 *)0x0;
                                  local_1a0 = 0;
                                  local_19c = 0;
                                  local_8._0_1_ = 0x12;
                                  FUN_00402b70();
                                  local_8._0_1_ = 0x13;
                                  FUN_0072ecf0();
                                  local_8._0_1_ = 0x14;
                                  puStack_20c = (uint *)0x815712;
                                  FUN_006dd980();
                                  FUN_00402c50();
                                  local_8._0_1_ = 0x12;
                                  FUN_00402c50();
                                  puVar1 = (undefined4 *)((local_1a0 - (int)local_1a4) / 0x1c);
                                  puVar19 = local_1a4;
                                  puVar16 = local_160;
                                  while (local_160 = puVar1, local_160 != (undefined4 *)0x0) {
                                    puVar16 = puVar19;
                                    if (0xf < (uint)puVar19[5]) {
                                      puVar16 = (undefined4 *)*puVar19;
                                    }
                                    uVar10 = 0;
                                    if (puVar16 != (undefined4 *)0x0) {
                                      uVar10 = FUN_008917b4();
                                    }
                                    local_164 = (float *)(uVar10 & 0xffff);
                                    FUN_0044b4e0();
                                    puVar19 = puVar19 + 7;
                                    puVar16 = (undefined4 *)((int)local_160 + -1);
                                    puVar1 = puVar16;
                                  }
                                  local_160 = puVar16;
                                  FUN_00573ea0();
                                }
                                local_154[9] = local_168;
                                *(char *)((int)local_154 + 0x29) = (char)local_15c;
                                local_15c = local_15c + 1;
                                local_154[6] = puVar8;
                                *(undefined1 *)(local_154 + 10) = (undefined1)local_180;
                                local_8 = CONCAT31(local_8._1_3_,10);
                                FUN_00402c50();
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
LAB_008157df:
              if ((local_154[6] == 0) || (*(short *)(local_154 + 1) == 0)) {
                (**(code **)*local_154)();
                puStack_20c = (uint *)0xc52be0;
                uStack_210 = 0x815836;
                FUN_006edb60();
              }
              else {
                puStack_20c = local_178;
                uStack_210 = 0x81580e;
                FUN_0081aab0();
              }
              uVar10 = FUN_0072e3c0();
              local_158 = uVar10;
              if (0xf < local_70) {
                FUN_0089120c();
              }
              local_8 = local_8 & 0xffffff00;
              local_84[0] = local_84[0] & 0xffffff00;
              local_74 = 0;
              local_70 = 0xf;
              if (0xf < local_20) {
                FUN_0089120c();
              }
            }
          }
          local_170 = FUN_0072e3c0();
          uVar10 = local_1ac;
          puVar9 = local_1a8;
          local_1a8 = local_178;
          local_1ac = local_168;
        }
        FUN_0057ef20();
        puStack_20c = (uint *)0x8158e1;
        FUN_0082f200();
        local_174 = FUN_0072e3c0();
      }
      else {
        puStack_20c = (uint *)0xc52924;
        uStack_210 = 0x813eee;
        FUN_006edb60();
        local_174 = FUN_0072e3c0();
      }
    }
    local_8 = 0xffffffff;
    local_150 = TiXmlDocument::vftable;
    if (0xf < local_f0) {
      FUN_0089120c();
    }
    local_f0 = 0xf;
    local_f4 = 0;
    local_104 = local_104 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

