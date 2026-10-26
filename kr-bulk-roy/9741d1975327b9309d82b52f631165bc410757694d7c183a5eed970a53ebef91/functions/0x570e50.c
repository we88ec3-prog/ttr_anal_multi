
undefined * FUN_00570e50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092732e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe2878 & 1) == 0) {
    DAT_00fe2878 = DAT_00fe2878 | 1;
    local_8 = 0;
    FUN_0052b6c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcf300);
  }
  ExceptionList = local_10;
  return &DAT_00fe287c;
}

