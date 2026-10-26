
void FUN_00bce150(void)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00a0832e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fc1cc0 = CTradeMgr::vftable;
  local_8 = 1;
  _eh_vector_destructor_iterator_(&DAT_00fc7d30,0x40,7,FUN_004fdc20);
  local_8 = local_8 & 0xffffff00;
  _eh_vector_destructor_iterator_(&DAT_00fc7b70,0x40,7,FUN_004fdc20);
  DAT_00fc1cc0 = CPacketProcessor::vftable;
  ExceptionList = local_10;
  return;
}

