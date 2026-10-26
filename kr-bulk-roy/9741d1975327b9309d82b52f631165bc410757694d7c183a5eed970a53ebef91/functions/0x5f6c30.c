
void FUN_005f6c30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CItemInvenDialog::vftable;
  if (in_ECX[0x41] != 0) {
    FUN_0089120c(in_ECX[0x41]);
  }
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  *in_ECX = FoxUI::FXUIWindowMS::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

