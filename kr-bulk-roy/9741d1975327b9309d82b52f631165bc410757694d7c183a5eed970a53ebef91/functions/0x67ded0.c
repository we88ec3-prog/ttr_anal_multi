
void FUN_0067ded0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00919e06;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CShopStoneEnchantWnd::vftable;
  local_8 = 1;
  _eh_vector_destructor_iterator_(in_ECX + 0x5c,0x58,3,FUN_0067dea0);
  if (7 < (uint)in_ECX[0x51]) {
    FUN_0089120c(in_ECX[0x4c],uVar1);
  }
  in_ECX[0x51] = 7;
  in_ECX[0x50] = 0;
  *(undefined2 *)(in_ECX + 0x4c) = 0;
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

