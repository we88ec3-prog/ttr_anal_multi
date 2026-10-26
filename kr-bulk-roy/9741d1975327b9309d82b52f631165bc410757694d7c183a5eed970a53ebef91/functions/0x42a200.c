
void FUN_0042a200(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a960;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIButton::vftable;
  local_8 = 0;
  FUN_0077b5f0(in_ECX + 0x2a);
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 1;
  FUN_00744370(uVar1);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

