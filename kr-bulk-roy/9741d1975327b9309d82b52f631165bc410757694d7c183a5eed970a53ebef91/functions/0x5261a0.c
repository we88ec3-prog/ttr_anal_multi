
void FUN_005261a0(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[7] != 0) {
    FUN_006ab960();
    FUN_0089120c(unaff_ESI[7]);
  }
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  if (7 < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 7;
  *(undefined2 *)unaff_ESI = 0;
  return;
}

