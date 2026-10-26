
void FUN_0051c1c0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908655;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0051d8f0(*DAT_00f8d91c,DAT_00f8d91c);
  FUN_0089120c(DAT_00f8d91c,uVar1);
  ExceptionList = local_10;
  return;
}

