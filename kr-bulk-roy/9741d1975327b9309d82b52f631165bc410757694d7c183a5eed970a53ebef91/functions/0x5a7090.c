
void FUN_005a7090(void)

{
  undefined4 *unaff_ESI;
  
  FUN_00595a60(unaff_ESI);
  unaff_ESI[0x4e] = 0;
  unaff_ESI[0x4f] = 0;
  unaff_ESI[0x50] = 0;
  unaff_ESI[0x51] = 0;
  unaff_ESI[0x52] = 0;
  unaff_ESI[0x53] = 0;
  unaff_ESI[0x54] = 0;
  unaff_ESI[0x55] = 0;
  unaff_ESI[0x56] = 0;
  unaff_ESI[0x57] = 0;
  unaff_ESI[0x58] = 0;
  unaff_ESI[0x59] = 0;
  unaff_ESI[0x4d] = 0;
  *unaff_ESI = FUI::CMainPage::vftable;
  return;
}

