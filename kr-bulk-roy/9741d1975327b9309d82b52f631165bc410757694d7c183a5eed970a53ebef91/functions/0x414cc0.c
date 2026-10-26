
void FUN_00414cc0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091370b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CCashShopSell::vftable;
  local_8._0_1_ = 9;
  local_8._1_3_ = 0;
  FUN_005540c0(*(undefined4 *)in_ECX[0x129],(undefined4 *)in_ECX[0x129]);
  FUN_0089120c(in_ECX[0x129],uVar1);
  local_8._0_1_ = 7;
  _eh_vector_destructor_iterator_(in_ECX + 0xe8,0x10,0xf,FUN_00418290);
  local_8._0_1_ = 6;
  _eh_vector_destructor_iterator_(in_ECX + 0xac,0x10,0xf,FUN_00418290);
  local_8 = CONCAT31(local_8._1_3_,5);
  _eh_vector_destructor_iterator_(in_ECX + 0x70,0x10,0xf,FUN_00418290);
  if (in_ECX[0x6c] != 0) {
    FUN_0089120c(in_ECX[0x6c]);
  }
  in_ECX[0x6c] = 0;
  in_ECX[0x6d] = 0;
  in_ECX[0x6e] = 0;
  local_8._0_1_ = 3;
  _eh_vector_destructor_iterator_(in_ECX + 0x50,0x10,6,FUN_00418290);
  local_8._0_1_ = 2;
  _eh_vector_destructor_iterator_(in_ECX + 0x38,0x10,6,FUN_00418290);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_005540c0(*(undefined4 *)in_ECX[0x33],(undefined4 *)in_ECX[0x33]);
  FUN_0089120c(in_ECX[0x33]);
  if (in_ECX[0x2e] != 0) {
    FUN_0089120c(in_ECX[0x2e]);
  }
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIDummy::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

