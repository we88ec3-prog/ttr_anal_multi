
void FUN_0069a050(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *local_28;
  uint local_24;
  undefined4 *local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091243e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  uVar3 = *(int *)(param_1 + 0x168) - *(int *)(param_1 + 0x164) >> 2;
  uVar2 = 0;
  local_24 = 0;
  if (uVar3 != 0) {
    local_28 = (undefined4 *)(param_1 + 0x9c);
    do {
      if (7 < uVar2) goto LAB_0069a18e;
      local_20 = *(undefined4 **)(*(int *)(param_1 + 0x164) + local_24 * 4);
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 0;
        FUN_0051c120(uVar1);
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      local_20 = (undefined4 *)*local_20;
      FUN_008438c0(&local_20);
      if ((local_1c != DAT_00f8d91c) && (iVar5 = *(int *)(local_1c + 0x10), iVar5 != 0)) {
        (**(code **)(*(int *)*local_28 + 0x19c))
                  (*(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x1c),0,0);
        uVar2 = uVar2 + 1;
        local_28 = local_28 + 1;
      }
      local_24 = local_24 + 1;
    } while (local_24 < uVar3);
  }
  if (uVar2 < 8) {
    puVar4 = (undefined4 *)(param_1 + 0x9c + uVar2 * 4);
    iVar5 = 8 - uVar2;
    do {
      (**(code **)(*(int *)*puVar4 + 0x19c))(0xffffffff,0xffffffff,0,0);
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
LAB_0069a18e:
  (**(code **)(**(int **)(param_1 + 0x98) + 200))();
  ExceptionList = local_14;
  return;
}

