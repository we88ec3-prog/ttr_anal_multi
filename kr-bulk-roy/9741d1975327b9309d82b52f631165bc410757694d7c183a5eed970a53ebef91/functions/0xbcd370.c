
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00bcd370(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a07ffa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_00fb7a28 = CAIControl::vftable;
  local_8 = 0;
  _eh_vector_destructor_iterator_(&DAT_00fb7a38,0x10,3,FUN_00418290);
  _DAT_00fb7a28 = ObsessionsAI::IUserData::vftable;
  ExceptionList = local_10;
  return;
}

