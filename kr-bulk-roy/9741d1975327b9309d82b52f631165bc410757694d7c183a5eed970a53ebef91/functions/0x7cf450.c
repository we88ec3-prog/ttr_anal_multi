
void FUN_007cf450(void)

{
  undefined4 *unaff_ESI;
  
  if (0xf < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[5] = 0xf;
  unaff_ESI[4] = 0;
  *(undefined1 *)unaff_ESI = 0;
  return;
}

