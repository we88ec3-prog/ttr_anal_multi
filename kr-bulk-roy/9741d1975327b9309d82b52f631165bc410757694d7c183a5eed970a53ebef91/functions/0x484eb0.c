
undefined * FUN_00484eb0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f76e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1094 & 1) == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  ExceptionList = local_10;
  return &DAT_00fc1098;
}

