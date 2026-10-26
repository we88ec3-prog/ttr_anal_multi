
void FUN_00513ae0(void)

{
  undefined4 *unaff_ESI;
  
  if (0xf < (uint)unaff_ESI[0xc]) {
    FUN_0089120c(unaff_ESI[7]);
  }
  unaff_ESI[0xc] = 0xf;
  unaff_ESI[0xb] = 0;
  *(undefined1 *)(unaff_ESI + 7) = 0;
  if (7 < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[5] = 7;
  unaff_ESI[4] = 0;
  *(undefined2 *)unaff_ESI = 0;
  return;
}

