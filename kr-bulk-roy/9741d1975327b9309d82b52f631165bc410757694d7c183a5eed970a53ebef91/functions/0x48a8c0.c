
undefined * FUN_0048a8c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009223fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1c80 & 1) == 0) {
    DAT_00fc1c80 = DAT_00fc1c80 | 1;
    local_8 = 0;
    FUN_0056b690(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce500);
  }
  ExceptionList = local_10;
  return &DAT_00fc1c84;
}

