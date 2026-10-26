
undefined4 * FUN_00714260(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a84e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe4c98 & 1) == 0) {
    DAT_00fe4c98 = DAT_00fe4c98 | 1;
    local_8 = 0;
    FUN_007142d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bd0760);
  }
  ExceptionList = local_10;
  return &DAT_00fe4c7c;
}

