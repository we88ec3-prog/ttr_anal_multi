
/* WARNING: Removing unreachable block (ram,0x00542b4b) */

void FUN_00542710(int *param_1,int *param_2)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  char *******pppppppcVar9;
  int iVar10;
  char *pcVar11;
  char *******pppppppcVar12;
  uint uVar13;
  int *piVar14;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e0;
  int *local_d8;
  uint *local_c4;
  int local_c0;
  uint local_bc;
  undefined4 local_ac;
  uint local_a8;
  uint local_a0 [4];
  undefined4 local_90;
  uint local_8c;
  uint local_84;
  undefined4 local_74;
  uint local_70;
  char ******local_68 [4];
  undefined4 local_58;
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  char ******local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b389;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_2 != 0) {
    puVar5 = (undefined4 *)FUN_0071ba40("SoundSet");
    puVar2 = (uint *)*puVar5;
    while (puVar2 != (uint *)0x0) {
      if ((puVar2 == (uint *)0x0) || (local_c4 = puVar2, (*puVar2 & 7) != 1)) {
        local_c4 = (uint *)0x0;
      }
      local_a8 = 0xf;
      local_ac = 0;
      local_bc = local_bc & 0xffffff00;
      local_8 = 0;
      FUN_0071baa0(&DAT_00c0f680);
      if (local_ec == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = *(char **)(local_ec + 8);
        if (pcVar11 == (char *)0x0) {
          pcVar11 = "";
        }
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      pcVar6 = pcVar11;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar6 - (int)(pcVar11 + 1));
      local_8._0_1_ = 1;
      FUN_0071baa0("PlayMethod");
      if (local_e8 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = *(char **)(local_e8 + 8);
        if (pcVar11 == (char *)0x0) {
          pcVar11 = "";
        }
      }
      local_70 = 0xf;
      local_74 = 0;
      local_84 = local_84 & 0xffffff00;
      pcVar6 = pcVar11;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar11,(int)pcVar6 - (int)(pcVar11 + 1));
      local_8._0_1_ = 2;
      FUN_00719f10(&local_c4,&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_0071baa0("InheritFrom");
      if (local_f0 != 0) {
        FUN_0071baa0("InheritFrom");
        if (local_e0 == 0) {
          pcVar11 = (char *)0x0;
        }
        else {
          pcVar11 = *(char **)(local_e0 + 8);
          if (pcVar11 == (char *)0x0) {
            pcVar11 = "";
          }
        }
        pcVar6 = pcVar11;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar11,(int)pcVar6 - (int)(pcVar11 + 1));
      }
      piVar14 = (int *)0x0;
      local_d8 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      piVar7 = (int *)FUN_0071ba40("SoundList");
      local_c0 = *piVar7;
      if (local_c0 != 0) {
        puVar5 = (undefined4 *)FUN_0071ba40("Sound");
        puVar4 = (uint *)*puVar5;
        while (puVar3 = puVar4, puVar3 != (uint *)0x0) {
          if ((puVar3 != (uint *)0x0) && ((*puVar3 & 7) == 1)) {
            for (uVar13 = puVar3[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
              if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
                 (iVar8 = __stricmp("Name",*(char **)(uVar13 + 4)), iVar8 == 0)) {
                pcVar11 = *(char **)(uVar13 + 8);
                if (pcVar11 == (char *)0x0) {
                  pcVar11 = "";
                }
                goto LAB_0054299b;
              }
            }
          }
          pcVar11 = (char *)0x0;
LAB_0054299b:
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = (char ******)((uint)local_30[0] & 0xffffff00);
          pcVar6 = pcVar11;
          do {
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar11,(int)pcVar6 - (int)(pcVar11 + 1));
          local_8._0_1_ = 5;
          pppppppcVar12 = (char *******)local_30[0];
          if (local_1c < 0x10) {
            pppppppcVar12 = local_30;
          }
          local_8c = 0xf;
          local_90 = 0;
          local_a0[0] = local_a0[0] & 0xffffff00;
          pppppppcVar9 = pppppppcVar12;
          do {
            cVar1 = *(char *)pppppppcVar9;
            pppppppcVar9 = (char *******)((int)pppppppcVar9 + 1);
          } while (cVar1 != '\0');
          FUN_0040b310(pppppppcVar12);
          local_8._0_1_ = 6;
          iVar8 = FUN_0080a8b0(*param_1,local_a0);
          local_8 = CONCAT31(local_8._1_3_,5);
          local_c0 = iVar8;
          if (0xf < local_8c) {
            FUN_0089120c(local_a0[0]);
          }
          if (iVar8 != 0) {
            if (&local_c0 < piVar14) {
              if (piVar14 == (int *)0x0) {
                FUN_004deab0();
                piVar14 = local_d8;
              }
              if (piVar14 != (int *)0x0) {
                *piVar14 = *(int *)(((int)&local_c0 >> 2) * 4);
              }
            }
            else {
              if (piVar14 == (int *)0x0) {
                FUN_004deab0();
                piVar14 = local_d8;
              }
              if (piVar14 != (int *)0x0) {
                *piVar14 = iVar8;
              }
            }
            piVar14 = piVar14 + 1;
            local_d8 = piVar14;
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          if (0xf < local_1c) {
            FUN_0089120c(local_30[0]);
          }
          puVar4 = (uint *)0x0;
          if (puVar3 != (uint *)0x0) {
            puVar4 = (uint *)puVar3[6];
          }
        }
      }
      if ((local_c4 != (uint *)0x0) && (uVar13 = local_c4[7], uVar13 != 0)) {
LAB_00542b15:
        if ((*(char **)(uVar13 + 4) == (char *)0x0) ||
           (iVar8 = __stricmp("Setting",*(char **)(uVar13 + 4)), iVar8 != 0)) goto LAB_00542b32;
        pppppppcVar12 = (char *******)local_68[0];
        if (local_54 < 0x10) {
          pppppppcVar12 = local_68;
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (char ******)((uint)local_30[0] & 0xffffff00);
        pppppppcVar9 = pppppppcVar12;
        do {
          cVar1 = *(char *)pppppppcVar9;
          pppppppcVar9 = (char *******)((int)pppppppcVar9 + 1);
        } while (cVar1 != '\0');
        FUN_0040b310(pppppppcVar12);
        local_8 = CONCAT31(local_8._1_3_,7);
        iVar8 = *param_1;
        iVar10 = FUN_0080c1c0(local_30);
        if (iVar10 != *(int *)(iVar8 + 0x2c)) {
          pcVar11 = (char *)(iVar10 + 0xc);
          if (0xf < *(uint *)(iVar10 + 0x20)) {
            pcVar11 = *(char **)pcVar11;
          }
          uVar13 = local_20;
          if (*(uint *)(iVar10 + 0x1c) <= local_20) {
            uVar13 = *(uint *)(iVar10 + 0x1c);
          }
          pppppppcVar12 = (char *******)local_30[0];
          if (local_1c < 0x10) {
            pppppppcVar12 = local_30;
          }
          __strnicmp((char *)pppppppcVar12,pcVar11,uVar13);
        }
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
LAB_00542b41:
      if (0xf < local_54) {
        FUN_0089120c(local_68[0]);
      }
      local_54 = 0xf;
      local_58 = 0;
      local_68[0] = (char ******)((uint)local_68[0] & 0xffffff00);
      if (0xf < local_70) {
        FUN_0089120c(local_84);
      }
      local_70 = 0xf;
      local_74 = 0;
      local_84 = local_84 & 0xffffff00;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_8 = 0xffffffff;
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      if (0xf < local_a8) {
        FUN_0089120c(local_bc);
      }
      if (puVar2 != (uint *)0x0) {
        puVar2 = (uint *)puVar2[6];
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_00542b32:
  uVar13 = *(uint *)(uVar13 + 0x10);
  if (uVar13 == 0) goto LAB_00542b41;
  goto LAB_00542b15;
}

