
void FUN_007b2c40(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[7] != 0) {
    FUN_007b2be0();
    FUN_0089120c(unaff_ESI[7]);
  }
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  if (0xf < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0xf;
  *(undefined1 *)unaff_ESI = 0;
  return;
}

