
void FUN_007e8840(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[0xf] != 0) {
    FUN_0089120c(unaff_ESI[0xf]);
  }
  unaff_ESI[0xf] = 0;
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x11] = 0;
  if (0xf < (uint)unaff_ESI[0xd]) {
    FUN_0089120c(unaff_ESI[8]);
  }
  unaff_ESI[0xd] = 0xf;
  unaff_ESI[0xc] = 0;
  *(undefined1 *)(unaff_ESI + 8) = 0;
  if (0xf < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0xf;
  *(undefined1 *)unaff_ESI = 0;
  return;
}

