
void FUN_00693c10(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007451f0();
  unaff_ESI[0x20] = 0;
  unaff_ESI[0x21] = 0;
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x23] = 0;
  unaff_ESI[0x25] = 0;
  unaff_ESI[0x26] = 0;
  unaff_ESI[0x27] = 0;
  unaff_ESI[0x28] = 0;
  unaff_ESI[0x29] = 0;
  unaff_ESI[0x2a] = 0;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[0x2c] = 0;
  unaff_ESI[0x2d] = 0;
  *unaff_ESI = FUI::CPartyListInside::vftable;
  unaff_ESI[0x32] = 0;
  unaff_ESI[0x33] = 7;
  *(undefined2 *)(unaff_ESI + 0x2e) = 0;
  *(undefined1 *)(unaff_ESI + 0x3d) = 0;
  unaff_ESI[0x35] = 0xffffffff;
  unaff_ESI[0x36] = 0xffffffff;
  unaff_ESI[0x37] = 0xffffffff;
  unaff_ESI[0x38] = 0xffffffff;
  unaff_ESI[0x39] = 0xffffffff;
  unaff_ESI[0x3a] = 0xffffffff;
  unaff_ESI[0x3b] = 0xffffffff;
  unaff_ESI[0x3c] = 0xffffffff;
  return;
}

