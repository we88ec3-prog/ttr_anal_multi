
void FUN_00440210(void)

{
  undefined4 *unaff_ESI;
  
  if (0xf < (uint)unaff_ESI[0x17]) {
    FUN_0089120c(unaff_ESI[0x12]);
  }
  unaff_ESI[0x17] = 0xf;
  unaff_ESI[0x16] = 0;
  *(undefined1 *)(unaff_ESI + 0x12) = 0;
  if (0xf < (uint)unaff_ESI[0x10]) {
    FUN_0089120c(unaff_ESI[0xb]);
  }
  unaff_ESI[0x10] = 0xf;
  unaff_ESI[0xf] = 0;
  *(undefined1 *)(unaff_ESI + 0xb) = 0;
  *unaff_ESI = CLoginModule::vftable;
  if (0xf < (uint)unaff_ESI[8]) {
    FUN_0089120c(unaff_ESI[3]);
  }
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0xf;
  *(undefined1 *)(unaff_ESI + 3) = 0;
  return;
}

