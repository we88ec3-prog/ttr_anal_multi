
void FUN_004761d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CBaseInvenInsideWindow::vftable;
  if (in_ECX[0x3d] != 0) {
    FUN_0089120c(in_ECX[0x3d]);
  }
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  *in_ECX = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

