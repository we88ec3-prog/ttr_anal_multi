
undefined * FUN_00420830(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917c7e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7324 & 1) == 0) {
    DAT_00fb7324 = DAT_00fb7324 | 1;
    local_8 = 0;
    FUN_0081b920(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd080);
  }
  ExceptionList = local_10;
  return &DAT_00fb7328;
}

