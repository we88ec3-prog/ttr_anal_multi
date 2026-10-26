
undefined * FUN_004146b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00925a1e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb1350 & 1) == 0) {
    DAT_00fb1350 = DAT_00fb1350 | 1;
    local_8 = 0;
    FUN_00511ca0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccf40);
  }
  ExceptionList = local_10;
  return &DAT_00fb1354;
}

