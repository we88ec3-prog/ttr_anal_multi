
void FUN_0072dc10(void)

{
  undefined4 *unaff_ESI;
  
  if (0xf < (uint)unaff_ESI[0x11]) {
    FUN_0089120c(unaff_ESI[0xc]);
  }
  unaff_ESI[0x11] = 0xf;
  unaff_ESI[0x10] = 0;
  *(undefined1 *)(unaff_ESI + 0xc) = 0;
  if (0xf < (uint)unaff_ESI[10]) {
    FUN_0089120c(unaff_ESI[5]);
  }
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0xf;
  *(undefined1 *)(unaff_ESI + 5) = 0;
  *unaff_ESI = TiXmlBase::vftable;
  return;
}

