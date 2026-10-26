
void FUN_00670390(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CChangeSquareChannelDialog::vftable;
  if (in_ECX[0x3f] != 0) {
    FUN_0089120c(in_ECX[0x3f]);
  }
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

