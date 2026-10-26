
void FUN_00441cb0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3d] = 0;
  unaff_ESI[0x3e] = 0;
  *unaff_ESI = FUI::CRareAvatarComposeWnd::vftable;
  *(undefined1 *)(unaff_ESI + 0x3c) = 1;
  unaff_ESI[0x44] = 0;
  unaff_ESI[0x45] = 0;
  *(undefined1 *)(unaff_ESI + 0x47) = 0;
  unaff_ESI[0x4c] = 0;
  unaff_ESI[0x4d] = 0;
  *(undefined1 *)(unaff_ESI + 0x4f) = 0;
  unaff_ESI[0x40] = 0xffffffff;
  unaff_ESI[0x41] = 0xffffffff;
  unaff_ESI[0x42] = 0xffffffff;
  unaff_ESI[0x43] = 0xffffffff;
  unaff_ESI[0x46] = 0xffffffff;
  unaff_ESI[0x48] = 0xffffffff;
  unaff_ESI[0x49] = 0xffffffff;
  unaff_ESI[0x4a] = 0xffffffff;
  unaff_ESI[0x4b] = 0xffffffff;
  unaff_ESI[0x4e] = 0xffffffff;
  unaff_ESI[0x58] = 0;
  unaff_ESI[0x59] = 0;
  unaff_ESI[0x5a] = 0;
  unaff_ESI[0x5b] = 0;
  unaff_ESI[0x5c] = 0;
  unaff_ESI[0x5d] = 0;
  unaff_ESI[0x5e] = 0;
  unaff_ESI[0x5f] = 0x3f800000;
  *(undefined1 *)(unaff_ESI + 0x60) = 1;
  return;
}

