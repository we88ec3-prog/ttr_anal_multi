
void FUN_005944b0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f918;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CKeyDescMgr::vftable;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_004ffa40(*(undefined4 *)in_ECX[0x706],(undefined4 *)in_ECX[0x706]);
  FUN_0089120c(in_ECX[0x706],uVar1);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004ffa40(*(undefined4 *)in_ECX[0x702],(undefined4 *)in_ECX[0x702]);
  FUN_0089120c(in_ECX[0x702]);
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,0x100,FUN_004fa440);
  ExceptionList = local_10;
  return;
}

