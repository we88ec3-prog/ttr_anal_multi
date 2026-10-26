
void FUN_006a4790(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091cf10;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CGuildWnd::vftable;
  local_8 = 1;
  FUN_005540c0(*(undefined4 *)in_ECX[0x44],(undefined4 *)in_ECX[0x44]);
  FUN_0089120c(in_ECX[0x44],uVar1);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowMS::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

