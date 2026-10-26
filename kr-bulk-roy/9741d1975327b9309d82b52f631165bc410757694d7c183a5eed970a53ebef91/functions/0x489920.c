
undefined * FUN_00489920(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009066ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc10cc & 1) == 0) {
    DAT_00fc10cc = DAT_00fc10cc | 1;
    local_8 = 0;
    FUN_00803ff0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdc90);
  }
  ExceptionList = local_10;
  return &DAT_00fc10d0;
}

