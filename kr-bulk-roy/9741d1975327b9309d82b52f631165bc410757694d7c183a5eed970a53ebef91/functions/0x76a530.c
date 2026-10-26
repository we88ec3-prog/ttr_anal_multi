
void FUN_0076a530(void)

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
  *in_ECX = FoxUI::FXUIWindowClientBtnBase::vftable;
  local_8 = 0;
  if ((int *)in_ECX[0x35] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x35] + 0x10))(1,uVar1);
    in_ECX[0x35] = 0;
  }
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 1;
  FUN_00744370();
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

