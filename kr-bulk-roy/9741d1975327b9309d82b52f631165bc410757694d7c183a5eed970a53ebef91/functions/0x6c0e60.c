
void FUN_006c0e60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093aa0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1b14 & 1) == 0) {
    DAT_00fc1b14 = DAT_00fc1b14 | 1;
    local_8 = 0;
    FUN_0055ee90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdf90);
  }
  local_8 = 0xffffffff;
  if (DAT_00fc1b18 != 0) {
    FUN_0055f8a0();
  }
  ExceptionList = local_10;
  return;
}

