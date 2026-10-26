
void FUN_0077b1a0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c6a8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIBackgroundSingle::vftable;
  local_8 = 0;
  FUN_00776700(uVar1);
  *in_ECX = FoxUI::FXUIArchive::vftable;
  ExceptionList = local_10;
  return;
}

