
void FUN_00744b50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIEventI1S1::vftable;
  if (7 < (uint)in_ECX[0xb]) {
    FUN_0089120c(in_ECX[6]);
  }
  in_ECX[0xb] = 7;
  in_ECX[10] = 0;
  *(undefined2 *)(in_ECX + 6) = 0;
  *in_ECX = FoxUI::FXUIEvent::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

