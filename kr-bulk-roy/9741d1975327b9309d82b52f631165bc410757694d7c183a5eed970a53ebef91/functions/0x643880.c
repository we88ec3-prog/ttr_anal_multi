
void FUN_00643880(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CEdit::vftable;
  FUN_00761220();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

