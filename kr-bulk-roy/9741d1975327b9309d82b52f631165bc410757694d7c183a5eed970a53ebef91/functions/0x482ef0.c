
void FUN_00482ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CShopShapeRestoreItemWnd::vftable;
  if (in_ECX[0x48] != 0) {
    FUN_0089120c(in_ECX[0x48]);
  }
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x4a] = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

