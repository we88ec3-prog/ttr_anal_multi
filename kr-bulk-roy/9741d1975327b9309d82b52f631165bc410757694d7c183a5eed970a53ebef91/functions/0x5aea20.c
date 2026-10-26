
void FUN_005aea20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CChatablePage::vftable;
  FUN_00595c80();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

