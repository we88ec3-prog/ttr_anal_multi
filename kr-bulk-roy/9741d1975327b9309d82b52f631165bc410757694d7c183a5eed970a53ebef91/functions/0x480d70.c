
void FUN_00480d70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CShopShapeChangeItemWnd::vftable;
  if (in_ECX[0x4f] != 0) {
    FUN_0089120c(in_ECX[0x4f]);
  }
  in_ECX[0x4f] = 0;
  in_ECX[0x50] = 0;
  in_ECX[0x51] = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

