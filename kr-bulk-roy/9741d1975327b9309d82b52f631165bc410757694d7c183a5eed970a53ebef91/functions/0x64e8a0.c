
undefined4 FUN_0064e8a0(void)

{
  uint uVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d77c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (DAT_00f9392c != 1) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (DAT_00f9392c != 2) {
      iVar2 = FUN_00404ba0();
      if (*(int *)(iVar2 + 0x5f4c) != 6) {
        ExceptionList = local_14;
        return 1;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

