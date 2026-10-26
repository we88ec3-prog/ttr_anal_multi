
void FUN_006c13b0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_00744320();
  *(undefined1 *)(unaff_ESI + 0x29) = 0;
  unaff_ESI[0x2a] = 0;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[0x2c] = 0;
  unaff_ESI[0x2d] = 0;
  *unaff_ESI = FUI::CCharMenuPopup::vftable;
  unaff_ESI[0x2e] = 0;
  unaff_ESI[0x2f] = 0;
  unaff_ESI[0x30] = 0;
  return;
}

