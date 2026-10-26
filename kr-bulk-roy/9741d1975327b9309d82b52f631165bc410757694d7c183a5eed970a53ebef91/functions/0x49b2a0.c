
undefined4 * FUN_0049b2a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091773e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 0;
    FUN_00736880(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce6f0);
  }
  ExceptionList = local_10;
  return &DAT_00fcde28;
}

