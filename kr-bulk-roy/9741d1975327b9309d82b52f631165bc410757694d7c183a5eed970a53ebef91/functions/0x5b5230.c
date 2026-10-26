
void FUN_005b5230(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091adc0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CLobbyPage::vftable;
  local_8 = 1;
  FUN_005540c0(*(undefined4 *)in_ECX[0xbb],(undefined4 *)in_ECX[0xbb]);
  FUN_0089120c(in_ECX[0xbb],uVar1);
  local_8 = 0xffffffff;
  *in_ECX = FUI::CChatablePage::vftable;
  FUN_00595c80();
  ExceptionList = local_10;
  return;
}

