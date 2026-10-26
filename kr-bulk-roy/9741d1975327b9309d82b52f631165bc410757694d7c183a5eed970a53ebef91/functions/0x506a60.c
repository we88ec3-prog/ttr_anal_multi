
undefined * FUN_00506a60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b3ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1de0 & 1) == 0) {
    DAT_00fe1de0 = DAT_00fe1de0 | 1;
    local_8 = 0;
    FUN_00519060(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcef60);
  }
  ExceptionList = local_10;
  return &DAT_00fe1de4;
}

