
void FUN_00652c80(void)

{
  undefined4 *unaff_ESI;
  
  FUN_0075bb00();
  *unaff_ESI = FUI::CBossProgressBar::vftable;
  unaff_ESI[0x37] = 0;
  unaff_ESI[0x38] = 0;
  _memset(unaff_ESI + 0x3a,0,0x40);
  *(undefined1 *)(unaff_ESI + 0x4b) = 0;
  return;
}

