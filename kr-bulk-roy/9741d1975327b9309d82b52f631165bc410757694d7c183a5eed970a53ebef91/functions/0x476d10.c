
void FUN_00476d10(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092b35e;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  iVar6 = 0;
  local_20 = 0xffffffff;
  piVar5 = (int *)(param_1 + 0xf4);
  do {
    uVar2 = DAT_00fb9368 & 1;
    iVar1 = *piVar5;
    *(undefined4 *)(iVar1 + 0x29c) = 0;
    *(undefined4 *)(iVar1 + 0x2a0) = 0;
    if (uVar2 == 0) {
      DAT_00fb9368 = DAT_00fb9368 | 1;
      local_c = 0;
      FUN_00822000(uVar4);
      _atexit((_func_4879 *)&LAB_00bcd590);
      local_c = 0xffffffff;
    }
    FUN_008438c0(&local_20);
    if (local_1c == DAT_00fb9374) {
      uVar3 = 0;
    }
    else {
      uVar3 = (undefined2)*(undefined4 *)(local_1c + 0x10);
    }
    *(undefined2 *)(iVar1 + 0x298) = uVar3;
    FUN_005d7240(0xffffffff,0xffffffff,0,0);
    *(int *)(*piVar5 + 0x2a4) = iVar6;
    iVar6 = iVar6 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar6 < 10);
  *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x2a4) = 0xb;
  ExceptionList = local_14;
  return;
}

