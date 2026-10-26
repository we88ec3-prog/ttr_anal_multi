
void FUN_0069bf80(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x20] = 0;
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3c] = 0;
  unaff_ESI[0x3d] = 0x10101;
  *unaff_ESI = FUI::CCashShopInvenWnd::vftable;
  unaff_ESI[0x3e] = 0;
  _memset(unaff_ESI + 0x3f,0,0x3c);
  unaff_ESI[0x4e] = 0;
  unaff_ESI[0x4f] = 0;
  unaff_ESI[0x50] = 0;
  unaff_ESI[0x51] = 0;
  unaff_ESI[0x52] = 0;
  unaff_ESI[0x53] = 0xffffffff;
  return;
}

