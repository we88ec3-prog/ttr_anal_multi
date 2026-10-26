
undefined * FUN_00474db0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b73e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0dfc & 1) == 0) {
    DAT_00fc0dfc = DAT_00fc0dfc | 1;
    local_8 = 0;
    FUN_008263c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcda40);
  }
  ExceptionList = local_10;
  return &DAT_00fc0e00;
}

