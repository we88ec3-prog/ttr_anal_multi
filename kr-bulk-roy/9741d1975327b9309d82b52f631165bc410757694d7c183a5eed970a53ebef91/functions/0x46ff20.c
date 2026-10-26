
undefined * FUN_0046ff20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910cae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0dd8 & 1) == 0) {
    DAT_00fc0dd8 = DAT_00fc0dd8 | 1;
    local_8 = 0;
    FUN_00484f20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd9f0);
  }
  ExceptionList = local_10;
  return &DAT_00fc0ddc;
}

