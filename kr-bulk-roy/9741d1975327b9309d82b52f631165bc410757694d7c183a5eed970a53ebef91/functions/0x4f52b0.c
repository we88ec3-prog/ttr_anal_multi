
void FUN_004f52b0(void)

{
  undefined4 *unaff_ESI;
  
  if (0xf < (uint)unaff_ESI[0x13]) {
    FUN_0089120c(unaff_ESI[0xe]);
  }
  unaff_ESI[0x13] = 0xf;
  unaff_ESI[0x12] = 0;
  *(undefined1 *)(unaff_ESI + 0xe) = 0;
  if (7 < (uint)unaff_ESI[0xc]) {
    FUN_0089120c(unaff_ESI[7]);
  }
  unaff_ESI[0xc] = 7;
  unaff_ESI[0xb] = 0;
  *(undefined2 *)(unaff_ESI + 7) = 0;
  if (0xf < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0xf;
  *(undefined1 *)unaff_ESI = 0;
  return;
}

