
void FUN_006a05a0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c516;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_8 = 0;
    FUN_00533f80(local_14);
    _atexit((_func_4879 *)&LAB_00bced30);
  }
  local_8 = 0xffffffff;
  uVar5 = FUN_00538e60();
  local_8 = 1;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  if (param_2 < 1) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x24c);
    if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
      FUN_006438f0(iVar1);
    }
    FUN_00757710();
    FUN_005384c0(&local_24,*(undefined4 *)(param_1 + 0x148));
    local_8 = 2;
    uVar10 = local_20 - local_24 >> 2;
    (**(code **)(**(int **)(param_1 + 0x100) + 0x90))(uVar10 != 0);
    local_50 = 0;
    if (uVar10 != 0) {
      do {
        uVar5 = FUN_00538f00(&DAT_00fe1bec);
        local_8._0_1_ = 3;
        iVar1 = *(int *)(param_1 + 0x100);
        iVar6 = *(int *)(iVar1 + 0x24c);
        if (iVar6 != 0) {
          iVar6 = *(int *)(iVar6 + 0xcc);
          if (iVar6 == 0) {
            iVar6 = -1;
          }
          else {
            iVar6 = FUN_0075d370(*(undefined4 *)(iVar6 + 0xe4));
          }
          iVar1 = *(int *)(*(int *)(iVar1 + 0x24c) + 0xcc);
          if (iVar1 != 0) {
            for (piVar9 = *(int **)(iVar1 + 0xa8);
                (piVar9 != *(int **)(iVar1 + 0xac) && (*(int *)(*piVar9 + 0x20) != iVar6));
                piVar9 = piVar9 + 1) {
            }
          }
          FUN_00757800(uVar5);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if (7 < local_38) {
          FUN_0089120c(local_4c);
        }
        local_50 = local_50 + 1;
      } while (local_50 < uVar10);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x24c);
    if (iVar1 != 0) {
      FUN_00749920(iVar1);
    }
    uVar5 = FUN_00538f00(&DAT_00fe1bec);
    local_8._0_1_ = 4;
    FUN_00757800(uVar5);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    (**(code **)(**(int **)(param_1 + 0x100) + 200))();
    local_8 = 0xffffffff;
    if (local_24 != 0) {
      FUN_0089120c(local_24);
    }
  }
  if (param_2 < 2) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x104) + 0x24c);
    if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
      FUN_006438f0(iVar1);
    }
    FUN_00757710();
    FUN_00538650(*(undefined4 *)(param_1 + 0x148),*(undefined4 *)(param_1 + 0x14c));
    local_8 = 5;
    uVar10 = local_20 - local_24 >> 2;
    (**(code **)(**(int **)(param_1 + 0x104) + 0x90))(uVar10 != 0);
    local_50 = 0;
    if (uVar10 != 0) {
      do {
        uVar5 = FUN_00538fd0(&DAT_00fe1bec,*(undefined4 *)(param_1 + 0x14c));
        local_8._0_1_ = 6;
        iVar1 = *(int *)(param_1 + 0x104);
        iVar6 = *(int *)(iVar1 + 0x24c);
        if (iVar6 != 0) {
          piVar9 = *(int **)(iVar6 + 0xcc);
          if (piVar9 == (int *)0x0) {
            iVar6 = -1;
          }
          else {
            piVar2 = (int *)piVar9[0x29];
            iVar6 = piVar9[0x39];
            if (piVar2 == (int *)0x0) {
              iVar6 = -1;
            }
            else {
              if (piVar9[0x2e] == piVar9[0x2f]) {
                iVar7 = (**(code **)(*piVar2 + 0x28))();
              }
              else {
                iVar7 = *(int *)(piVar9[0x2f] + -4);
                (**(code **)(*piVar2 + 0x2c))(iVar7);
                if (piVar9[0x2e] != piVar9[0x2f]) {
                  piVar9[0x2f] = piVar9[0x2f] + -4;
                }
              }
              *(int *)(iVar7 + 0x20) = iVar6;
              (**(code **)(*piVar9 + 0x70))(iVar7);
              FUN_00443d10();
              uVar8 = piVar9[0x39];
              if ((uint)piVar9[0x39] < iVar6 + 1U) {
                uVar8 = iVar6 + 1U;
              }
              piVar9[0x39] = uVar8;
            }
          }
          iVar1 = *(int *)(*(int *)(iVar1 + 0x24c) + 0xcc);
          if (iVar1 != 0) {
            for (piVar9 = *(int **)(iVar1 + 0xa8);
                (piVar9 != *(int **)(iVar1 + 0xac) && (*(int *)(*piVar9 + 0x20) != iVar6));
                piVar9 = piVar9 + 1) {
            }
          }
          FUN_00757800(uVar5);
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        if (7 < local_38) {
          FUN_0089120c(local_4c);
        }
        local_50 = local_50 + 1;
      } while (local_50 < uVar10);
    }
    piVar9 = *(int **)(*(int *)(param_1 + 0x104) + 0x24c);
    if (piVar9 != (int *)0x0) {
      puVar3 = (undefined4 *)piVar9[0x19];
      for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
        iVar1 = puVar4[2];
        if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
        }
      }
      (**(code **)(*piVar9 + 0x128))();
    }
    uVar5 = FUN_00538fd0(&DAT_00fe1bec,*(undefined4 *)(param_1 + 0x14c));
    local_8._0_1_ = 7;
    FUN_00757800(uVar5);
    local_8 = CONCAT31(local_8._1_3_,5);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    (**(code **)(**(int **)(param_1 + 0x104) + 200))();
    if (local_24 != 0) {
      FUN_0089120c(local_24);
    }
  }
  if ((*(uint *)(*(int *)(param_1 + 0xfc) + 0x28) >> 7 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x148) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x154) = 0;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x100) + 0x28) >> 7 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x14c) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x154) = 1;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x104) + 0x28) >> 7 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x150) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x154) = 2;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

