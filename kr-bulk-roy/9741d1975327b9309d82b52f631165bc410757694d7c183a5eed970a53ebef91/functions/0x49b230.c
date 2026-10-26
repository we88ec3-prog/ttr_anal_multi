
undefined4 * FUN_0049b230(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a5ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8 = 0;
    FUN_006f4380(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce6d0);
  }
  ExceptionList = local_10;
  return &DAT_00fdf3c8;
}

