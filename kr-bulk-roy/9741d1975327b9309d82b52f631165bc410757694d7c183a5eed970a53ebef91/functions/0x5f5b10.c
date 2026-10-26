
void FUN_005f5b10(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = FUI::CBaseInvenInsideWindow::vftable;
  if (unaff_ESI[0x3d] != 0) {
    FUN_0089120c(unaff_ESI[0x3d]);
  }
  unaff_ESI[0x3d] = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  *unaff_ESI = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  return;
}

