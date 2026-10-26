
void FUN_00649890(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CWorldMapDialog::vftable;
  if (in_ECX[0x45] != 0) {
    FUN_0089120c(in_ECX[0x45]);
  }
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
  in_ECX[0x47] = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

