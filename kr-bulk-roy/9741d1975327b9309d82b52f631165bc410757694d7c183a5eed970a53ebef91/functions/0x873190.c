
void FUN_00873190(void)

{
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  FUN_007846f0(unaff_ESI);
  *unaff_ESI = gbLight::vftable;
  unaff_ESI[0x23] = 0x3f800000;
  unaff_ESI[0x24] = 0x3f800000;
  unaff_ESI[0x25] = 0x3f800000;
  unaff_ESI[0x1d] = *(undefined4 *)(unaff_EDI + 0x74);
  unaff_ESI[0x1e] = *(undefined4 *)(unaff_EDI + 0x78);
  unaff_ESI[0x1f] = *(undefined4 *)(unaff_EDI + 0x7c);
  unaff_ESI[0x20] = *(undefined4 *)(unaff_EDI + 0x80);
  unaff_ESI[0x21] = *(undefined4 *)(unaff_EDI + 0x84);
  unaff_ESI[0x22] = *(undefined4 *)(unaff_EDI + 0x88);
  unaff_ESI[0x23] = *(undefined4 *)(unaff_EDI + 0x8c);
  unaff_ESI[0x24] = *(undefined4 *)(unaff_EDI + 0x90);
  unaff_ESI[0x25] = *(undefined4 *)(unaff_EDI + 0x94);
  return;
}

