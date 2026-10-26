
undefined * FUN_0043ffa0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092127e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8 = 0;
    FUN_00734ef0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  ExceptionList = local_10;
  return &DAT_00fb7b70;
}

