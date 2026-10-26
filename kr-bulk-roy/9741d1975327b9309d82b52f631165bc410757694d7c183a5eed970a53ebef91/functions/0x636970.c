
void FUN_00636970(int param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 uVar8;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093dd1c;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  iVar4 = *(int *)(param_1 + 0x90);
  uVar7 = 0;
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_1 + 0x94);
    bVar2 = 0;
    ExceptionList = &local_14;
    if ((iVar4 != 0) && (*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 3 != 0)) {
      do {
        iVar1 = *(int *)(iVar4 + 4) + uVar7 * 8;
        if (*(int *)(*(int *)(iVar4 + 4) + uVar7 * 8) == 3) {
          if ((DAT_00f94390 & 1) == 0) {
            DAT_00f94390 = DAT_00f94390 | 1;
            local_c = 0;
            FUN_004e1590(uVar3);
            _atexit((_func_4879 *)&LAB_00bccc80);
          }
          iVar4 = *(int *)(DAT_00f94300 + 0x50b8) / 0x14;
          if (((int)(uint)*(ushort *)(iVar1 + 4) <= iVar4) &&
             (iVar4 <= (int)(uint)*(ushort *)(iVar1 + 6))) {
            bVar2 = 1;
          }
        }
        iVar4 = *(int *)(param_1 + 0x94);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 3));
    }
    local_c = 0xffffffff;
    iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar4 == 0) {
      ExceptionList = local_14;
      return;
    }
    uVar3 = -(uint)bVar2 & 10;
    piVar5 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
    if ((DAT_00fb72a4 & 1) == 0) {
      DAT_00fb72a4 = DAT_00fb72a4 | 1;
      local_c = 1;
      FUN_0049f850();
      _atexit((_func_4879 *)&LAB_00bccfe0);
      local_c = 0xffffffff;
    }
    (**(code **)(*piVar5 + 0x4c))(uVar3);
    uVar8 = *(undefined4 *)(param_1 + 0x84);
    puVar6 = &DAT_00fb72a8;
  }
  else {
    if (iVar4 == 2) {
      ExceptionList = &local_14;
      iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      if (iVar4 == 0) {
        ExceptionList = local_14;
        return;
      }
      piVar5 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
      uVar3 = 1;
    }
    else {
      if (iVar4 != 3) {
        return;
      }
      ExceptionList = &local_14;
      iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      if (iVar4 == 0) {
        ExceptionList = local_14;
        return;
      }
      piVar5 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
      uVar3 = 2;
    }
    (**(code **)(*piVar5 + 0x4c))(uVar3);
    uVar8 = *(undefined4 *)(param_1 + 0x84);
    puVar6 = (undefined *)FUN_0041d910(uVar8);
  }
  FUN_004a01b0(puVar6,uVar8,uVar3);
  ExceptionList = local_14;
  return;
}

