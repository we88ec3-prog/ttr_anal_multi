
void FUN_00775500(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIManagedLine::vftable;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,4,FUN_005f5d10);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

