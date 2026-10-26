
void FUN_005ff180(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d7d8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CInventoryInsideWindow::vftable;
  local_8 = 0;
  if (7 < (uint)in_ECX[0x5c]) {
    FUN_0089120c(in_ECX[0x57],uVar1);
  }
  in_ECX[0x5c] = 7;
  in_ECX[0x5b] = 0;
  *(undefined2 *)(in_ECX + 0x57) = 0;
  FUN_00757640(in_ECX + 0x45);
  local_8 = 0xffffffff;
  *in_ECX = FUI::CBaseInvenInsideWindow::vftable;
  if (in_ECX[0x3d] != 0) {
    FUN_0089120c(in_ECX[0x3d],uVar1);
  }
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  *in_ECX = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

