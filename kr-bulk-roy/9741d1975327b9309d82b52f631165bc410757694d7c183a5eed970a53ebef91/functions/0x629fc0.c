
void FUN_00629fc0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 *local_1c;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a327;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CKeyOptionInsideWnd::vftable;
  local_18 = in_ECX + 0x40;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_00628330(&local_1c,*(undefined4 *)in_ECX[0x41],(undefined4 *)in_ECX[0x41]);
  FUN_0089120c(in_ECX[0x41],uVar1);
  local_1c = in_ECX + 0x3c;
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_005540c0(*(undefined4 *)in_ECX[0x3d],(undefined4 *)in_ECX[0x3d]);
  FUN_0089120c(in_ECX[0x3d]);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

