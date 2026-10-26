
/* WARNING: Removing unreachable block (ram,0x00526117) */
/* WARNING: Removing unreachable block (ram,0x00525fb0) */
/* WARNING: Removing unreachable block (ram,0x00525dba) */
/* WARNING: Removing unreachable block (ram,0x005259d6) */
/* WARNING: Removing unreachable block (ram,0x00525ae5) */
/* WARNING: Removing unreachable block (ram,0x00525dec) */
/* WARNING: Removing unreachable block (ram,0x00526156) */
/* WARNING: Removing unreachable block (ram,0x00525fea) */
/* WARNING: Removing unreachable block (ram,0x00526043) */
/* WARNING: Removing unreachable block (ram,0x0052604d) */
/* WARNING: Removing unreachable block (ram,0x00526050) */
/* WARNING: Removing unreachable block (ram,0x00526055) */
/* WARNING: Removing unreachable block (ram,0x00526061) */
/* WARNING: Removing unreachable block (ram,0x0052607a) */
/* WARNING: Removing unreachable block (ram,0x00526080) */
/* WARNING: Removing unreachable block (ram,0x005260a4) */

void FUN_00525840(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  int local_220;
  int local_21c;
  int local_218;
  int local_210;
  int local_20c;
  uint local_168;
  uint local_154;
  int local_130 [4];
  char local_120 [264];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091e10a;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uVar4;
  FUN_00402160(L"NPC_Talk",8);
  local_21c = 0;
  iVar5 = FUN_0072e360(uVar4);
  do {
    if (iVar5 == 0) {
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8._0_1_ = 0xb;
        FUN_005c3de0();
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_8 = (uint)local_8._1_3_ << 8;
      }
      FUN_005c7410();
      ExceptionList = local_10;
      __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
      return;
    }
    for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar5 + 0x44; iVar8 = *(int *)(iVar8 + 0x50)) {
      pcVar10 = (char *)(iVar8 + 0x14);
      if (0xf < *(uint *)(iVar8 + 0x28)) {
        pcVar10 = *(char **)pcVar10;
      }
      iVar6 = __stricmp(pcVar10,"ID");
      if (iVar6 == 0) {
        if (iVar8 != 0) {
          puVar9 = (undefined4 *)(iVar8 + 0x30);
          if (0xf < *(uint *)(iVar8 + 0x44)) {
            puVar9 = (undefined4 *)*puVar9;
          }
          if (puVar9 != (undefined4 *)0x0) {
            uVar7 = FUN_008917b4(puVar9);
            goto LAB_00525921;
          }
        }
        break;
      }
    }
    uVar7 = 0;
