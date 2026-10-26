
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00554410(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916cde;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_00fd9248 = 0;
  _DAT_00fd924c = 0;
  DAT_00fd9250 = 0;
  _DAT_00fd9254 = 0;
  if ((DAT_00fe1e1c & 1) == 0) {
    DAT_00fe1e1c = DAT_00fe1e1c | 1;
    local_8 = 0;
    FUN_007c30c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcf1b0);
  }
  local_8 = 0xffffffff;
  DAT_00fd9250 = FUN_007c2b60(0x13);
  ExceptionList = local_10;
  return &DAT_00fd9248;
}

