
undefined * FUN_00489bf0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b25e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc18fc & 1) == 0) {
    DAT_00fc18fc = DAT_00fc18fc | 1;
    local_8 = 0;
    FUN_005548f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdcd0);
  }
  ExceptionList = local_10;
  return &DAT_00fc1900;
}

