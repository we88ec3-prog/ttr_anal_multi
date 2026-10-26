
void FUN_00485040(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090dc85;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00485970(*DAT_00fc0de0,DAT_00fc0de0);
  FUN_0089120c(DAT_00fc0de0,uVar1);
  ExceptionList = local_10;
  return;
}

