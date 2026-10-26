
undefined * FUN_0048a850(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090dc2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1710 & 1) == 0) {
    DAT_00fc1710 = DAT_00fc1710 | 1;
    local_8 = 0;
    FUN_0082a2a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce440);
  }
  ExceptionList = local_10;
  return &DAT_00fc1714;
}

