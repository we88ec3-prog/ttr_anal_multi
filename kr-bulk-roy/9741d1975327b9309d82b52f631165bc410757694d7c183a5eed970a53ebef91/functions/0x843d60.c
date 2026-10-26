
void FUN_00843d60(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090e2d0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbMaterial::vftable;
  local_8 = 4;
  FUN_00783920(*(undefined4 *)(in_ECX[0x5d] + 4));
  *(undefined4 *)(in_ECX[0x5d] + 4) = in_ECX[0x5d];
  *(undefined4 *)in_ECX[0x5d] = in_ECX[0x5d];
  *(undefined4 *)(in_ECX[0x5d] + 8) = in_ECX[0x5d];
  in_ECX[0x5e] = 0;
  local_8._0_1_ = 5;
  FUN_00844d40(*(undefined4 *)in_ECX[0x5d],(undefined4 *)in_ECX[0x5d]);
  FUN_0089120c(in_ECX[0x5d],uVar1);
  local_8._0_1_ = 2;
  _eh_vector_destructor_iterator_(in_ECX + 0x39,0x10,8,FUN_00843ab0);
  local_8._0_1_ = 1;
  _eh_vector_destructor_iterator_(in_ECX + 0x19,0x10,8,FUN_00843ab0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_00535ac0(*(undefined4 *)in_ECX[0x16],(undefined4 *)in_ECX[0x16]);
  FUN_0089120c(in_ECX[0x16]);
  local_8 = 0xffffffff;
  FUN_00780000();
  ExceptionList = local_10;
  return;
}

