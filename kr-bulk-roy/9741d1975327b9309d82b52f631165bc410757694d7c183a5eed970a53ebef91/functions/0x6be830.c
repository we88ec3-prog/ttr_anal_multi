
void FUN_006be830(void)

{
  undefined4 *unaff_ESI;
  
  FUN_00754880();
  unaff_ESI[0x57] = 0;
  unaff_ESI[0x58] = 0;
  unaff_ESI[0x59] = 0;
  unaff_ESI[0x5a] = 0;
  unaff_ESI[0x5b] = 0;
  unaff_ESI[0x5c] = 0;
  unaff_ESI[0x5e] = 0;
  *(undefined1 *)(unaff_ESI + 0x56) = 1;
  *unaff_ESI = FUI::CBuffSlotToolTip::vftable;
  unaff_ESI[0x5d] = 0xffffffff;
  return;
}

