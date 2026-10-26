
undefined4 * FUN_0048a1d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090662e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fd8ea8 & 1) == 0) {
    DAT_00fd8ea8 = DAT_00fd8ea8 | 1;
    local_8 = 0;
    FUN_0055ac10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdfe0);
  }
  ExceptionList = local_10;
  return &DAT_00fd8eb0;
}

