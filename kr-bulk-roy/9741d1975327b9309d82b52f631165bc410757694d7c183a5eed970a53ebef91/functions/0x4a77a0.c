
undefined * FUN_004a77a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092510e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_8 = 0;
    FUN_0050caf0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  ExceptionList = local_10;
  return &DAT_00fe17c0;
}

