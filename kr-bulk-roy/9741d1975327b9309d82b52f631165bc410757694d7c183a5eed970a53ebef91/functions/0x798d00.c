
undefined * FUN_00798d00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c5fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 0;
    FUN_007cdeb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bd09b0);
  }
  ExceptionList = local_10;
  return &DAT_00fe3250;
}

