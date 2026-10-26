
void FUN_004fdb90(byte param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090d600;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = CTradeMgr::vftable;
  local_8 = 1;
  _eh_vector_destructor_iterator_(in_ECX + 0x181c,0x40,7,FUN_004fdc20);
  local_8 = local_8 & 0xffffff00;
  _eh_vector_destructor_iterator_(in_ECX + 0x17ac,0x40,7,FUN_004fdc20);
  *in_ECX = CPacketProcessor::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

