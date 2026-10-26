
void FUN_006a1610(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3d] = 0;
  *(undefined1 *)(unaff_ESI + 0x3c) = 1;
  *unaff_ESI = FUI::CPutUpAtAuctionWnd::vftable;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  unaff_ESI[0x41] = 0;
  unaff_ESI[0x42] = 0;
  unaff_ESI[0x43] = 0;
  unaff_ESI[0x44] = 0;
  unaff_ESI[0x45] = 0;
  unaff_ESI[0x47] = 0;
  unaff_ESI[0x48] = 0;
  unaff_ESI[0x49] = 0;
  unaff_ESI[0x4a] = 0;
  unaff_ESI[0x4b] = 0;
  return;
}

