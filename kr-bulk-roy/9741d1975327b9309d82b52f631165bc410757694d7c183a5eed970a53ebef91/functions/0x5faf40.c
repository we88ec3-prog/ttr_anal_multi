
void FUN_005faf40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CInventoryDialog::vftable;
  if (7 < (uint)in_ECX[0x57]) {
    FUN_0089120c(in_ECX[0x52]);
  }
  in_ECX[0x57] = 7;
  in_ECX[0x56] = 0;
  *(undefined2 *)(in_ECX + 0x52) = 0;
  *in_ECX = FUI::CItemInvenDialog::vftable;
  if (in_ECX[0x41] != 0) {
    FUN_0089120c(in_ECX[0x41]);
  }
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  *in_ECX = FoxUI::FXUIWindowMS::vftable;
  FUN_00756590();
  return;
}

