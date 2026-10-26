
void FUN_005d4fc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CBottomMenuFrameScenario::vftable;
  FUN_005cc3e0();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

