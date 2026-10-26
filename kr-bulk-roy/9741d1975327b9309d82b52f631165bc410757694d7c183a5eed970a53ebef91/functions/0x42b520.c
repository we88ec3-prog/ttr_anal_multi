
void FUN_0042b520(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3d] = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  unaff_ESI[0x42] = 0;
  unaff_ESI[0x43] = 0;
  unaff_ESI[0x44] = 0;
  unaff_ESI[0x45] = 0;
  unaff_ESI[0x47] = 0xffffffff;
  unaff_ESI[0x48] = 0xffffffff;
  *(undefined1 *)(unaff_ESI + 0x3c) = 1;
  *unaff_ESI = FUI::CDuelListWnd::vftable;
  unaff_ESI[0x46] = 0;
  return;
}

