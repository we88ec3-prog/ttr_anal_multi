
void FUN_0055f320(void)

{
  undefined4 *unaff_ESI;
  
  unaff_ESI[10] = 0;
  if (unaff_ESI[0x11] != 0) {
    FUN_0089120c(unaff_ESI[0x11]);
    unaff_ESI[0x11] = 0;
  }
  if (7 < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[5] = 7;
  unaff_ESI[4] = 0;
  *(undefined2 *)unaff_ESI = 0;
  FUN_0089120c();
  return;
}

