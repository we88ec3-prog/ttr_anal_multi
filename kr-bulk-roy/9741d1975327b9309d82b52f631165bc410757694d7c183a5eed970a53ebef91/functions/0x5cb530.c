
void FUN_005cb530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CIMECompositionType1::vftable;
  if (7 < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 7;
  in_ECX[6] = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  *in_ECX = FoxUI::FXUIIMEComposition::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

