
void FUN_00656560(void)

{
  undefined4 *unaff_ESI;
  
  FUN_00744320();
  *(undefined1 *)(unaff_ESI + 0x29) = 0;
  *(undefined1 *)(unaff_ESI + 0x2a) = 0;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[0x2c] = 0;
  unaff_ESI[0x2d] = 0;
  *unaff_ESI = FUI::CMissionLadderScene::vftable;
  unaff_ESI[0x2e] = 0;
  unaff_ESI[0x2f] = 0;
  unaff_ESI[0x30] = 0;
  unaff_ESI[0x31] = 0;
  unaff_ESI[0x36] = 0;
  unaff_ESI[0x37] = 0;
  unaff_ESI[0x38] = 0;
  unaff_ESI[0x39] = 0;
  _memset(unaff_ESI + 0x3a,0,0x50);
  unaff_ESI[0x4e] = 0xffffffff;
  return;
}

