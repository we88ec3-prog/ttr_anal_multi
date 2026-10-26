
void FUN_008159e0(void)

{
  char ***pppcVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  char ***pppcVar14;
  int iVar15;
  undefined4 *puVar16;
  char ******ppppppcVar17;
  char *****pppppcVar18;
  int in_ECX;
  undefined4 *puVar19;
  uint uVar20;
  undefined4 uVar21;
  char **ppcVar22;
  bool bVar23;
  undefined4 *local_a8;
  char **local_a4;
  char ****local_a0 [5];
  uint local_8c;
  uint local_84;
  undefined4 local_74;
  uint local_70;
  char *****local_4c [5];
  uint local_38;
  char *****local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918443;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar7 = FUN_0072e360(local_14);
  do {
    if (iVar7 == 0) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_70 = 0xf;
    local_74 = 0;
    local_84 = local_84 & 0xffffff00;
    FUN_00402a70(&DAT_00c408b8,4);
    local_8 = 0;
    FUN_0072ecf0(&DAT_00bf2375);
    local_8._0_1_ = 2;
    if (0xf < local_70) {
      FUN_0089120c(local_84);
    }
    local_70 = 0xf;
    local_74 = 0;
    local_84 = local_84 & 0xffffff00;
    ppppppcVar17 = (char ******)local_30[0];
    if (local_1c < 0x10) {
      ppppppcVar17 = local_30;
    }
    iVar8 = __stricmp("Random",(char *)ppppppcVar17);
    if (iVar8 == 0) {
      local_a4 = (char **)FUN_00891268(0xc);
      if (local_a4 == (char **)0x0) {
        local_a4 = (char **)0x0;
      }
      else {
        local_a4[1] = (char *)0x1;
        *local_a4 = (char *)CSkillInterruptCondition_RandomChance::vftable;
      }
      for (iVar8 = *(int *)(iVar7 + 0x94); iVar8 != iVar7 + 0x44; iVar8 = *(int *)(iVar8 + 0x50)) {
        pcVar10 = (char *)(iVar8 + 0x14);
        if (0xf < *(uint *)(iVar8 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar9 = __stricmp(pcVar10,"Chance");
        if (iVar9 == 0) {
          if (iVar8 != 0) {
            puVar19 = (undefined4 *)(iVar8 + 0x30);
            if (0xf < *(uint *)(iVar8 + 0x44)) {
              puVar19 = (undefined4 *)*puVar19;
            }
            if (puVar19 != (undefined4 *)0x0) {
              pcVar10 = (char *)FUN_008917b4(puVar19);
              goto LAB_00815b08;
            }
          }
          break;
        }
      }
      pcVar10 = (char *)0x0;
LAB_00815b08:
      local_a4[2] = pcVar10;
      pppcVar14 = *(char ****)(in_ECX + 0xc);
      bVar23 = &local_a4 < pppcVar14;
      ppcVar22 = local_a4;
LAB_00815cb7:
      local_a4 = ppcVar22;
      if (bVar23) {
        pppcVar1 = *(char ****)(in_ECX + 8);
        if (&local_a4 < pppcVar1) goto LAB_00815cfa;
        if (pppcVar14 == *(char ****)(in_ECX + 0x10)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0xc) =
               *(undefined4 *)(*(int *)(in_ECX + 8) + ((int)&local_a4 - (int)pppcVar1 >> 2) * 4);
          *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 4;
          goto LAB_0081664b;
        }
      }
      else {
LAB_00815cfa:
        if (pppcVar14 == *(char ****)(in_ECX + 0x10)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0xc) = ppcVar22;
        }
      }
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 4;
    }
    else {
      ppppppcVar17 = (char ******)local_30[0];
      if (local_1c < 0x10) {
        ppppppcVar17 = local_30;
      }
      iVar7 = __stricmp("SkillType",(char *)ppppppcVar17);
      if (iVar7 == 0) {
        local_a4 = (char **)FUN_00891268(0xc);
        if (local_a4 == (char **)0x0) {
          local_a4 = (char **)0x0;
        }
        else {
          local_a4[1] = (char *)0x3;
          *local_a4 = (char *)CSkillInterruptCondition_SkillType::vftable;
          local_a4[2] = (char *)0x0;
        }
        iVar7 = FUN_0072e360();
        iVar8 = FUN_0072e360();
        iVar9 = FUN_0072e360();
        iVar11 = FUN_0072e360();
        iVar12 = FUN_0072e360();
        uVar20 = -(uint)(iVar7 != 0) & 2 | -(uint)(iVar8 != 0) & 8 | -(uint)(iVar9 != 0) & 0x10 |
                 -(uint)(iVar11 != 0) & 0x20 | -(uint)(iVar12 != 0) & 0x40;
        iVar7 = FUN_0072e360();
        uVar13 = -(uint)(iVar7 != 0) & 0x80;
LAB_00815c9b:
        local_a4[2] = (char *)(uVar20 | uVar13);
        pppcVar14 = *(char ****)(in_ECX + 0xc);
        bVar23 = &local_a4 < pppcVar14;
        ppcVar22 = local_a4;
        goto LAB_00815cb7;
      }
      ppppppcVar17 = (char ******)local_30[0];
      if (local_1c < 0x10) {
        ppppppcVar17 = local_30;
      }
      iVar7 = __stricmp("SkillBaseType",(char *)ppppppcVar17);
      if (iVar7 == 0) {
        local_a4 = (char **)FUN_00891268(0xc);
        if (local_a4 == (char **)0x0) {
          local_a4 = (char **)0x0;
        }
        else {
          local_a4[1] = (char *)0x2;
          *local_a4 = (char *)CSkillInterruptCondition_SkillBaseType::vftable;
          local_a4[2] = (char *)0x0;
        }
        iVar7 = FUN_0072e360();
        iVar8 = FUN_0072e360();
        uVar20 = -(uint)(iVar7 != 0) & 2 | -(uint)(iVar8 != 0) & 8;
        iVar7 = FUN_0072e360();
        uVar13 = -(uint)(iVar7 != 0) & 4;
        goto LAB_00815c9b;
      }
      ppppppcVar17 = (char ******)local_30[0];
      if (local_1c < 0x10) {
        ppppppcVar17 = local_30;
      }
      iVar7 = __stricmp("Elemental",(char *)ppppppcVar17);
      if (iVar7 == 0) {
        local_a4 = (char **)FUN_00891268(0xc);
        if (local_a4 == (char **)0x0) {
          local_a4 = (char **)0x0;
        }
        else {
          local_a4[1] = (char *)0x4;
          *local_a4 = (char *)CSkillInterruptCondition_SkillElemental::vftable;
          local_a4[2] = (char *)0x0;
        }
        iVar7 = FUN_0072e360();
        iVar8 = FUN_0072e360();
        iVar9 = FUN_0072e360();
        iVar11 = FUN_0072e360();
        iVar12 = FUN_0072e360();
        iVar15 = FUN_0072e360();
        local_a4[2] = (char *)(-(uint)(iVar7 != 0) & 2 | -(uint)(iVar8 != 0) & 4 |
                               -(uint)(iVar9 != 0) & 8 | -(uint)(iVar11 != 0) & 0x10 |
                               -(uint)(iVar12 != 0) & 0x20 | -(uint)(iVar15 != 0) & 0x40);
        FUN_007bb350();
      }
      else {
        ppppppcVar17 = (char ******)local_30[0];
        if (local_1c < 0x10) {
          ppppppcVar17 = local_30;
        }
        iVar7 = __stricmp("SkillLevel",(char *)ppppppcVar17);
        if (iVar7 == 0) {
          puVar19 = (undefined4 *)FUN_00891268(0xc);
          if (puVar19 == (undefined4 *)0x0) {
            puVar19 = (undefined4 *)0x0;
          }
          else {
            puVar19[1] = 5;
            *puVar19 = CSkillInterruptCondition_SkillLevel::vftable;
            puVar19[2] = 0;
          }
          iVar7 = FUN_007300a0("MaxLevel");
          if (iVar7 == 0) {
LAB_00815e82:
            local_a8._0_1_ = 0;
          }
          else {
            puVar16 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar16 = (undefined4 *)*puVar16;
            }
            if (puVar16 == (undefined4 *)0x0) goto LAB_00815e82;
            local_a8._0_1_ = FUN_008917b4(puVar16);
          }
          iVar7 = FUN_007300a0("MinLevel");
          if (iVar7 == 0) {
LAB_00815eba:
            local_a4 = (char **)0x0;
          }
          else {
            puVar16 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar16 = (undefined4 *)*puVar16;
            }
            if (puVar16 == (undefined4 *)0x0) goto LAB_00815eba;
            local_a4 = (char **)FUN_008917b4(puVar16);
          }
          iVar7 = FUN_007300a0("SkillID");
          if (iVar7 != 0) {
            puVar16 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar16 = (undefined4 *)*puVar16;
            }
            if (puVar16 != (undefined4 *)0x0) {
              uVar6 = FUN_008917b4(puVar16);
              *(undefined2 *)(puVar19 + 2) = uVar6;
              *(undefined1 *)((int)puVar19 + 0xb) = local_a8._0_1_;
              uVar2 = local_a4._0_1_;
              goto LAB_00815fcf;
            }
          }
          *(undefined2 *)(puVar19 + 2) = 0;
          *(undefined1 *)((int)puVar19 + 0xb) = local_a8._0_1_;
          uVar2 = local_a4._0_1_;
        }
        else {
          ppppppcVar17 = (char ******)local_30[0];
          if (local_1c < 0x10) {
            ppppppcVar17 = local_30;
          }
          iVar7 = __stricmp("TargetSpecies",(char *)ppppppcVar17);
          if (iVar7 == 0) goto LAB_0081664b;
          ppppppcVar17 = (char ******)local_30[0];
          if (local_1c < 0x10) {
            ppppppcVar17 = local_30;
          }
          iVar7 = __stricmp("CastBuffLevel",(char *)ppppppcVar17);
          if (iVar7 != 0) {
            ppppppcVar17 = (char ******)local_30[0];
            if (local_1c < 0x10) {
              ppppppcVar17 = local_30;
            }
            iVar7 = __stricmp("CastBuffElemental",(char *)ppppppcVar17);
            if (iVar7 == 0) {
              local_a8 = (undefined4 *)FUN_00891268(0xc);
              if (local_a8 == (undefined4 *)0x0) {
                local_a8 = (undefined4 *)0x0;
              }
              else {
                local_a8[1] = 6;
                *local_a8 = CSkillInterruptCondition_CastBuffElemental::vftable;
                local_a8[2] = 0;
              }
              iVar7 = FUN_0072e360();
              iVar8 = FUN_0072e360();
              iVar9 = FUN_0072e360();
              iVar11 = FUN_0072e360();
              iVar12 = FUN_0072e360();
              iVar15 = FUN_0072e360();
              local_a8[2] = -(uint)(iVar7 != 0) & 2 | -(uint)(iVar8 != 0) & 4 |
                            -(uint)(iVar9 != 0) & 8 | -(uint)(iVar11 != 0) & 0x10 |
                            -(uint)(iVar12 != 0) & 0x20 | -(uint)(iVar15 != 0) & 0x40;
              FUN_007bb350();
              goto LAB_0081664b;
            }
            ppppppcVar17 = (char ******)local_30[0];
            if (local_1c < 0x10) {
              ppppppcVar17 = local_30;
            }
            iVar7 = __stricmp("HaveBuff",(char *)ppppppcVar17);
            if (iVar7 == 0) {
              puVar19 = (undefined4 *)FUN_00891268(0x10);
              if (puVar19 == (undefined4 *)0x0) {
                puVar19 = (undefined4 *)0x0;
              }
              else {
                *(undefined2 *)(puVar19 + 3) = 0;
                puVar19[1] = 8;
                *puVar19 = CSkillInterruptCondition_HaveBuffCheck::vftable;
                *(undefined1 *)((int)puVar19 + 0xe) = 0;
              }
              FUN_00402b70("CheckTarget");
              local_8._0_1_ = 3;
              FUN_0072ecf0("Caster");
              local_8 = CONCAT31(local_8._1_3_,5);
              FUN_00402c50();
              ppppppcVar17 = (char ******)local_4c[0];
              if (local_38 < 0x10) {
                ppppppcVar17 = local_4c;
              }
              iVar7 = __stricmp("Caster",(char *)ppppppcVar17);
              if (iVar7 == 0) {
                uVar21 = 1;
              }
              else {
                ppppppcVar17 = (char ******)local_4c[0];
                if (local_38 < 0x10) {
                  ppppppcVar17 = local_4c;
                }
                iVar7 = __stricmp("Target",(char *)ppppppcVar17);
                if (iVar7 == 0) {
                  uVar21 = 0;
                }
                else {
                  FUN_006edb60("HaveBuffCheck::Invalid CheckTarget");
                  uVar21 = 1;
                }
              }
              uVar2 = FUN_0072e650(0);
              uVar3 = FUN_0072e650(0);
              uVar4 = FUN_0072e650(0);
              *(undefined1 *)(puVar19 + 3) = uVar4;
              *(undefined1 *)((int)puVar19 + 0xd) = uVar3;
              *(undefined1 *)((int)puVar19 + 0xe) = uVar2;
              puVar19[2] = uVar21;
LAB_00816211:
              FUN_007bb350();
            }
            else {
              ppppppcVar17 = (char ******)local_30[0];
              if (local_1c < 0x10) {
                ppppppcVar17 = local_30;
              }
              iVar7 = __stricmp("StruckType",(char *)ppppppcVar17);
              if (iVar7 == 0) {
                local_a8 = (undefined4 *)FUN_00891268(0xc);
                uVar21 = 0;
                if (local_a8 == (undefined4 *)0x0) {
                  local_a8 = (undefined4 *)0x0;
                }
                else {
                  local_a8[1] = 9;
                  *local_a8 = CSkillInterruptCondition_StruckType::vftable;
                  local_a8[2] = 0;
                }
                FUN_00402b70("StruckType");
                local_8._0_1_ = 6;
                FUN_0072ecf0("Caster");
                local_8 = CONCAT31(local_8._1_3_,8);
                FUN_00402c50();
                ppppppcVar17 = (char ******)local_4c[0];
                if (local_38 < 0x10) {
                  ppppppcVar17 = local_4c;
                }
                iVar7 = __stricmp("Miss",(char *)ppppppcVar17);
                if (iVar7 == 0) {
                  local_a8[2] = 3;
                }
                else {
                  ppppppcVar17 = (char ******)local_4c[0];
                  if (local_38 < 0x10) {
                    ppppppcVar17 = local_4c;
                  }
                  iVar7 = __stricmp("Block",(char *)ppppppcVar17);
                  if (iVar7 == 0) {
                    local_a8[2] = 4;
                  }
                  else {
                    ppppppcVar17 = (char ******)local_4c[0];
                    if (local_38 < 0x10) {
                      ppppppcVar17 = local_4c;
                    }
                    iVar7 = __stricmp("Critical",(char *)ppppppcVar17);
                    if (iVar7 == 0) {
                      uVar21 = 2;
                    }
                    local_a8[2] = uVar21;
                  }
                }
                goto LAB_00816211;
              }
              ppppppcVar17 = (char ******)local_30[0];
              if (local_1c < 0x10) {
                ppppppcVar17 = local_30;
              }
              iVar7 = __stricmp("KnockbackType",(char *)ppppppcVar17);
              if (iVar7 == 0) {
                local_a8 = (undefined4 *)FUN_00891268(0xc);
                uVar21 = 0;
                if (local_a8 == (undefined4 *)0x0) {
                  local_a8 = (undefined4 *)0x0;
                }
                else {
                  local_a8[1] = 10;
                  *local_a8 = CSkillInterruptCondition_KnockbackType::vftable;
                  local_a8[2] = 0;
                }
                FUN_00402b70("KnockbackType");
                local_8._0_1_ = 9;
                FUN_0072ecf0("ATTACKED");
                local_8 = CONCAT31(local_8._1_3_,0xb);
                FUN_00402c50();
                ppppppcVar17 = (char ******)local_4c[0];
                if (local_38 < 0x10) {
                  ppppppcVar17 = local_4c;
                }
                iVar7 = __stricmp("ATTACKED",(char *)ppppppcVar17);
                if (iVar7 == 0) {
                  local_a8[2] = 1;
                }
                else {
                  ppppppcVar17 = (char ******)local_4c[0];
                  if (local_38 < 0x10) {
                    ppppppcVar17 = local_4c;
                  }
                  iVar7 = __stricmp("KNOCKDOWN",(char *)ppppppcVar17);
                  if (iVar7 == 0) {
                    local_a8[2] = 2;
                  }
                  else {
                    ppppppcVar17 = (char ******)local_4c[0];
                    if (local_38 < 0x10) {
                      ppppppcVar17 = local_4c;
                    }
                    iVar7 = __stricmp("ROLL",(char *)ppppppcVar17);
                    if (iVar7 == 0) {
                      local_a8[2] = 3;
                    }
                    else {
                      ppppppcVar17 = (char ******)local_4c[0];
                      if (local_38 < 0x10) {
                        ppppppcVar17 = local_4c;
                      }
                      iVar7 = __stricmp("AERIAL",(char *)ppppppcVar17);
                      if (iVar7 == 0) {
                        local_a8[2] = 4;
                      }
                      else {
                        ppppppcVar17 = (char ******)local_4c[0];
                        if (local_38 < 0x10) {
                          ppppppcVar17 = local_4c;
                        }
                        iVar7 = __stricmp("PULLED",(char *)ppppppcVar17);
                        if (iVar7 == 0) {
                          uVar21 = 5;
                        }
                        local_a8[2] = uVar21;
                      }
                    }
                  }
                }
                goto LAB_00816211;
              }
              ppppppcVar17 = (char ******)local_30[0];
              if (local_1c < 0x10) {
                ppppppcVar17 = local_30;
              }
              iVar7 = __stricmp("LifeCheck",(char *)ppppppcVar17);
              if (iVar7 != 0) goto LAB_0081664b;
              puVar19 = (undefined4 *)FUN_00891268(0x18);
              if (puVar19 == (undefined4 *)0x0) {
                puVar19 = (undefined4 *)0x0;
              }
              else {
                puVar19[1] = 0xb;
                *puVar19 = CSkillInterruptCondition_LifeCheck::vftable;
              }
              local_a4 = (char **)0x1;
              FUN_00402b70("CheckTarget");
              local_8._0_1_ = 0xc;
              FUN_0072ecf0("Caster");
              local_8 = CONCAT31(local_8._1_3_,0xe);
              FUN_00402c50();
              pppppcVar18 = (char *****)local_a0[0];
              if (local_8c < 0x10) {
                pppppcVar18 = local_a0;
              }
              iVar7 = __stricmp("Caster",(char *)pppppcVar18);
              if (iVar7 == 0) {
                local_a4 = (char **)0x1;
              }
              else {
                pppppcVar18 = (char *****)local_a0[0];
                if (local_8c < 0x10) {
                  pppppcVar18 = local_a0;
                }
                iVar7 = __stricmp("Target",(char *)pppppcVar18);
                if (iVar7 == 0) {
                  local_a4 = (char **)0x0;
                }
                else {
                  FUN_006edb60("HaveBuffCheck::Invalid CheckTarget");
                }
              }
              uVar13 = FUN_0072e6d0(0);
              bVar5 = FUN_0072e650(0);
              uVar20 = FUN_0072e650(0);
              puVar19[3] = uVar20 & 0xff;
              puVar19[4] = (uint)bVar5;
              puVar19[2] = local_a4;
              puVar19[5] = uVar13 & 0xff;
              FUN_007bb350();
            }
            local_8._0_1_ = 2;
            FUN_00402c50();
            goto LAB_0081664b;
          }
          puVar19 = (undefined4 *)FUN_00891268(0xc);
          if (puVar19 == (undefined4 *)0x0) {
            puVar19 = (undefined4 *)0x0;
          }
          else {
            puVar19[1] = 7;
            *puVar19 = CSkillInterruptCondition_CastBuffLevel::vftable;
            *(undefined2 *)(puVar19 + 2) = 0;
            *(undefined1 *)((int)puVar19 + 10) = 0;
          }
          uVar2 = FUN_0072e650(0);
          uVar3 = FUN_0072e650(0);
          uVar4 = FUN_0072e650(0);
          *(undefined1 *)(puVar19 + 2) = uVar4;
          *(undefined1 *)((int)puVar19 + 9) = uVar3;
        }
LAB_00815fcf:
        *(undefined1 *)((int)puVar19 + 10) = uVar2;
        FUN_007bb350();
      }
    }
LAB_0081664b:
    iVar7 = FUN_0072e3c0();
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  } while( true );
}

