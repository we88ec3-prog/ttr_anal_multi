
undefined4 * FUN_007b89e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909f7e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe3284 & 1) == 0) {
    DAT_00fe3284 = DAT_00fe3284 | 1;
    local_8 = 0;
    FUN_007df1e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bd0ad0);
  }
  ExceptionList = local_10;
  return &DAT_00fe3288;
}

