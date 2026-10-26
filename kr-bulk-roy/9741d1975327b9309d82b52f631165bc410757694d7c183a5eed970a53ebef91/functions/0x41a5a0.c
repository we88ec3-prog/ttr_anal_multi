
void FUN_0041a5a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CCastleMapDialog::vftable;
  if (in_ECX[0x46] != 0) {
    FUN_0089120c(in_ECX[0x46]);
  }
  in_ECX[0x46] = 0;
  in_ECX[0x47] = 0;
  in_ECX[0x48] = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

