
void FUN_00480cd0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  unaff_ESI[0x41] = 0;
  unaff_ESI[0x42] = 0;
  unaff_ESI[0x45] = 0;
  unaff_ESI[0x46] = 0;
  unaff_ESI[0x47] = 0;
  *unaff_ESI = FUI::CShopShapeChangeItemWnd::vftable;
  unaff_ESI[0x49] = 0xffffffff;
  unaff_ESI[0x4a] = 0xffffffff;
  unaff_ESI[0x4b] = 0xffffffff;
  unaff_ESI[0x4c] = 0xffffffff;
  *(undefined1 *)(unaff_ESI + 0x3c) = 1;
  unaff_ESI[0x4d] = 0;
  unaff_ESI[0x4e] = 0x7fffffff;
  unaff_ESI[0x4f] = 0;
  unaff_ESI[0x50] = 0;
  unaff_ESI[0x51] = 0;
  *(undefined1 *)(unaff_ESI + 0x53) = 1;
  return;
}

