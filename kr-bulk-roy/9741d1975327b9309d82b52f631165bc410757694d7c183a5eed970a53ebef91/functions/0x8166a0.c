
void FUN_008166a0(int param_1,undefined4 param_2,byte param_3)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *******pppppppcVar11;
  int in_ECX;
  undefined4 *puVar12;
  undefined4 uVar13;
  bool bVar14;
  undefined4 local_90;
  undefined4 local_8c;
  char ******local_84 [5];
  uint local_70;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  char ******local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009183c0;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0xf;
  local_58 = 0;
  local_68 = local_68 & 0xffffff00;
  local_14 = uVar3;
  FUN_00402a70("LearnType",9);
  local_8 = 0;
  FUN_0072ecf0("Learnable");
  local_8._0_1_ = 2;
  if (0xf < local_54) {
    FUN_0089120c(local_68,uVar3);
  }
  local_54 = 0xf;
  local_58 = 0;
  local_68 = local_68 & 0xffffff00;
  pppppppcVar11 = (char *******)local_84[0];
  if (local_70 < 0x10) {
    pppppppcVar11 = local_84;
  }
  iVar4 = __stricmp((char *)pppppppcVar11,"System");
  if (iVar4 == 0) {
    *(undefined4 *)(in_ECX + 0xc) = 2;
  }
  else {
    pppppppcVar11 = (char *******)local_84[0];
    if (local_70 < 0x10) {
      pppppppcVar11 = local_84;
    }
    iVar4 = __stricmp((char *)pppppppcVar11,"Disabled");
    *(uint *)(in_ECX + 0xc) = (uint)(iVar4 != 0);
  }
  iVar4 = FUN_0072e360();
  do {
    if (iVar4 == 0) {
      if (0xf < local_70) {
        FUN_0089120c(local_84[0]);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_00402a70(&DAT_00c408b8,4);
    local_8._0_1_ = 3;
    FUN_0072ecf0(&DAT_00bf2375);
    local_8 = CONCAT31(local_8._1_3_,5);
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    pppppppcVar11 = (char *******)local_30[0];
    if (local_1c < 0x10) {
      pppppppcVar11 = local_30;
    }
    iVar5 = __stricmp((char *)pppppppcVar11,"Payment");
    if (iVar5 == 0) {
      iVar5 = iVar4 + 0x44;
      for (iVar7 = *(int *)(iVar4 + 0x94); iVar7 != iVar5; iVar7 = *(int *)(iVar7 + 0x50)) {
        pcVar10 = (char *)(iVar7 + 0x14);
        if (0xf < *(uint *)(iVar7 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar6 = __stricmp(pcVar10,"Skillpoint");
        if (iVar6 == 0) {
          if (iVar7 != 0) {
            puVar12 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar12 = (undefined4 *)*puVar12;
            }
            if (puVar12 != (undefined4 *)0x0) {
              local_8c = FUN_008917b4(puVar12);
              goto LAB_00816876;
            }
          }
          break;
        }
      }
      local_8c = 0;
LAB_00816876:
      for (iVar7 = *(int *)(iVar4 + 0x94); iVar7 != iVar5; iVar7 = *(int *)(iVar7 + 0x50)) {
        pcVar10 = (char *)(iVar7 + 0x14);
        if (0xf < *(uint *)(iVar7 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar6 = __stricmp(pcVar10,"Money");
        if (iVar6 == 0) {
          if (iVar7 != 0) {
            puVar12 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar12 = (undefined4 *)*puVar12;
            }
            if (puVar12 != (undefined4 *)0x0) {
              uVar13 = FUN_008917b4(puVar12);
              goto LAB_008168ab;
            }
          }
          break;
        }
      }
      uVar13 = 0;
LAB_008168ab:
      for (iVar4 = *(int *)(iVar4 + 0x94); iVar4 != iVar5; iVar4 = *(int *)(iVar4 + 0x50)) {
        pcVar10 = (char *)(iVar4 + 0x14);
        if (0xf < *(uint *)(iVar4 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar7 = __stricmp(pcVar10,"SkillExp");
        if (iVar7 == 0) {
          if (iVar4 != 0) {
            puVar12 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar12 = (undefined4 *)*puVar12;
            }
            if (puVar12 != (undefined4 *)0x0) {
              uVar8 = FUN_008917b4(puVar12);
              goto LAB_008168d8;
            }
          }
          break;
        }
      }
      uVar8 = 0;
LAB_008168d8:
      FUN_0081aec0(param_3,local_8c,uVar8,uVar13);
    }
    else {
      pppppppcVar11 = (char *******)local_30[0];
      if (local_1c < 0x10) {
        pppppppcVar11 = local_30;
      }
      iVar4 = __stricmp((char *)pppppppcVar11,"CharLevel");
      if (iVar4 == 0) {
        puVar12 = (undefined4 *)FUN_00891268(0x10);
        if (puVar12 == (undefined4 *)0x0) {
          puVar12 = (undefined4 *)0x0;
        }
        else {
          puVar12[1] = 0;
          *puVar12 = CPracticeRequirement_CharLevel::vftable;
        }
        iVar4 = FUN_007300a0("MaxLevel");
        if (iVar4 == 0) {
LAB_008169dd:
          uVar13 = 0;
        }
        else {
          puVar9 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 == (undefined4 *)0x0) goto LAB_008169dd;
          uVar13 = FUN_008917b4(puVar9);
        }
        iVar4 = FUN_007300a0("MinLevel");
        if (iVar4 == 0) {
LAB_00816a07:
          uVar8 = 0;
        }
        else {
          puVar9 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 == (undefined4 *)0x0) goto LAB_00816a07;
          uVar8 = FUN_008917b4(puVar9);
        }
        puVar12[3] = uVar13;
        uVar3 = (uint)param_3;
        puVar12[2] = uVar8;
        FUN_0081acc0(uVar3,puVar12);
        if (uVar3 < (uint)(*(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2)) {
          bVar1 = *(byte *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4) + 0x24);
        }
        else {
          bVar1 = 0xff;
        }
        if ((int)(uint)bVar1 < (int)puVar12[2]) {
          *(char *)(*(int *)(*(int *)(in_ECX + 0x14) + uVar3 * 4) + 0x24) = (char)puVar12[2];
        }
      }
      else {
        pppppppcVar11 = (char *******)local_30[0];
        if (local_1c < 0x10) {
          pppppppcVar11 = local_30;
        }
        iVar4 = __stricmp((char *)pppppppcVar11,"Practice");
        if (iVar4 != 0) {
          pppppppcVar11 = (char *******)local_30[0];
          if (local_1c < 0x10) {
            pppppppcVar11 = local_30;
          }
          iVar4 = __stricmp((char *)pppppppcVar11,"Group");
          if (iVar4 != 0) {
            pppppppcVar11 = (char *******)local_30[0];
            if (local_1c < 0x10) {
              pppppppcVar11 = local_30;
            }
            iVar4 = __stricmp((char *)pppppppcVar11,"SkillLevel");
            if (iVar4 != 0) {
              pppppppcVar11 = (char *******)local_30[0];
              if (local_1c < 0x10) {
                pppppppcVar11 = local_30;
              }
              iVar4 = __stricmp((char *)pppppppcVar11,"UsedSkillpoint");
              if (iVar4 != 0) goto LAB_00816e2f;
              puVar12 = (undefined4 *)FUN_00891268(0xc);
              if (puVar12 == (undefined4 *)0x0) {
                puVar12 = (undefined4 *)0x0;
              }
              else {
                puVar12[1] = 4;
                *puVar12 = CPracticeRequirement_UsedSkillpoint::vftable;
              }
              iVar4 = FUN_007300a0("Value");
              if (iVar4 == 0) {
LAB_00816e08:
                uVar3 = 0;
              }
              else {
                puVar9 = (undefined4 *)(iVar4 + 0x30);
                if (0xf < *(uint *)(iVar4 + 0x44)) {
                  puVar9 = (undefined4 *)*puVar9;
                }
                if (puVar9 == (undefined4 *)0x0) goto LAB_00816e08;
                uVar3 = FUN_008917b4(puVar9);
              }
              puVar12[2] = uVar3;
              FUN_0081acc0(param_3,puVar12);
              if (*(byte *)(param_1 + 0x30) < uVar3) {
                *(char *)(param_1 + 0x30) = (char)uVar3;
              }
              goto LAB_00816e2f;
            }
            puVar12 = (undefined4 *)FUN_00891268(0x14);
            if (puVar12 == (undefined4 *)0x0) {
              puVar12 = (undefined4 *)0x0;
            }
            else {
              puVar12[1] = 3;
              *puVar12 = CPracticeRequirement_SkillLevel::vftable;
            }
            iVar4 = FUN_007300a0("MinLevel");
            if (iVar4 == 0) {
LAB_00816d0d:
              local_90 = 0;
            }
            else {
              puVar9 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar9 = (undefined4 *)*puVar9;
              }
              if (puVar9 == (undefined4 *)0x0) goto LAB_00816d0d;
              local_90 = FUN_008917b4(puVar9);
            }
            iVar4 = FUN_007300a0("MaxLevel");
            if (iVar4 == 0) {
LAB_00816d41:
              uVar13 = 0;
            }
            else {
              puVar9 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar9 = (undefined4 *)*puVar9;
              }
              if (puVar9 == (undefined4 *)0x0) goto LAB_00816d41;
              uVar13 = FUN_008917b4(puVar9);
            }
            iVar4 = FUN_007300a0("SkillID");
            if (iVar4 == 0) {
LAB_00816d6b:
              uVar2 = 0;
            }
            else {
              puVar9 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar9 = (undefined4 *)*puVar9;
              }
              if (puVar9 == (undefined4 *)0x0) goto LAB_00816d6b;
              uVar2 = FUN_008917b4(puVar9);
            }
            *(undefined2 *)(puVar12 + 2) = uVar2;
            puVar12[3] = local_90;
            puVar12[4] = uVar13;
            FUN_0081acc0(param_3,puVar12);
            goto LAB_00816e2f;
          }
          puVar12 = (undefined4 *)FUN_00891268(0x18);
          if (puVar12 == (undefined4 *)0x0) {
            puVar12 = (undefined4 *)0x0;
          }
          else {
            puVar12[1] = 2;
            *puVar12 = CPracticeRequirement_GroupCount::vftable;
          }
          iVar4 = FUN_007300a0(&DAT_00c411c4);
          if (iVar4 == 0) {
LAB_00816bc9:
            local_8c = 0;
          }
          else {
            puVar9 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 == (undefined4 *)0x0) goto LAB_00816bc9;
            local_8c = FUN_008917b4(puVar9);
          }
          iVar4 = FUN_007300a0(&DAT_00c411c8);
          if (iVar4 == 0) {
LAB_00816c00:
            local_90 = 0;
          }
          else {
            puVar9 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 == (undefined4 *)0x0) goto LAB_00816c00;
            local_90 = FUN_008917b4(puVar9);
          }
          iVar4 = FUN_007300a0("GroupID");
          if (iVar4 == 0) {
LAB_00816c33:
            uVar13 = 0;
          }
          else {
            puVar9 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 == (undefined4 *)0x0) goto LAB_00816c33;
            uVar13 = FUN_008917b4(puVar9);
          }
          iVar4 = FUN_007300a0("CountLevel");
          if (iVar4 == 0) {
LAB_00816c67:
            bVar14 = false;
          }
          else {
            pcVar10 = (char *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              pcVar10 = *(char **)pcVar10;
            }
            if (pcVar10 == (char *)0x0) goto LAB_00816c67;
            iVar4 = __stricmp(pcVar10,"true");
            bVar14 = iVar4 == 0;
          }
          puVar12[3] = (uint)bVar14;
          puVar12[4] = local_8c;
          puVar12[5] = local_90;
          puVar12[2] = uVar13;
          FUN_0081acc0(param_3,puVar12);
          goto LAB_00816e2f;
        }
        puVar12 = (undefined4 *)FUN_00891268(0x14);
        if (puVar12 == (undefined4 *)0x0) {
          puVar12 = (undefined4 *)0x0;
        }
        else {
          puVar12[1] = 1;
          *puVar12 = CPracticeRequirement_PracticeCount::vftable;
        }
        iVar4 = FUN_007300a0("MinLevel");
        if (iVar4 == 0) {
LAB_00816acd:
          local_8c = 0;
        }
        else {
          puVar9 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 == (undefined4 *)0x0) goto LAB_00816acd;
          local_8c = FUN_008917b4(puVar9);
        }
        iVar4 = FUN_007300a0("MaxLevel");
        if (iVar4 == 0) {
LAB_00816b01:
          uVar13 = 0;
        }
        else {
          puVar9 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 == (undefined4 *)0x0) goto LAB_00816b01;
          uVar13 = FUN_008917b4(puVar9);
        }
        iVar4 = FUN_007300a0("PracticeID");
        if (iVar4 == 0) {
LAB_00816b2b:
          uVar8 = 0;
        }
        else {
          puVar9 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 == (undefined4 *)0x0) goto LAB_00816b2b;
          uVar8 = FUN_008917b4(puVar9);
        }
        puVar12[2] = uVar8;
        puVar12[3] = local_8c;
        puVar12[4] = uVar13;
        FUN_0081acc0(param_3,puVar12);
      }
    }
LAB_00816e2f:
    iVar4 = FUN_0072e3c0();
    local_8._0_1_ = 2;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  } while( true );
}

