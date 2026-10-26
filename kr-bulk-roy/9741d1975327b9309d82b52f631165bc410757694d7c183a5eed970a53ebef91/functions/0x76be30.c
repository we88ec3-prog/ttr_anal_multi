
void FUN_0076be30(void)

{
  undefined4 *unaff_ESI;
  
  FUN_00744320();
  unaff_ESI[0x2c] = 0;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[0x2a] = 0;
  unaff_ESI[0x29] = 0;
  unaff_ESI[0x30] = 0;
  unaff_ESI[0x2f] = 0;
  unaff_ESI[0x2e] = 0;
  unaff_ESI[0x2d] = 0;
  unaff_ESI[0x31] = 0;
  unaff_ESI[0x35] = 0;
  unaff_ESI[0x36] = 0;
  unaff_ESI[0x33] = 0;
  unaff_ESI[0x34] = 0;
  *unaff_ESI = FoxUI::
               FXUIListContainer<FoxUI::FXUIListBoxContent,FoxUI::FXUIScrollbar,FoxUI::FXUIContentButton>
               ::vftable;
  *(undefined1 *)(unaff_ESI + 0x32) = 1;
  return;
}

