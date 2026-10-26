
void FUN_005ca7c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CFXUIImageSetGroupAutoDestory::vftable;
  FUN_00763c90();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

