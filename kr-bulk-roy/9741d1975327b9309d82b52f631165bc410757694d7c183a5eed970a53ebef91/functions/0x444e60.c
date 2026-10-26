
undefined2 * FUN_00444e60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927c3e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_8 = 0;
    FUN_00822000(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  ExceptionList = local_10;
  return &DAT_00fb936c;
}

