
void FUN_00606cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CItemMakingRecipeDlg::vftable;
  if (in_ECX[0x53] != 0) {
    FUN_0049bf30();
    FUN_0089120c(in_ECX[0x53]);
  }
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x55] = 0;
  if (7 < (uint)in_ECX[0x50]) {
    FUN_0089120c(in_ECX[0x4b]);
  }
  in_ECX[0x4f] = 0;
  in_ECX[0x50] = 7;
  *(undefined2 *)(in_ECX + 0x4b) = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  return;
}

