
undefined4 * FUN_0041e5c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009259c3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb72e8 & 1) == 0) {
    DAT_00fb72e8 = DAT_00fb72e8 | 1;
    DAT_00fb72ec = 0;
    DAT_00fb72f0 = 0;
    DAT_00fb72f4 = 0;
    local_8 = 1;
    FUN_0049ef70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bccff0);
  }
  ExceptionList = local_10;
  return &DAT_00fb72ec;
}

