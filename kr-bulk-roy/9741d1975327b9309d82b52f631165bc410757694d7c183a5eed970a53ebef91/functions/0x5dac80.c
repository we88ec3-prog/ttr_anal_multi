
void FUN_005dac80(int param_1)

{
  uint uVar1;
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
  if (DAT_00f9392c == 4) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    FUN_0050c640(*(undefined4 *)(param_1 + 0x2a0));
  }
  ExceptionList = local_14;
  return;
}

