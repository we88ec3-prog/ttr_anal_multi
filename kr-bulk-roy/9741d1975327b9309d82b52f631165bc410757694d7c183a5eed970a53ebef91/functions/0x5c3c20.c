
void FUN_005c3c20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::FXUICashShopCartOpen::vftable;
  if (in_ECX[5] != 0) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = FoxUI::FXUIEvent::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

