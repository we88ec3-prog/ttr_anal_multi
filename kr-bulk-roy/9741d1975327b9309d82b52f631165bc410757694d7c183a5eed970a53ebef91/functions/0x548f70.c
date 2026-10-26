
void FUN_00548f70(byte param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009062e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = CAIControl::vftable;
  local_8 = 0;
  _eh_vector_destructor_iterator_(in_ECX + 4,0x10,3,FUN_00418290);
  *in_ECX = ObsessionsAI::IUserData::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

