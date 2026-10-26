
uint FUN_005cf860(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  byte bVar9;
  uint uVar10;
  undefined1 local_98 [12];
  undefined1 local_8c [4];
  undefined4 *local_88;
  undefined1 local_70 [12];
  undefined1 local_64 [4];
  undefined4 *local_60;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093f3a4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  FUN_0082ef00(&param_3);
  if ((local_1c == DAT_00fb11b0) || (local_40 = *(int *)(local_1c + 0x10), local_40 == 0)) {
    ExceptionList = local_10;
    return 0;
  }
  if (param_4 < (uint)(*(int *)(local_40 + 0x18) - *(int *)(local_40 + 0x14) >> 2)) {
    iVar1 = *(int *)(*(int *)(local_40 + 0x14) + param_4 * 4);
    local_18 = *(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2;
  }
  else {
    local_18 = 0;
  }
  param_3 = param_3 & 0xffffff;
  local_1c = 0;
  uVar6 = local_18;
  if (local_18 != 0) {
    do {
      uVar10 = local_1c;
      iVar1 = *(int *)(*(int *)(local_40 + 0x14) + param_4 * 4);
      if (local_1c < (uint)(*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2)) {
        piVar2 = *(int **)(*(int *)(iVar1 + 0x14) + local_1c * 4);
        if (piVar2 != (int *)0x0) {
          uVar5 = (**(code **)(*piVar2 + 4))();
          if ((uVar5 & 0x14100000) == 0x14100000) {
            uVar6 = (**(code **)(*piVar2 + 4))();
            uVar5 = ~-(uint)((uVar6 & 0x14100000) != 0x14100000) & (uint)piVar2;
            uVar6 = local_18;
            local_20 = uVar5;
            if (uVar5 != 0) {
              FUN_007e8a90(&local_3c,uVar5 + 8);
              local_8 = 1;
              local_24 = local_38 - local_3c >> 2;
              if (*(int *)(*(int *)(uVar5 + 0x18) + 4) == 1) {
                FUN_00830e10();
                local_8._0_1_ = 2;
                bVar9 = 1;
                local_28 = 0;
                if (local_24 != 0) {
                  do {
                    if (bVar9 == 0) break;
                    if (local_24 <= local_28) {
                    /* WARNING: Subroutine does not return */
                      FUN_0087db7d("invalid vector<T> subscript");
                    }
                    iVar1 = *(int *)(local_3c + local_28 * 4);
                    switch(*(undefined4 *)(iVar1 + 4)) {
                    case 2:
                    case 3:
                    case 4:
                    case 6:
                    case 7:
                    case 9:
                    case 10:
switchD_005cfa35_caseD_2:
                      bVar9 = 0;
                      break;
                    case 5:
                      local_14 = (undefined1 *)(uint)*(ushort *)(iVar1 + 8);
                      bVar4 = FUN_0081b3d0();
                      bVar9 = bVar9 & bVar4 & param_2 == ((uint)local_14 & 0xffff);
                      uVar8 = FUN_00830d00(local_98,local_70,*(int *)(uVar5 + 0x18) + 8);
                      local_8._0_1_ = 3;
                      FUN_005cf7e0(uVar8);
                      local_8._0_1_ = 2;
                      FUN_005ce3c0();
                      uVar5 = local_20;
                      break;
                    case 8:
                      iVar3 = *(int *)(iVar1 + 8);
                      iVar7 = FUN_00404ba0();
                      uVar8 = *(undefined4 *)(iVar7 + 0x5f50);
                      FUN_00489d00();
                      iVar7 = FUN_004d2da0(uVar8);
                      local_14 = (undefined1 *)(uint)*(byte *)(iVar1 + 0xc);
                      FUN_00826280(&local_14);
                      uVar5 = local_20;
                      if (local_2c == *(int *)(iVar7 + 4)) goto switchD_005cfa35_caseD_2;
                      bVar4 = FUN_0081b540();
                      bVar9 = (bVar9 & iVar3 != 0) != 0 & bVar4;
                      uVar5 = local_20;
                      break;
                    case 0xb:
                      iVar1 = *(int *)(iVar1 + 8);
                      FUN_0040f060();
                      (**(code **)(*DAT_00fba7a4 + 0x20))();
                      bVar4 = FUN_0081b600();
                      bVar9 = bVar9 & iVar1 != 0 & bVar4;
                    }
                    local_28 = local_28 + 1;
                  } while (local_28 < local_24);
                }
                if ((param_3._3_1_ == '\0') && (bVar9 == 0)) {
                  param_3 = param_3 & 0xffffff;
                }
                else {
                  param_3 = CONCAT13(1,(undefined3)param_3);
                  if (bVar9 != 0) {
                    uVar8 = FUN_00830d00(local_98,param_1,local_70);
                    local_8._0_1_ = 4;
                    FUN_005cf7e0(uVar8);
                    local_14 = local_8c;
                    local_8._0_1_ = 5;
                    FUN_004ca160(*local_88,local_88);
                    FUN_0089120c(local_88);
                  }
                }
                local_14 = local_64;
                local_8 = CONCAT31(local_8._1_3_,6);
                FUN_004ca160(*local_60,local_60);
                FUN_0089120c(local_60);
                uVar10 = local_1c;
              }
              local_8 = 0xffffffff;
              if (local_3c != 0) {
                FUN_0089120c(local_3c);
              }
              local_3c = 0;
              local_38 = 0;
              local_34 = 0;
              uVar6 = local_18;
            }
          }
        }
      }
      local_1c = uVar10 + 1;
    } while (local_1c < uVar6);
  }
  ExceptionList = local_10;
  return param_3 >> 0x18;
}

