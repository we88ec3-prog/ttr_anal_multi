
void FUN_00656180(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_34;
  int local_30;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d50a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar2 = DAT_00fab130;
  local_c = 0xffffffff;
  iVar3 = *(int *)(DAT_00fab130 + 0x5ebc) - *(int *)(DAT_00fab130 + 0x5eb8) >> 3;
  if (*(uint *)(in_ECX + 0x108) <
      (uint)(*(int *)(DAT_00fab130 + 0x5ecc) - *(int *)(DAT_00fab130 + 0x5ec8) >> 2)) {
    local_34 = *(uint *)(*(int *)(DAT_00fab130 + 0x5ec8) + *(uint *)(in_ECX + 0x108) * 4);
  }
  else {
    local_34 = 0;
  }
  local_30 = local_34 * 5;
  local_1c = iVar3 * 5;
  puVar5 = (undefined4 *)(in_ECX + 0xf4);
  local_28 = 5;
  do {
    if ((local_34 < (uint)((*(int *)(iVar2 + 0x5edc) - *(int *)(iVar2 + 0x5ed8)) / 5)) &&
       (puVar4 = (undefined4 *)(*(int *)(iVar2 + 0x5ed8) + local_30), puVar4 != (undefined4 *)0x0))
    {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 2;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      uVar1 = *puVar4;
      local_24 = uVar1;
      FUN_008438c0(&local_24);
      if ((local_20 != DAT_00f8d91c) && (*(int *)(local_20 + 0x10) != 0)) {
        (**(code **)(*(int *)*puVar5 + 0x1ac))
                  (*(undefined4 *)(*(int *)(local_20 + 0x10) + 0x20),uVar1,0,0,
                   *(undefined1 *)(puVar4 + 1));
      }
    }
    else {
      (**(code **)(*(int *)*puVar5 + 0x1ac))(0xffffffff,0xffffffff,0,0,0xffffffff);
    }
    (**(code **)(*(int *)*puVar5 + 200))();
    local_34 = local_34 + iVar3;
    local_30 = local_30 + local_1c;
    puVar5 = puVar5 + 1;
    local_28 = local_28 + -1;
  } while (local_28 != 0);
  ExceptionList = local_14;
  return;
}

