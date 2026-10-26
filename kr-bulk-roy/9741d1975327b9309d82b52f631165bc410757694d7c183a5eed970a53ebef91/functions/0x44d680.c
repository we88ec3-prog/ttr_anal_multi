
undefined4 * FUN_0044d680(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091769e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fbacd0 & 1) == 0) {
    DAT_00fbacd0 = DAT_00fbacd0 | 1;
    local_8 = 0;
    DAT_00fbacd4 = 0;
    DAT_00fbacd4 = FUN_006d6300(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd670);
  }
  ExceptionList = local_10;
  return &DAT_00fbacd4;
}

