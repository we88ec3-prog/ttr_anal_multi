
void FUN_006b5240(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint local_3c;
  uint *local_38;
  uint *local_34;
  uint *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  puStack_10 = &LAB_0093c03e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  puVar4 = (uint *)0x0;
  puVar5 = (uint *)0x0;
  local_38 = (uint *)0x0;
  local_34 = (uint *)0x0;
  local_30 = (uint *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_c = 1;
  uStack_b = 0;
  local_3c = 0;
  do {
    uVar1 = local_3c;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 2;
      FUN_004e1590(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 1;
    }
    if ((((uVar1 < 10) && (iVar3 = uVar1 * 0x210 + DAT_00f94304, *(int *)(iVar3 + 0x5c) != 0)) &&
        (iVar3 != 0)) && (*(int *)(iVar3 + 0x5c) != 0)) {
      if ((&local_3c < puVar4) && (puVar5 <= &local_3c)) {
        iVar3 = (int)&local_3c - (int)local_38;
        if (puVar4 == local_30) {
          FUN_006d6240();
          puVar4 = local_34;
        }
        puVar5 = local_38;
        if (puVar4 != (uint *)0x0) {
          *puVar4 = local_38[iVar3 >> 2];
        }
      }
      else {
        if (puVar4 == local_30) {
          FUN_006d6240();
          puVar4 = local_34;
          puVar5 = local_38;
        }
        if (puVar4 != (uint *)0x0) {
          *puVar4 = uVar1;
        }
      }
      puVar4 = puVar4 + 1;
      local_34 = puVar4;
    }
    local_3c = uVar1 + 1;
  } while ((int)local_3c < 10);
  iVar3 = (int)puVar4 - (int)puVar5 >> 2;
  if (2 < iVar3) {
    iVar3 = 3;
  }
  if (puVar5 != puVar4) {
    FUN_0046dff0(puVar5,puVar4);
  }
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  iVar6 = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  *(undefined1 *)(param_1 + 0x1e0) = 0;
  if (0 < iVar3) {
    do {
      FUN_006b56e0();
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar3);
  }
  if (local_38 != (uint *)0x0) {
    FUN_0089120c(local_38);
  }
  ExceptionList = local_14;
  return;
}

