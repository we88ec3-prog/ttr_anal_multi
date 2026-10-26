
void FUN_00531c60(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090fff8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  _eh_vector_destructor_iterator_(&DAT_00fe1ea8,0x10,4,FUN_00531c00);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00535ac0(*DAT_00fe1e9c,DAT_00fe1e9c);
  FUN_0089120c(DAT_00fe1e9c,uVar1);
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(&DAT_00fe1e48,0x10,5,FUN_00532630);
  ExceptionList = local_10;
  return;
}

