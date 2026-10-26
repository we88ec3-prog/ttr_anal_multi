
undefined4 * FUN_0055c5a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009389de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1ee8 & 1) == 0) {
    DAT_00fe1ee8 = DAT_00fe1ee8 | 1;
    local_8 = 0;
    FUN_0055c610(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcf290);
  }
  ExceptionList = local_10;
  return &DAT_00fe1eec;
}

