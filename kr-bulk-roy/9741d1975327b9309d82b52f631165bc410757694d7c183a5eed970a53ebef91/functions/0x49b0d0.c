
undefined4 * FUN_0049b0d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091776e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fd93f0 & 1) == 0) {
    DAT_00fd93f0 = DAT_00fd93f0 | 1;
    local_8 = 0;
    FUN_007ab4e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce6a0);
  }
  ExceptionList = local_10;
  return &DAT_00fd92a0;
}

