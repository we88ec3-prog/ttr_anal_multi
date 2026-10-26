
void FUN_00760ec0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911c36;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIPage::vftable;
  local_8 = 2;
  FUN_00761060(in_ECX);
  local_8._0_1_ = 3;
  FUN_005540c0(*(undefined4 *)in_ECX[0x25],(undefined4 *)in_ECX[0x25]);
  FUN_0089120c(in_ECX[0x25],uVar1);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005540c0(*(undefined4 *)in_ECX[0x21],(undefined4 *)in_ECX[0x21]);
  FUN_0089120c(in_ECX[0x21]);
  local_8 = 0xffffffff;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

