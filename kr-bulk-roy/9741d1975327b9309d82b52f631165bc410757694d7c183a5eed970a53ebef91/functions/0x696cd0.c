
void FUN_00696cd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CPartyTitlePanel::vftable;
  if (7 < (uint)in_ECX[0x42]) {
    FUN_0089120c(in_ECX[0x3d]);
  }
  in_ECX[0x42] = 7;
  in_ECX[0x41] = 0;
  *(undefined2 *)(in_ECX + 0x3d) = 0;
  *in_ECX = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  return;
}

