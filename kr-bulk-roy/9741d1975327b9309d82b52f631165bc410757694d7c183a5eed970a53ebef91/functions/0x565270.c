
undefined4 FUN_00565270(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00922eee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1bf4 & 1) == 0) {
    DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
    local_8 = 0;
    FUN_0057ef90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdfb0);
  }
  ExceptionList = local_10;
  return DAT_00fc1c6c;
}

