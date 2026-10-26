
void FUN_00626560(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CKeyOptionUIWnd::vftable;
  FUN_00629fc0();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

