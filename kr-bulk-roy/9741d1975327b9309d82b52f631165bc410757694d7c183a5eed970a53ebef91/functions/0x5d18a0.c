
void FUN_005d18a0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007451f0();
  *(undefined1 *)(unaff_ESI + 0x20) = 0;
  unaff_ESI[0x21] = 0;
  unaff_ESI[0x29] = 0;
  unaff_ESI[0x2a] = 0;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[0x2c] = 0;
  unaff_ESI[0x2d] = 0;
  unaff_ESI[0x2e] = 0;
  unaff_ESI[0x2f] = 0;
  *unaff_ESI = FUI::CBottomMenuFieldPart::vftable;
  unaff_ESI[0x22] = 0xffffffff;
  unaff_ESI[0x23] = 0xffffffff;
  unaff_ESI[0x24] = 0xffffffff;
  unaff_ESI[0x25] = 0xffffffff;
  unaff_ESI[0x26] = 0xffffffff;
  unaff_ESI[0x27] = 0xffffffff;
  unaff_ESI[0x28] = 0xffffffff;
  unaff_ESI[0x30] = 0;
  unaff_ESI[0x31] = 0;
  unaff_ESI[0x32] = 0;
  unaff_ESI[0x33] = 0;
  unaff_ESI[0x34] = 0;
  return;
}

