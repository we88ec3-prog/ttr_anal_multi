
void FUN_005cc3e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CBottomMenuFrame::vftable;
  if (7 < (uint)in_ECX[0xcb]) {
    FUN_0089120c(in_ECX[0xc6]);
  }
  in_ECX[0xcb] = 7;
  in_ECX[0xca] = 0;
  *(undefined2 *)(in_ECX + 0xc6) = 0;
  if (7 < (uint)in_ECX[0x66]) {
    FUN_0089120c(in_ECX[0x61]);
  }
  in_ECX[0x66] = 7;
  in_ECX[0x65] = 0;
  *(undefined2 *)(in_ECX + 0x61) = 0;
  *in_ECX = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  return;
}

