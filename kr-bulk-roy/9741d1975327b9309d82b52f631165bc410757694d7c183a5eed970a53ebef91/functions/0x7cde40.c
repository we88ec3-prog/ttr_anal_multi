
undefined4 * FUN_007cde40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909f2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe3314 & 1) == 0) {
    DAT_00fe3314 = DAT_00fe3314 | 1;
    local_8 = 0;
    FUN_007ed9f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bd0ae0);
  }
  ExceptionList = local_10;
  return &DAT_00fe3318;
}

