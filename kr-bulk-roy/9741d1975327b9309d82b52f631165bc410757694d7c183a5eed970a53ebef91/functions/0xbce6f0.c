
void FUN_00bce6f0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a084a8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00737010(*DAT_00fcde34,DAT_00fcde34);
  FUN_0089120c(DAT_00fcde34,uVar1);
  ExceptionList = local_10;
  return;
}

