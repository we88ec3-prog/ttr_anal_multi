
undefined4 * FUN_00804310(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009074ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe3354 & 1) == 0) {
    DAT_00fe3354 = DAT_00fe3354 | 1;
    local_8 = 0;
    FUN_00807120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bd0b90);
  }
  ExceptionList = local_10;
  return &DAT_00fe3358;
}

