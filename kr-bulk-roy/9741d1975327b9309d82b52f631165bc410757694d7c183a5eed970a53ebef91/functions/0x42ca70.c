
void FUN_0042ca70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CDuelOptionWnd::vftable;
  if (7 < (uint)in_ECX[0x53]) {
    FUN_0089120c(in_ECX[0x4e]);
  }
  in_ECX[0x53] = 7;
  in_ECX[0x52] = 0;
  *(undefined2 *)(in_ECX + 0x4e) = 0;
  *in_ECX = FoxUI::FXUIWindowSimple::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

