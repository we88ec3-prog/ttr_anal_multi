
undefined4 * FUN_0040f930(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009459ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  ExceptionList = local_10;
  return &DAT_00fab2a0;
}

