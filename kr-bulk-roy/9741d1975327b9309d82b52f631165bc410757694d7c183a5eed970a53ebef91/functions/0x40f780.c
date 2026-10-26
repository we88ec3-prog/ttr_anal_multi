
undefined * FUN_0040f780(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090defe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  ExceptionList = local_10;
  return &DAT_00fb11ac;
}

