
void FUN_00433b20(byte param_1)

{
  _Locimp *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906753;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)in_ECX = std::locale::_Locimp::vftable;
  local_8 = 1;
  std::locale::_Locimp::_Locimp_dtor(in_ECX);
  if (*(void **)(in_ECX + 0x18) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x18));
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined ***)in_ECX = std::locale::facet::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

