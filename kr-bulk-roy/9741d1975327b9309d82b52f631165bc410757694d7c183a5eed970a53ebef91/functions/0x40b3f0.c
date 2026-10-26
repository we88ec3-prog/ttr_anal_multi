
undefined4 * FUN_0040b3f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917d3e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8 = 0;
    FUN_0080a3a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  ExceptionList = local_10;
  return &DAT_00fab028;
}

