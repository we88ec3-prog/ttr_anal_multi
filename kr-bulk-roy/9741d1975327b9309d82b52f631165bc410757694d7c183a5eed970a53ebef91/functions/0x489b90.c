
undefined * FUN_00489b90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092245e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fdf6f4 & 1) == 0) {
    DAT_00fdf6f4 = DAT_00fdf6f4 | 1;
    local_8 = 0;
    FUN_0049b490(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  }
  ExceptionList = local_10;
  return &DAT_00fdf6f8;
}

