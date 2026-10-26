
void FUN_00753a50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIEventS1::vftable;
  if (7 < (uint)in_ECX[10]) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[10] = 7;
  in_ECX[9] = 0;
  *(undefined2 *)(in_ECX + 5) = 0;
  *in_ECX = FoxUI::FXUIEvent::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

