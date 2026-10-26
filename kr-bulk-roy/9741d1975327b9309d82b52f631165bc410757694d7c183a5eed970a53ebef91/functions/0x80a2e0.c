
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0080a2e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009051ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe33c4 & 1) == 0) {
    DAT_00fe33c4 = DAT_00fe33c4 | 1;
    local_8 = 0;
    FUN_0080e030(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _DAT_00fe33f8 = 0;
    _atexit((_func_4879 *)&LAB_00bd0bd0);
  }
  ExceptionList = local_10;
  return &DAT_00fe33c8;
}

