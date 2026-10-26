
void FUN_00757940(undefined4 *param_1,short param_2,short param_3)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int local_9c;
  int local_98;
  undefined4 *local_94;
  undefined4 *local_90;
  undefined4 *local_8c;
  undefined4 local_88;
  int local_80;
  int local_7c;
  undefined4 local_78;
  int *local_70;
  int local_6c;
  undefined4 local_68;
  int local_60;
  int local_5c;
  undefined4 *local_58;
  undefined4 *local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092875b;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00597b70(DAT_00d61f20 ^ (uint)&stack0xffffff50);
  iVar11 = param_1[4];
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_70 = (int *)0x0;
  local_6c = 0;
  local_68 = 0;
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  local_90 = (undefined4 *)0x0;
  local_8c = (undefined4 *)0x0;
  local_88 = 0;
  FUN_0075a730();
  bVar2 = false;
  local_c = CONCAT31(local_c._1_3_,2);
  bVar3 = false;
  local_9c = 0;
  iVar8 = 0;
  iVar10 = 0;
  if (iVar11 < 1) {
LAB_00757ac2:
    if (((iVar8 - (int)local_70 ^ iVar10 - local_80) & 0xfffffffcU) == 0) {
LAB_00757ada:
      local_98 = iVar10 - local_80 >> 2;
      if (0 < local_98) {
        iVar11 = local_80 - (int)local_70;
        puVar5 = local_90;
        piVar9 = local_70;
        local_60 = iVar11;
        do {
          if (*(int *)(iVar11 + (int)piVar9) < *piVar9) {
            puVar6 = puVar5;
            if (7 < (uint)puVar5[5]) {
              puVar6 = (undefined4 *)*puVar5;
            }
            local_94 = (undefined4 *)FUN_008935e3(puVar6);
            local_58 = local_94;
            FUN_00848020(&local_94);
            if (local_5c == param_1[0xb]) {
              local_4c = *piVar9;
              local_50 = *(undefined4 *)(iVar11 + (int)piVar9);
              local_2c = local_2c & 0xffffff00;
              local_44 = local_2c;
              local_54 = local_58;
              local_48 = 0xffffffff;
              uVar7 = FUN_0054f7d0();
              FUN_00597db0(param_1 + 10,uVar7);
              iVar11 = local_60;
            }
            else {
              iVar8 = *piVar9;
              *(undefined4 *)(local_5c + 0x10) = *(undefined4 *)(iVar11 + (int)piVar9);
              *(int *)(local_5c + 0x14) = iVar8;
              local_1c = local_1c & 0xffffff00;
              *(undefined4 *)(local_5c + 0x18) = 0xffffffff;
              *(uint *)(local_5c + 0x1c) = local_1c;
            }
          }
          puVar5 = puVar5 + 7;
          piVar9 = piVar9 + 1;
          local_98 = local_98 + -1;
        } while (local_98 != 0);
      }
    }
    puVar4 = local_8c;
    puVar6 = local_90;
    puVar5 = local_90;
    if (local_90 == (undefined4 *)0x0) goto LAB_00757c17;
    for (; puVar5 != puVar4; puVar5 = puVar5 + 7) {
      if (7 < (uint)puVar5[5]) {
        FUN_0089120c(*puVar5);
      }
      puVar5[5] = 7;
      puVar5[4] = 0;
      *(undefined2 *)puVar5 = 0;
    }
  }
  else {
    local_94 = local_90 + -7;
    do {
      uVar1 = param_1[5];
      puVar5 = param_1;
      if (7 < uVar1) {
        puVar5 = (undefined4 *)*param_1;
      }
      if (*(short *)((int)puVar5 + local_9c * 2) == param_2) {
        if (bVar2) goto LAB_00757a97;
        FUN_004a8680();
        local_94 = local_94 + 7;
        bVar3 = true;
        bVar2 = bVar3;
      }
      else {
        puVar5 = param_1;
        if (7 < uVar1) {
          puVar5 = (undefined4 *)*param_1;
        }
        if (*(short *)((int)puVar5 + local_9c * 2) == param_3) {
          if (!bVar2) goto LAB_00757a97;
          FUN_004a8680();
          bVar3 = false;
          bVar2 = bVar3;
        }
        else if (bVar2) {
          puVar5 = param_1;
          if (7 < uVar1) {
            puVar5 = (undefined4 *)*param_1;
          }
          FUN_00440010(1,*(undefined2 *)((int)puVar5 + local_9c * 2));
          bVar2 = bVar3;
        }
      }
      local_9c = local_9c + 1;
    } while (local_9c < iVar11);
    if (!bVar2) {
      iVar8 = local_6c;
      iVar10 = local_7c;
      if (local_80 == local_7c) goto LAB_00757ac2;
      goto LAB_00757ada;
    }
LAB_00757a97:
    puVar6 = local_90;
    if (local_90 == (undefined4 *)0x0) goto LAB_00757c17;
    FUN_0049bf30();
  }
  FUN_0089120c(puVar6);
LAB_00757c17:
  if (local_70 != (int *)0x0) {
    FUN_0089120c(local_70);
  }
  if (local_80 != 0) {
    FUN_0089120c(local_80);
  }
  ExceptionList = local_14;
  return;
}

