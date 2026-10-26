
undefined4 * FUN_0046f860(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009178de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0d94 & 1) == 0) {
    DAT_00fc0d94 = DAT_00fc0d94 | 1;
    local_8 = 0;
    FUN_0046fa20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcd950);
  }
  ExceptionList = local_10;
  return &DAT_00fc0d98;
}

