
void FUN_005f4430(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIStatic::vftable;
  FUN_00754980();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

