
void FUN_0076fd40(byte param_1)

{
  undefined4 *in_ECX;
  
  if (7 < (uint)in_ECX[9]) {
    FUN_0089120c(in_ECX[4]);
  }
  in_ECX[9] = 7;
  in_ECX[8] = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  *in_ECX = FoxUI::IFontItemImpl::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

