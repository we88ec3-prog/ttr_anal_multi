
undefined * FUN_0041d910(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908b8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb72a4 & 1) == 0) {
    DAT_00fb72a4 = DAT_00fb72a4 | 1;
    local_8 = 0;
    FUN_0049f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccfe0);
  }
  ExceptionList = local_10;
  return &DAT_00fb72a8;
}

