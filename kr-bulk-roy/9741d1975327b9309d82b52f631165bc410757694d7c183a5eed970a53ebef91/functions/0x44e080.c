
void FUN_0044e080(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910d30;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::FXUICachingMgrCmdTarget::vftable;
  local_8 = 1;
  FUN_005540c0(*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  FUN_0089120c(in_ECX[6],uVar1);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIManagerCmdTarget::vftable;
  FUN_00764700();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

