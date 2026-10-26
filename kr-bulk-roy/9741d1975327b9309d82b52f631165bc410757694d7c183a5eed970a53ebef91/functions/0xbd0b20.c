
void FUN_00bd0b20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00a084a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007fcb60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_0057ffd0(*DAT_00fe3348,DAT_00fe3348);
  FUN_0089120c(DAT_00fe3348);
  ExceptionList = local_10;
  return;
}

