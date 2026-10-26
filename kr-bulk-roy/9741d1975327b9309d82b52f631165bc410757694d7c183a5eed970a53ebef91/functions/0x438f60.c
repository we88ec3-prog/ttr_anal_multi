
void FUN_00438f60(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  unaff_ESI[0x3c] = 0;
  unaff_ESI[0x3d] = 0;
  unaff_ESI[0x3e] = 0;
  unaff_ESI[0x3f] = 0;
  unaff_ESI[0x40] = 0;
  unaff_ESI[0x41] = 0;
  unaff_ESI[0x52] = 0;
  unaff_ESI[0x53] = 0;
  unaff_ESI[0x55] = 0;
  unaff_ESI[0x56] = 0;
  unaff_ESI[0x57] = 0;
  unaff_ESI[0x58] = 0;
  *unaff_ESI = FUI::CEternalTowerMyRankingInside::vftable;
  *(undefined2 *)(unaff_ESI + 0x54) = 0;
  return;
}

