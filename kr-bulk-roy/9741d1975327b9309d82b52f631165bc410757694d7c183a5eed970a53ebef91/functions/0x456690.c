
undefined4 FUN_00456690(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093192e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8 = 0;
    FUN_004d4d10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  local_8 = 0xffffffff;
  FUN_004d7a20();
  ExceptionList = local_10;
  return 0;
}

