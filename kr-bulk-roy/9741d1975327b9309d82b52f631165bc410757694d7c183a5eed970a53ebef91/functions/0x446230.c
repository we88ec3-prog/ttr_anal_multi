
undefined4 * FUN_00446230(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927c0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb93cc & 1) == 0) {
    DAT_00fb93cc = DAT_00fb93cc | 1;
    local_8 = 0;
    FUN_00445460(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd620);
  }
  ExceptionList = local_10;
  return &DAT_00fb93d0;
}

