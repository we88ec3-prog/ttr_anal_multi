
void FUN_0052b780(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b0d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0052bd50(&DAT_00fe2880,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 1;
  FUN_005540c0(*DAT_00fe2884,DAT_00fe2884);
  FUN_0089120c(DAT_00fe2884);
  ExceptionList = local_10;
  return;
}

