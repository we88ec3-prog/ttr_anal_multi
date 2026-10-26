
undefined * FUN_004452c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090de9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb93b8 & 1) == 0) {
    DAT_00fb93b8 = DAT_00fb93b8 | 1;
    local_8 = 0;
    FUN_00823720(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcd5a0);
  }
  ExceptionList = local_10;
  return &DAT_00fb93bc;
}

