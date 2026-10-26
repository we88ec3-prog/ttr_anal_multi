
void FUN_00626500(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CKeyOptionDefWnd::vftable;
  FUN_00629fc0();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

