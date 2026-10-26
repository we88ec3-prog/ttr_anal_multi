
void FUN_00674fb0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint local_50;
  undefined4 local_4c;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009486b8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x1b4) != 0) {
    iVar1 = *(int *)(param_1 + 0x1b4) + 0x20;
    uVar3 = FUN_00538e60(local_14);
    local_8 = 0;
    FUN_00757800(uVar3);
    local_8 = 0xffffffff;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    (**(code **)(**(int **)(param_1 + 0x104) + 200))();
    if (param_2 < 1) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x108) + 0x24c);
      if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 != 0)) {
        FUN_006438f0(iVar2);
      }
      FUN_00757710();
      FUN_005384c0(&local_40,*(undefined4 *)(param_1 + 0x1b8));
      local_8 = 1;
      uVar6 = local_3c - local_40 >> 2;
      (**(code **)(**(int **)(param_1 + 0x108) + 0x90))(uVar6 != 0);
      local_50 = 0;
      if (uVar6 != 0) {
        do {
          uVar3 = FUN_00538f00(iVar1);
          local_8._0_1_ = 2;
          iVar2 = *(int *)(*(int *)(param_1 + 0x108) + 0x24c);
          if (iVar2 != 0) {
            iVar2 = *(int *)(iVar2 + 0xcc);
            if (iVar2 != 0) {
              FUN_0075d370(*(undefined4 *)(iVar2 + 0xe4));
            }
            FUN_00408810();
            FUN_00757800(uVar3);
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          if (7 < local_1c) {
            FUN_0089120c(local_30);
          }
          local_50 = local_50 + 1;
        } while (local_50 < uVar6);
      }
      iVar2 = *(int *)(*(int *)(param_1 + 0x108) + 0x24c);
      if (iVar2 != 0) {
        FUN_00749920(iVar2);
      }
      uVar3 = FUN_00538f00(iVar1);
      local_8._0_1_ = 3;
      FUN_00757800(uVar3);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      (**(code **)(**(int **)(param_1 + 0x108) + 200))();
      local_8 = 0xffffffff;
      if (local_40 != 0) {
        FUN_0089120c(local_40);
      }
    }
    if (param_2 < 2) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x10c) + 0x24c);
      if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 != 0)) {
        FUN_006438f0(iVar2);
      }
      FUN_00757710();
      FUN_00538650(*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1bc));
      local_8 = 4;
      uVar6 = local_3c - local_40 >> 2;
      (**(code **)(**(int **)(param_1 + 0x10c) + 0x90))(uVar6 != 0);
      local_50 = 0;
      if (uVar6 != 0) {
        do {
          uVar3 = FUN_00538fd0(iVar1,*(undefined4 *)(param_1 + 0x1bc));
          local_8._0_1_ = 5;
          iVar2 = *(int *)(param_1 + 0x10c);
          iVar4 = *(int *)(iVar2 + 0x24c);
          if (iVar4 != 0) {
            iVar4 = *(int *)(iVar4 + 0xcc);
            if (iVar4 == 0) {
              iVar4 = -1;
            }
            else {
              iVar4 = FUN_0075d370(*(undefined4 *)(iVar4 + 0xe4));
            }
            iVar2 = *(int *)(*(int *)(iVar2 + 0x24c) + 0xcc);
            if (iVar2 != 0) {
              for (piVar5 = *(int **)(iVar2 + 0xa8);
                  (piVar5 != *(int **)(iVar2 + 0xac) && (*(int *)(*piVar5 + 0x20) != iVar4));
                  piVar5 = piVar5 + 1) {
              }
            }
            FUN_00757800(uVar3);
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          if (7 < local_1c) {
            FUN_0089120c(local_30);
          }
          local_50 = local_50 + 1;
        } while (local_50 < uVar6);
      }
      iVar2 = *(int *)(*(int *)(param_1 + 0x10c) + 0x24c);
      if (iVar2 != 0) {
        FUN_00749920(iVar2);
      }
      uVar3 = FUN_00538fd0(iVar1,*(undefined4 *)(param_1 + 0x1bc));
      local_8._0_1_ = 6;
      FUN_00757800(uVar3);
      local_8 = CONCAT31(local_8._1_3_,4);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_30 = local_30 & 0xffff0000;
      local_1c = 7;
      local_20 = 0;
      (**(code **)(**(int **)(param_1 + 0x10c) + 200))();
      local_8 = 0xffffffff;
      if (local_40 != 0) {
        FUN_0089120c(local_40);
      }
    }
    if ((*(uint *)(*(int *)(param_1 + 0x104) + 0x28) >> 7 & 1) == 0) {
      *(undefined4 *)(param_1 + 0x1b8) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c4) = 0;
    }
    if ((*(uint *)(*(int *)(param_1 + 0x108) + 0x28) >> 7 & 1) == 0) {
      *(undefined4 *)(param_1 + 0x1bc) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c4) = 1;
    }
    if ((*(uint *)(*(int *)(param_1 + 0x10c) + 0x28) >> 7 & 1) == 0) {
      *(undefined4 *)(param_1 + 0x1c0) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c4) = 2;
    }
    FUN_00675b10(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

