
undefined4 FUN_004b6f70(int param_1)

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
  DAT_00fab128 = *(int *)(param_1 + 2) != 0;
  ExceptionList = local_10;
  return 0;
}

