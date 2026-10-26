
undefined4 * FUN_00489e70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090665e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1ac0 & 1) == 0) {
    DAT_00fc1ac0 = DAT_00fc1ac0 | 1;
    local_8 = 0;
    FUN_00558100(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdea0);
  }
  ExceptionList = local_10;
  return &DAT_00fc1ac4;
}

