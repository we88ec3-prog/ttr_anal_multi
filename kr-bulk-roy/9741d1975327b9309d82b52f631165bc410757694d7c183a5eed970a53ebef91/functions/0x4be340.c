
undefined4 * FUN_004be340(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924e13;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1aa8 & 1) == 0) {
    DAT_00fe1aa8 = DAT_00fe1aa8 | 1;
    DAT_00fe1aac = 0;
    DAT_00fe1ab0 = 0;
    DAT_00fe1ab4 = 0;
    local_8 = 1;
    FUN_004fcff0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcea20);
  }
  ExceptionList = local_10;
  return &DAT_00fe1aac;
}

