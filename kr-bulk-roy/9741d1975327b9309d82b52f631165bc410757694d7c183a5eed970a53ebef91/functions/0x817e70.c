
void FUN_00817e70(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c195;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00819860(*DAT_00fab280,DAT_00fab280);
  FUN_0089120c(DAT_00fab280,uVar1);
  ExceptionList = local_10;
  return;
}

