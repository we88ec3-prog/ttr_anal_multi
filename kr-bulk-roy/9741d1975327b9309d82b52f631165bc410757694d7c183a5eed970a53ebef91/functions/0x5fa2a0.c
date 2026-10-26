
int FUN_005fa2a0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  iVar4 = 0;
  local_1c = 0;
  do {
    iVar1 = iVar4 + -0x4f + *(int *)(in_ECX + 0xf0) * 0x50;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar3);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if (iVar1 - 1U < 0x1e0) {
      iVar2 = DAT_00f94300 + 0x23a0 + iVar1 * 0x18;
      if ((((*(int *)(DAT_00f94300 + 0x23ac + iVar1 * 0x18) != 0) && (*(int *)(iVar2 + 8) != 0)) &&
          (iVar2 != 0)) && (0 < *(int *)(iVar2 + 8))) {
        local_1c = local_1c + 1;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x50);
  ExceptionList = local_14;
  return local_1c;
}

