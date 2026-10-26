
void FUN_00647340(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CChatTextBox::vftable;
  FUN_004650f0();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

