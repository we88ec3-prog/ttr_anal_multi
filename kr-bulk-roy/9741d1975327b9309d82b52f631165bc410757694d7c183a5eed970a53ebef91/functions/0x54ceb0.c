
undefined4 FUN_0054ceb0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00943dfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0054cf60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  if (*(int *)(DAT_00fb76e8 + 0xa0) == *(int *)(DAT_00fb76e8 + 0xa4)) {
    if (DAT_00fbaaf8 == '\x01') {
      FUN_0054cba0();
    }
    else {
      FUN_0054ba30(0x1f);
    }
  }
  FUN_0054d640(0x3d088889);
  ExceptionList = local_10;
  return 0;
}

