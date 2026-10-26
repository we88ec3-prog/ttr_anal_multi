
undefined4 FUN_004b6a30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009109ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb9390 & 1) == 0) {
    DAT_00fb9390 = DAT_00fb9390 | 1;
    local_8 = 0;
    FUN_0044ad70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd610);
  }
  local_8 = 0xffffffff;
  FUN_0044af80();
  ExceptionList = local_10;
  return 0;
}

