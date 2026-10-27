
void FUN_005b2670(void)

{
  undefined4 *unaff_ESI;
  
  FUN_005b5020(unaff_ESI);
  unaff_ESI[0xbe] = 0;
  unaff_ESI[0xbf] = 0;
  unaff_ESI[0xc0] = 0;
  unaff_ESI[0xc1] = 0;
  unaff_ESI[0xc2] = 0;
  unaff_ESI[0xc3] = 0;
  unaff_ESI[0xc4] = 0;
  unaff_ESI[0xc5] = 0;
  unaff_ESI[199] = 0;
  *unaff_ESI = FUI::CSquarePage::vftable;
  return;
}

