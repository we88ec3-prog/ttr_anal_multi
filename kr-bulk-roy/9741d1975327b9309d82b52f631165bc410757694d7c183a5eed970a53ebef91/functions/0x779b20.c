
void FUN_00779b20(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090c6ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIBackground3X::vftable;
  local_8 = 1;
  _eh_vector_destructor_iterator_(in_ECX + 0x33,0x10,3,FUN_005f5d10);
  local_8 = local_8 & 0xffffff00;
  _eh_vector_destructor_iterator_(in_ECX + 3,0x40,3,FUN_00776700);
  *in_ECX = FoxUI::FXUIArchive::vftable;
  ExceptionList = local_10;
  return;
}

