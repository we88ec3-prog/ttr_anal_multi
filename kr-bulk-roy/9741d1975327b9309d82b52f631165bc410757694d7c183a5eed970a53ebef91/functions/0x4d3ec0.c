
void FUN_004d3ec0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d84e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  if (in_ECX[0x7e] != 0) {
    FUN_0089120c(in_ECX[0x7e],uVar1);
  }
  in_ECX[0x7e] = 0;
  in_ECX[0x7f] = 0;
  in_ECX[0x80] = 0;
  FUN_00825ed0(in_ECX + 0x75);
  local_8 = CONCAT31(local_8._1_3_,1);
  _eh_vector_destructor_iterator_(in_ECX + 0x44,0x1c,7,FUN_00418290);
  if (in_ECX[0x3f] != 0) {
    FUN_0089120c(in_ECX[0x3f],uVar1);
  }
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  *in_ECX = CBaseCharStatus::vftable;
  ExceptionList = local_10;
  return;
}

