
undefined * FUN_00489f40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092242e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fcde44 & 1) == 0) {
    DAT_00fcde44 = DAT_00fcde44 | 1;
    local_8 = 0;
    FUN_0055b8a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcdef0);
  }
  ExceptionList = local_10;
  return &DAT_00fcde48;
}

