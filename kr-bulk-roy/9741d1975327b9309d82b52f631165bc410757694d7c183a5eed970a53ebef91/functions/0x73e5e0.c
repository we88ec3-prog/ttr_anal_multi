
void FUN_0073e5e0(void)

{
  undefined4 *unaff_ESI;
  
  if (7 < (uint)unaff_ESI[0x1b]) {
    FUN_0089120c(unaff_ESI[0x16]);
  }
  unaff_ESI[0x1b] = 7;
  unaff_ESI[0x1a] = 0;
  *(undefined2 *)(unaff_ESI + 0x16) = 0;
  if (7 < (uint)unaff_ESI[0x14]) {
    FUN_0089120c(unaff_ESI[0xf]);
  }
  unaff_ESI[0x14] = 7;
  unaff_ESI[0x13] = 0;
  *(undefined2 *)(unaff_ESI + 0xf) = 0;
  if (7 < (uint)unaff_ESI[0xd]) {
    FUN_0089120c(unaff_ESI[8]);
  }
  unaff_ESI[0xd] = 7;
  unaff_ESI[0xc] = 0;
  *(undefined2 *)(unaff_ESI + 8) = 0;
  if (7 < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 7;
  *(undefined2 *)unaff_ESI = 0;
  return;
}

