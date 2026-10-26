
void FUN_005d5a30(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919018;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CExpBar::vftable;
  in_ECX[0xf] = 0;
  if (7 < (uint)in_ECX[0x3c]) {
    FUN_0089120c(in_ECX[0x37],uVar1);
  }
  in_ECX[0x3c] = 7;
  in_ECX[0x3b] = 0;
  *(undefined2 *)(in_ECX + 0x37) = 0;
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 0;
  FUN_00744370();
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

