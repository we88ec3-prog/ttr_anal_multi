
void FUN_006b2a30(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007451f0();
  unaff_ESI[0x20] = 0;
  unaff_ESI[0x21] = 0;
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x23] = 0;
  unaff_ESI[0x24] = 0;
  unaff_ESI[0x25] = 0;
  unaff_ESI[0x26] = 0;
  *unaff_ESI = FUI::CMapViewPanel::vftable;
  unaff_ESI[0x27] = 0xffffffff;
  unaff_ESI[0x28] = 0;
  unaff_ESI[0x29] = 0;
  *(undefined1 *)(unaff_ESI + 0x2a) = 1;
  return;
}

