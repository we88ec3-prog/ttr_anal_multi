
undefined * FUN_007b8970(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c50e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe32bc & 1) == 0) {
    DAT_00fe32bc = DAT_00fe32bc | 1;
    local_8 = 0;
    FUN_007dda50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bd0ac0);
  }
  ExceptionList = local_10;
  return &DAT_00fe32c0;
}

