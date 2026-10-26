
void FUN_005ca710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CFXUIImageSetAutoDestroy::vftable;
  FUN_007631f0();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

