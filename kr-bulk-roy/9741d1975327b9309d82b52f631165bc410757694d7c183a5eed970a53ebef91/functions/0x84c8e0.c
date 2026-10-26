
undefined4 FUN_0084c8e0(int *param_1,uint *param_2,int param_3,int *param_4)

{
  undefined **ppuVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined **ppuVar10;
  uint *puVar11;
  int iVar12;
  undefined1 local_a0 [8];
  int local_98;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_64;
  undefined4 *local_60;
  undefined4 local_5c;
  undefined **local_54;
  undefined1 local_50 [12];
  undefined4 *local_44;
  undefined4 local_40;
  int local_38;
  char *local_34;
  undefined1 local_30 [4];
  int *local_2c;
  undefined4 local_28;
  undefined **local_20;
  undefined **local_1c;
  undefined **local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e9d7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_28 = 0;
  local_2c = (int *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (local_2c == (int *)0x0) {
    local_34 = (char *)0x0;
    std::exception::exception((exception *)&local_1c,&local_34);
    local_1c = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_1c,&DAT_00c857a8);
  }
  *local_2c = (int)local_2c;
  local_2c[1] = (int)local_2c;
  local_2c[2] = (int)local_2c;
  *(undefined1 *)(local_2c + 4) = 1;
  *(undefined1 *)((int)local_2c + 0x11) = 1;
  local_8 = 0;
  puVar11 = (uint *)((int)param_2 + 0x20);
  local_38 = 3;
  do {
    uVar8 = 0;
    if (*puVar11 != 0) {
      param_2 = puVar11 + -8;
      do {
        uVar5 = FUN_006bde40(param_2);
        FUN_0044bbd0(local_30,uVar5);
        param_2 = param_2 + 2;
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar11);
    }
    puVar11 = puVar11 + 9;
    local_38 = local_38 + -1;
  } while (local_38 != 0);
  ppuVar10 = (undefined **)0x0;
  local_20 = (undefined **)0x0;
  local_1c = (undefined **)0x0;
  local_18 = (undefined **)0x0;
  local_8._0_1_ = 1;
  piVar9 = (int *)*local_2c;
  param_2 = (uint *)local_2c;
  local_38 = 0;
  if (piVar9 != local_2c) {
    do {
      ppuVar1 = (undefined **)(piVar9 + 3);
      if ((ppuVar1 < local_1c) && (ppuVar10 <= ppuVar1)) {
        iVar12 = (int)ppuVar1 - (int)ppuVar10;
        if (local_1c == local_18) {
          uVar8 = (int)local_1c - (int)ppuVar10 >> 2;
          if (0x3ffffffe < uVar8) {
LAB_0084cb23:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar8 = uVar8 + 1;
          uVar7 = (int)local_18 - (int)ppuVar10 >> 2;
          if (uVar7 < uVar8) {
            if (0x3fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar8) {
              uVar7 = uVar8;
            }
            FUN_00797980(uVar7);
            ppuVar10 = local_20;
          }
        }
        if (local_1c != (undefined **)0x0) {
          *local_1c = ppuVar10[iVar12 >> 2];
        }
      }
      else {
        if (local_1c == local_18) {
          uVar8 = (int)local_1c - (int)ppuVar10 >> 2;
          if (0x3ffffffe < uVar8) goto LAB_0084cb23;
          uVar8 = uVar8 + 1;
          uVar7 = (int)local_18 - (int)ppuVar10 >> 2;
          if (uVar7 < uVar8) {
            if (0x3fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar8) {
              uVar7 = uVar8;
            }
            FUN_00797980(uVar7);
            ppuVar10 = local_20;
          }
        }
        if (local_1c != (undefined **)0x0) {
          *local_1c = *ppuVar1;
        }
      }
      local_1c = local_1c + 1;
      if (*(char *)((int)piVar9 + 0x11) == '\0') {
        piVar3 = (int *)piVar9[2];
        if (*(char *)((int)piVar3 + 0x11) == '\0') {
          cVar2 = *(char *)(*piVar3 + 0x11);
          piVar9 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar2 == '\0') {
            cVar2 = *(char *)(*piVar3 + 0x11);
            piVar9 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar2 = *(char *)(piVar9[1] + 0x11);
          piVar4 = (int *)piVar9[1];
          piVar3 = piVar9;
          while ((piVar9 = piVar4, cVar2 == '\0' && (piVar3 == (int *)piVar9[2]))) {
            cVar2 = *(char *)(piVar9[1] + 0x11);
            piVar4 = (int *)piVar9[1];
            piVar3 = piVar9;
          }
        }
      }
    } while ((uint *)piVar9 != param_2);
  }
  piVar9 = local_2c;
  param_2 = (uint *)FUN_0084c840();
  uVar5 = param_3;
  *param_4 = (int)param_2;
  if (param_2 == (uint *)0xffffffff) {
    if (ppuVar10 != (undefined **)0x0) {
      FUN_0089120c(ppuVar10);
      piVar9 = local_2c;
    }
    local_8 = 2;
    FUN_004ca160(*piVar9,piVar9);
    FUN_0089120c(local_2c);
    ExceptionList = local_10;
    return 0;
  }
  FUN_00848020(param_3);
  if (param_4 == (int *)param_1[5]) {
    local_40 = 0;
    local_44 = (undefined4 *)FUN_00891268(0x38);
    if (local_44 == (undefined4 *)0x0) {
      param_4 = (int *)0x0;
      std::exception::exception((exception *)&local_54,(char **)&param_4);
      local_54 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_54,&DAT_00c857a8);
    }
    *local_44 = local_44;
    local_44[1] = local_44;
    local_44[2] = local_44;
    *(undefined1 *)(local_44 + 0xd) = 1;
    *(undefined1 *)((int)local_44 + 0x35) = 1;
    local_8._0_1_ = 3;
    uVar5 = FUN_008524c0();
    local_8._0_1_ = 4;
    uVar5 = FUN_008537e0(uVar5);
    FUN_008527c0(local_50,uVar5);
    param_4 = &local_64;
    local_8._0_1_ = 5;
    FUN_00850e70(*local_60,local_60);
    FUN_0089120c(local_60);
    local_8._0_1_ = 6;
    FUN_00850e70(*local_44,local_44);
    local_8._0_1_ = 1;
    FUN_0089120c(local_44);
    uVar5 = param_3;
  }
  iVar6 = FUN_008500d0(uVar5);
  iVar12 = (int)param_2;
  param_3 = (int)param_2;
  FUN_0084ffc0(&param_3);
  if (param_4 == *(int **)(iVar6 + 4)) {
    local_78 = iVar12 * 0x10 + *param_1;
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    local_64 = 0;
    local_60 = (undefined4 *)0x0;
    local_5c = 0;
    local_8._0_1_ = 7;
    uVar5 = FUN_008524e0(local_a0,&param_2);
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_00853710(uVar5);
    FUN_008525e0(iVar6,local_50);
    if (local_88 != 0) {
      FUN_0089120c(local_88);
    }
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    if (local_98 != 0) {
      FUN_0089120c(local_98);
    }
    local_8._0_1_ = 1;
  }
  uVar5 = FUN_0084fec0();
  if (local_20 != (undefined **)0x0) {
    FUN_0089120c(local_20);
  }
  local_8 = 9;
  FUN_004ca160(*local_2c,local_2c);
  FUN_0089120c(local_2c);
  ExceptionList = local_10;
  return uVar5;
}

