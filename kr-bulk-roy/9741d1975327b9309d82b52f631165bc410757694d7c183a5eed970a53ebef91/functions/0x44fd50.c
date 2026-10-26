
undefined4 * FUN_0044fd50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b73e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  ExceptionList = local_10;
  return &DAT_00fbad18;
}

