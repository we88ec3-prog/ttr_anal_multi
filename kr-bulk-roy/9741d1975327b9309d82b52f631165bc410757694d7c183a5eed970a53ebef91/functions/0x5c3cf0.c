
void FUN_005c3cf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::FXUIChangeTownFailNotOpenedTown::vftable;
  if (in_ECX[6] != 0) {
    FUN_0089120c(in_ECX[6]);
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *in_ECX = FoxUI::FXUIEvent::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