LAB_00525921:
    iVar5 = FUN_00526f60(param_1,uVar7);
    if (*(int *)(iVar5 + 0x14) == 0) {
      FUN_00402a70(&DAT_00c0ce30,4);
      local_8._0_1_ = 1;
      uVar7 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00440130(uVar7);
      if (0xf < local_154) {
        FUN_0089120c(local_168);
      }
      local_154 = 0xf;
      local_168 = local_168 & 0xffffff00;
    }
    local_8._0_1_ = 3;
    iVar8 = FUN_0072e360();
    if (iVar8 != 0) {
      local_8._0_1_ = 4;
      FUN_00402a70(&DAT_00c0d66c,4);
      local_8._0_1_ = 5;
      uVar7 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_00440130(uVar7);
      if (0xf < local_154) {
        FUN_0089120c(local_168);
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      local_168 = local_168 & 0xffffff00;
      iVar8 = FUN_007300a0(&DAT_00bfb82c);
      if (iVar8 != 0) {
        puVar9 = (undefined4 *)(iVar8 + 0x30);
        if (0xf < *(uint *)(iVar8 + 0x44)) {
          puVar9 = (undefined4 *)*puVar9;
        }
        if (puVar9 != (undefined4 *)0x0) {
          FUN_008917b4(puVar9);
        }
      }
      FUN_006ab570();
      iVar8 = FUN_007300a0(&DAT_00c0ecb8);
      if (iVar8 == 0) {
LAB_00525b95:
        local_218 = 0;
      }
      else {
        puVar9 = (undefined4 *)(iVar8 + 0x30);
        if (0xf < *(uint *)(iVar8 + 0x44)) {
          puVar9 = (undefined4 *)*puVar9;
        }
        if (puVar9 == (undefined4 *)0x0) goto LAB_00525b95;
        local_218 = FUN_008917b4(puVar9);
      }
      iVar8 = FUN_007300a0(&DAT_00c0ecbc);
      if (iVar8 == 0) {
LAB_00525bcc:
        local_220 = 0;
      }
      else {
        puVar9 = (undefined4 *)(iVar8 + 0x30);
        if (0xf < *(uint *)(iVar8 + 0x44)) {
          puVar9 = (undefined4 *)*puVar9;
        }
        if (puVar9 == (undefined4 *)0x0) goto LAB_00525bcc;
        local_220 = FUN_008917b4(puVar9);
      }
      local_21c = local_21c + 1;
      FUN_00401d90("FaceTable%d",local_21c);
      pcVar10 = local_120;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(local_120,(int)pcVar10 - (int)(local_120 + 1));
      FUN_00440130(iVar5 + 0x50);
      local_210 = 0;
      local_20c = FUN_0072e360();
      if (local_20c != 0) {
        puVar13 = (uint *)(iVar5 + 0x6c);
        do {
          local_210 = local_210 + 1;
          iVar6 = local_20c + 0x44;
          for (iVar8 = *(int *)(local_20c + 0x94); iVar8 != iVar6; iVar8 = *(int *)(iVar8 + 0x50)) {
            pcVar10 = (char *)(iVar8 + 0x14);
            if (0xf < *(uint *)(iVar8 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar11 = __stricmp(pcVar10,"ID");
            if (iVar11 == 0) {
              if (iVar8 != 0) {
                puVar9 = (undefined4 *)(iVar8 + 0x30);
                if (0xf < *(uint *)(iVar8 + 0x44)) {
                  puVar9 = (undefined4 *)*puVar9;
                }
                if (puVar9 != (undefined4 *)0x0) {
                  local_130[0] = FUN_008917b4(puVar9);
                  goto LAB_00525caa;
                }
              }
              break;
            }
          }
          local_130[0] = 0;
LAB_00525caa:
          local_130[3] = local_210;
          for (iVar8 = *(int *)(local_20c + 0x94); iVar11 = local_218, iVar8 != iVar6;
              iVar8 = *(int *)(iVar8 + 0x50)) {
            pcVar10 = (char *)(iVar8 + 0x14);
            if (0xf < *(uint *)(iVar8 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar12 = __stricmp(pcVar10,"X");
            if (iVar12 == 0) {
              if (iVar8 != 0) {
                puVar9 = (undefined4 *)(iVar8 + 0x30);
                if (0xf < *(uint *)(iVar8 + 0x44)) {
                  puVar9 = (undefined4 *)*puVar9;
                }
                if (puVar9 != (undefined4 *)0x0) {
                  iVar11 = FUN_008917b4(puVar9);
                }
              }
              break;
            }
          }
          local_130[1] = iVar11;
          for (iVar8 = *(int *)(local_20c + 0x94); iVar11 = local_220, iVar8 != iVar6;
              iVar8 = *(int *)(iVar8 + 0x50)) {
            pcVar10 = (char *)(iVar8 + 0x14);
            if (0xf < *(uint *)(iVar8 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar12 = __stricmp(pcVar10,"Y");
            if (iVar12 == 0) {
              if (iVar8 != 0) {
                puVar9 = (undefined4 *)(iVar8 + 0x30);
                if (0xf < *(uint *)(iVar8 + 0x44)) {
                  puVar9 = (undefined4 *)*puVar9;
                }
                if (puVar9 != (undefined4 *)0x0) {
                  iVar11 = FUN_008917b4(puVar9);
                }
              }
              break;
            }
          }
          local_8._0_1_ = 7;
          local_130[2] = iVar11;
          FUN_00402a70(&DAT_00c0d66c,4);
          local_8._0_1_ = 8;
          uVar7 = FUN_0072ecf0(&DAT_00bf2375);
          local_8._0_1_ = 9;
          FUN_00440130(uVar7);
          local_8 = CONCAT31(local_8._1_3_,7);
          FUN_006ab570();
          piVar2 = *(int **)(iVar5 + 0x70);
          if (local_130 < piVar2) {
            piVar3 = (int *)*puVar13;
            if (local_130 < piVar3) goto LAB_00525f36;
            if (piVar2 == *(int **)(iVar5 + 0x74)) {
              uVar4 = (int)piVar2 - (int)piVar3 >> 4;
              if (0xffffffe < uVar4) goto LAB_00526188;
              uVar4 = uVar4 + 1;
              uVar14 = (int)*(int **)(iVar5 + 0x74) - (int)piVar3 >> 4;
              if (uVar14 < uVar4) {
                if (0xfffffff - (uVar14 >> 1) < uVar14) {
                  uVar14 = 0;
                }
                else {
                  uVar14 = uVar14 + (uVar14 >> 1);
                }
                if (uVar14 < uVar4) {
                  uVar14 = uVar4;
                }
                FUN_00531860(uVar14);
              }
            }
            puVar9 = *(undefined4 **)(iVar5 + 0x70);
            puVar15 = (undefined4 *)(((int)local_130 - (int)piVar3 & 0xfffffff0U) + *puVar13);
            if (puVar9 != (undefined4 *)0x0) {
              *puVar9 = *puVar15;
              puVar9[1] = puVar15[1];
              puVar9[2] = puVar15[2];
              puVar9[3] = puVar15[3];
            }
            *(int *)(iVar5 + 0x70) = *(int *)(iVar5 + 0x70) + 0x10;
          }
          else {
LAB_00525f36:
            if (piVar2 == *(int **)(iVar5 + 0x74)) {
              uVar4 = (int)((int)piVar2 - *puVar13) >> 4;
              if (0xffffffe < uVar4) {
LAB_00526188:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar4 = uVar4 + 1;
              uVar14 = (int)((int)*(int **)(iVar5 + 0x74) - *puVar13) >> 4;
              if (uVar14 < uVar4) {
                if (0xfffffff - (uVar14 >> 1) < uVar14) {
                  uVar14 = 0;
                }
                else {
                  uVar14 = uVar14 + (uVar14 >> 1);
                }
                if (uVar14 < uVar4) {
                  uVar14 = uVar4;
                }
                FUN_00531860(uVar14);
              }
            }
            piVar2 = *(int **)(iVar5 + 0x70);
            if (piVar2 != (int *)0x0) {
              *piVar2 = local_130[0];
              piVar2[1] = local_130[1];
              piVar2[2] = iVar11;
              piVar2[3] = local_130[3];
            }
            *(int *)(iVar5 + 0x70) = *(int *)(iVar5 + 0x70) + 0x10;
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          local_20c = FUN_0072e3c0();
        } while (local_20c != 0);
      }
      local_154 = 0xf;
      local_8._0_1_ = 3;
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8._0_1_ = 10;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8._0_1_ = 3;
    }
    FUN_005c7410();
    local_8 = (uint)local_8._1_3_ << 8;
    iVar5 = FUN_0072e3c0();
  } while( true );
}

