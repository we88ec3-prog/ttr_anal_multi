
undefined * FUN_0048a240(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908a2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1a34 & 1) == 0) {
    DAT_00fc1a34 = DAT_00fc1a34 | 1;
    local_8 = 0;
    FUN_00737210(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce000);
  }
  ExceptionList = local_10;
  return &DAT_00fc1a38;
}

