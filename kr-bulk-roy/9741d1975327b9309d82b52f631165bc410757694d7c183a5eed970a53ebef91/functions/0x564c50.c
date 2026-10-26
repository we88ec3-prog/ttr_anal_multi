
undefined4 FUN_00564c50(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a9ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1b14 & 1) == 0) {
    DAT_00fc1b14 = DAT_00fc1b14 | 1;
    local_8 = 0;
    FUN_0055ee90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdf90);
  }
  ExceptionList = local_10;
  return DAT_00fc1b18;
}

