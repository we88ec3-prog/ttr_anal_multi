
void FUN_005325d0(void)

{
  undefined4 *unaff_ESI;
  
  if (7 < (uint)unaff_ESI[0xf]) {
    FUN_0089120c(unaff_ESI[10]);
  }
  unaff_ESI[0xf] = 7;
  unaff_ESI[0xe] = 0;
  *(undefined2 *)(unaff_ESI + 10) = 0;
  if (7 < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[5] = 7;
  unaff_ESI[4] = 0;
  *(undefined2 *)unaff_ESI = 0;
  return;
}

