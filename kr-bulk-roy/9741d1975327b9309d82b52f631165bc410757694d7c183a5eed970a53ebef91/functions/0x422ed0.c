
undefined * FUN_00422ed0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090db0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8 = 0;
    FUN_005533d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  ExceptionList = local_10;
  return &DAT_00fb7358;
}

