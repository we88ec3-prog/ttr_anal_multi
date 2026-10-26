
void FUN_0045cdd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CItemEnchantDlg::vftable;
  if (7 < (uint)in_ECX[0x4d]) {
    FUN_0089120c(in_ECX[0x48]);
  }
  in_ECX[0x4d] = 7;
  in_ECX[0x4c] = 0;
  *(undefined2 *)(in_ECX + 0x48) = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  return;
}

