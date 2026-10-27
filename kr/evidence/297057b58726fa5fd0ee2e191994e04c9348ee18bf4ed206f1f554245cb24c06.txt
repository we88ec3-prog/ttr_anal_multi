
void FUN_004ba640(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009065c6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = Scene::CDecisionBase::vftable;
  local_8 = 1;
  _eh_vector_destructor_iterator_(param_1 + 0x17b4,0x38,10,FUN_004ba610);
  if (param_1[0x17b0] != 0) {
    FUN_0089120c(param_1[0x17b0],uVar1);
  }
  param_1[0x17b0] = 0;
  param_1[0x17b1] = 0;
  param_1[0x17b2] = 0;
  *param_1 = CPacketProcessor::vftable;
  ExceptionList = local_10;
  return;
}

