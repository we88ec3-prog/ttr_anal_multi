
void FUN_00811cc0(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[10] != 0) {
    FUN_00440a80();
    FUN_0089120c(unaff_ESI[10]);
  }
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  if (0xf < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0xf;
  *(undefined1 *)unaff_ESI = 0;
  return;
}

