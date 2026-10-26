
void FUN_005e16e0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_00754880();
  unaff_ESI[0x57] = 0;
  unaff_ESI[0x5d] = 0;
  *(undefined2 *)(unaff_ESI + 0x5e) = 0;
  unaff_ESI[0x5f] = 0;
  unaff_ESI[0x60] = 0;
  unaff_ESI[0x61] = 0;
  unaff_ESI[0x62] = 0;
  unaff_ESI[99] = 0;
  unaff_ESI[100] = 0;
  unaff_ESI[0x65] = 0;
  unaff_ESI[0x66] = 0;
  *(undefined1 *)(unaff_ESI + 0x67) = 0;
  unaff_ESI[0x68] = 0;
  unaff_ESI[0x69] = 0;
  unaff_ESI[0x6a] = 0;
  unaff_ESI[0x6b] = 0;
  *(undefined1 *)(unaff_ESI + 0x56) = 1;
  *unaff_ESI = FUI::CItemSlotSingleToolTip::vftable;
  unaff_ESI[0x58] = 0xffffffff;
  unaff_ESI[0x59] = 0xffffffff;
  return;
}

