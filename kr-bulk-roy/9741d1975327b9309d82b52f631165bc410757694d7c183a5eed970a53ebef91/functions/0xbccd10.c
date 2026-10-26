
void FUN_00bccd10(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a08462;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00faafd8 = FUI::FXUICachingMgrCmdTarget::vftable;
  local_8 = 1;
  FUN_005540c0(*DAT_00faaff0,DAT_00faaff0);
  FUN_0089120c(DAT_00faaff0,uVar1);
  local_8 = 0xffffffff;
  DAT_00faafd8 = FoxUI::FXUIManagerCmdTarget::vftable;
  FUN_00764700();
  ExceptionList = local_10;
  return;
}

