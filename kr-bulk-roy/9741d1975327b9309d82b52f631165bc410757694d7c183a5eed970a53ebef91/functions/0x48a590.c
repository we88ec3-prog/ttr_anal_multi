
undefined * FUN_0048a590(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009253ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fdf3ec & 1) == 0) {
    DAT_00fdf3ec = DAT_00fdf3ec | 1;
    local_8 = 0;
    FUN_006d1da0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce330);
  }
  ExceptionList = local_10;
  return &DAT_00fdf3f0;
}

