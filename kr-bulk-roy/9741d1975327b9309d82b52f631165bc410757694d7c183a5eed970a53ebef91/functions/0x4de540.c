
void FUN_004de540(int param_1,uint param_2)

{
  short *psVar1;
  code *pcVar2;
  void **ppvVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 ******ppppppuVar8;
  undefined4 uVar9;
  int in_ECX;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int local_84;
  int local_80;
  int local_7c;
  int local_6c;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  undefined4 *****local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 *****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009303de;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar12 = (int *)(param_1 + 2);
  uVar5 = (int)piVar12 - param_1;
  local_14 = uVar4;
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, uVar5 < param_2) {
    if (*piVar12 == 0) {
      uVar6 = *(int *)(in_ECX + 0x5f00) - *(int *)(in_ECX + 0x5efc) >> 2;
      if (uVar6 != 0) {
        uVar10 = 0;
        puVar11 = *(undefined4 **)(in_ECX + 0x5efc);
        do {
          if (*(int *)*puVar11 == piVar12[1]) {
            local_6c = (*(undefined4 **)(in_ECX + 0x5efc))[uVar10];
            goto LAB_004de637;
          }
          uVar10 = uVar10 + 1;
          puVar11 = puVar11 + 1;
        } while (uVar10 < uVar6);
      }
      local_6c = 0;
LAB_004de637:
      uVar10 = 0;
      if (uVar6 != 0) {
        puVar11 = *(undefined4 **)(in_ECX + 0x5efc);
        do {
          if (*(int *)*puVar11 == piVar12[2]) {
            piVar13 = (int *)(*(undefined4 **)(in_ECX + 0x5efc))[uVar10];
            goto LAB_004de666;
          }
          uVar10 = uVar10 + 1;
          puVar11 = puVar11 + 1;
        } while (uVar10 < uVar6);
      }
      piVar13 = (int *)0x0;
LAB_004de666:
      if (local_6c != 0) {
        *(short *)(local_6c + 4) = *(short *)(local_6c + 4) + 1;
      }
      if (piVar13 != (int *)0x0) {
        *(short *)(piVar13 + 2) = (short)piVar13[2] + 1;
        uVar10 = 0;
        uVar6 = *(int *)(in_ECX + 0x5eec) - *(int *)(in_ECX + 0x5ee8) >> 2;
        if (uVar6 != 0) {
          piVar14 = *(int **)(in_ECX + 0x5ee8);
          do {
            if (*piVar14 == *piVar13) {
              if (*(int *)(in_ECX + 0x5f20) < 1) {
                *(undefined4 *)(in_ECX + 0x5f20) = 0;
              }
              else {
                *(int *)(in_ECX + 0x5f20) = *(int *)(in_ECX + 0x5f20) + -1;
              }
              goto LAB_004de6e7;
            }
            uVar10 = uVar10 + 1;
            piVar14 = piVar14 + 1;
          } while (uVar10 < uVar6);
        }
        if (*(int *)(in_ECX + 0x5f1c) < 1) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x5f1c) + -1;
        }
        *(int *)(in_ECX + 0x5f1c) = iVar7;
      }
LAB_004de6e7:
      if ((piVar12[1] != 0) && (piVar12[2] != 0)) {
        local_38 = 7;
        local_3c = 0;
        local_4c[0] = (undefined4 *****)((uint)local_4c[0] & 0xffff0000);
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (undefined4 *****)((uint)local_30[0] & 0xffff0000);
        local_8._1_3_ = 0;
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_8._0_1_ = 2;
          local_8._1_3_ = 0;
          FUN_004f3d80(uVar4);
          _atexit((_func_4879 *)&LAB_00bcd1e0);
        }
        local_8._0_1_ = 1;
        local_6c = piVar12[1];
        FUN_008438c0(&local_6c);
        if (local_7c == DAT_00fb7574) {
          local_3c = 0;
          ppppppuVar8 = (undefined4 ******)local_4c[0];
          if (local_38 < 8) {
            ppppppuVar8 = local_4c;
          }
          *(undefined2 *)ppppppuVar8 = 0;
        }
        else {
          FUN_004026e0(*(undefined4 *)(local_7c + 0x10),0,0xffffffff);
        }
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_8._0_1_ = 3;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_8._0_1_ = 1;
        }
        local_6c = piVar12[2];
        FUN_008438c0(&local_6c);
        if (local_84 == DAT_00fb7574) {
          local_20 = 0;
          ppppppuVar8 = (undefined4 ******)local_30[0];
          if (local_1c < 8) {
            ppppppuVar8 = local_30;
          }
          *(undefined2 *)ppppppuVar8 = 0;
        }
        else {
          FUN_004026e0(*(undefined4 *)(local_84 + 0x10),0,0xffffffff);
        }
        ppppppuVar8 = (undefined4 ******)local_4c[0];
        if (local_38 < 8) {
          ppppppuVar8 = local_4c;
        }
        if ((DAT_00fe5b08 & 1) == 0) {
          DAT_00fe5b08 = DAT_00fe5b08 | 1;
          local_8._0_1_ = 4;
          FUN_00584c40(&DAT_00fe5ae8);
          _atexit((_func_4879 *)&LAB_00bcf380);
          local_8._0_1_ = 1;
        }
        local_6c = 0x28;
        FUN_005740f0(&local_6c);
        if (local_80 == DAT_00fe5aec) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        uVar9 = FUN_00498ef0(ppppppuVar8);
        if ((DAT_00fb11e0 & 1) == 0) {
          DAT_00fb11e0 = DAT_00fb11e0 | 1;
          local_8._0_1_ = 6;
          FUN_004d4d10();
          _atexit((_func_4879 *)&LAB_00bccef0);
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        FUN_004d6b30(uVar9);
        if (7 < local_54) {
          FUN_0089120c(local_68);
        }
        local_54 = 7;
        local_58 = 0;
        local_68 = local_68 & 0xffff0000;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_8 = 0xffffffff;
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (undefined4 *****)((uint)local_30[0] & 0xffff0000);
        if (7 < local_38) {
          FUN_0089120c(local_4c[0]);
        }
        local_38 = 7;
        local_3c = 0;
        local_4c[0] = (undefined4 *****)((uint)local_4c[0] & 0xffff0000);
      }
      piVar12 = piVar12 + 3;
      uVar5 = uVar5 + 0xc;
      ppvVar3 = ExceptionList;
    }
    else {
      if (*piVar12 != 2) break;
      uVar10 = 0;
      uVar6 = *(int *)(in_ECX + 0x5f00) - *(int *)(in_ECX + 0x5efc) >> 2;
      if (uVar6 == 0) {
LAB_004de5ee:
        piVar12 = piVar12 + 2;
        uVar5 = uVar5 + 8;
        ppvVar3 = ExceptionList;
      }
      else {
        puVar11 = *(undefined4 **)(in_ECX + 0x5efc);
        do {
          if (*(int *)*puVar11 == piVar12[1]) {
            iVar7 = (*(undefined4 **)(in_ECX + 0x5efc))[uVar10];
            if (iVar7 != 0) {
              psVar1 = (short *)(iVar7 + 6);
              *psVar1 = *psVar1 + 1;
            }
            goto LAB_004de5ee;
          }
          uVar10 = uVar10 + 1;
          puVar11 = puVar11 + 1;
        } while (uVar10 < uVar6);
        piVar12 = piVar12 + 2;
        uVar5 = uVar5 + 8;
        ppvVar3 = ExceptionList;
      }
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 7;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf42a6);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

