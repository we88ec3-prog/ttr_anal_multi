
void FUN_00683200(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00919d7c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CShopTradeWnd::vftable;
  local_8 = 3;
  FUN_0085e680(*(undefined4 *)in_ECX[0x4c],(undefined4 *)in_ECX[0x4c]);
  FUN_0089120c(in_ECX[0x4c],uVar1);
  if (in_ECX[0x47] != 0) {
    FUN_0089120c(in_ECX[0x47],uVar1);
  }
  in_ECX[0x47] = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  if (in_ECX[0x43] != 0) {
    FUN_0089120c(in_ECX[0x43],uVar1);
  }
  in_ECX[0x43] = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

