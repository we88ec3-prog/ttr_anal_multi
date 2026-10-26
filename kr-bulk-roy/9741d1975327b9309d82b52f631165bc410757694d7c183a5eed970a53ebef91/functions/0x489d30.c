
undefined * FUN_00489d30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908a8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fd8ef8 & 1) == 0) {
    DAT_00fd8ef8 = DAT_00fd8ef8 | 1;
    local_8 = 0;
    FUN_00498280(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcddd0);
  }
  ExceptionList = local_10;
  return &DAT_00fd8efc;
}

