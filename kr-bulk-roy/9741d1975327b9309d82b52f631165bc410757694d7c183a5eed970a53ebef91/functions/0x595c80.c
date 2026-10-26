
void FUN_00595c80(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009129ef;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CBasePage::vftable;
  local_8 = 1;
  _eh_vector_destructor_iterator_(in_ECX + 0x30,0x10,3,FUN_00595c10);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004ca160(*(undefined4 *)in_ECX[0x29],(undefined4 *)in_ECX[0x29]);
  FUN_0089120c(in_ECX[0x29],uVar1);
  local_8 = 0xffffffff;
  FUN_00760ec0();
  ExceptionList = local_10;
  return;
}

