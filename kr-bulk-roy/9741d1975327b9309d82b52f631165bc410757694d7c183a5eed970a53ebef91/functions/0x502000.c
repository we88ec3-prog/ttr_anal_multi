
void FUN_00502000(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b403;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  _eh_vector_destructor_iterator_(param_1 + 0x22,0x1c,2,FUN_004fa440);
  if (7 < (uint)param_1[0x1f]) {
    FUN_0089120c(param_1[0x1a],uVar1);
  }
  param_1[0x1f] = 7;
  param_1[0x1e] = 0;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  *param_1 = FlyingObject::CFadeObject::vftable;
  if (0xf < (uint)param_1[0x17]) {
    FUN_0089120c(param_1[0x12],uVar1);
  }
  param_1[0x17] = 0xf;
  param_1[0x16] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *param_1 = FlyingObject::CDefFlyingObject::vftable;
  ExceptionList = local_10;
  return;
}

