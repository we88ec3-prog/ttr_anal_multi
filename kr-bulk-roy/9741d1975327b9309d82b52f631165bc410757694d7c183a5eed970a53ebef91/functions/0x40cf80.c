
undefined * FUN_0040cf80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091097e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 0;
    FUN_0049d6a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcce20);
  }
  ExceptionList = local_10;
  return &DAT_00fab104;
}

