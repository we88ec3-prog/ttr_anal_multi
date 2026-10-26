
void FUN_005a70f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CMainPage::vftable;
  FUN_00595c80();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

