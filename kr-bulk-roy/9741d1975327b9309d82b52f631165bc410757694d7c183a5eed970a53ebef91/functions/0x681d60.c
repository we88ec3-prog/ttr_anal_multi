
void FUN_00681d60(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d0ae;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CShopTradeInsideClient::vftable;
  local_8 = 1;
  FUN_00757640(in_ECX + 0x4a);
  if (in_ECX[0x40] != 0) {
    FUN_0089120c(in_ECX[0x40],uVar1);
  }
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 2;
  FUN_00744370();
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

