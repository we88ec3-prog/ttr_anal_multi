
void FUN_0058ca80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::FXUIPositionHistory::vftable;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 0x1c))(1);
    in_ECX[2] = 0;
  }
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

