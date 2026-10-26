
void FUN_006629b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CUserInfoWnd::vftable;
  if (in_ECX[0x53] != 0) {
    FUN_0089120c(in_ECX[0x53]);
  }
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x55] = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

