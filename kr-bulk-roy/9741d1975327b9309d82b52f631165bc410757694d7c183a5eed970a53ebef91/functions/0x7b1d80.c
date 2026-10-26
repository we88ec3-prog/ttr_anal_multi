
void FUN_007b1d80(void)

{
  int *unaff_ESI;
  
  if (*unaff_ESI != 0) {
    FUN_007b2be0();
    FUN_0089120c(*unaff_ESI);
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  return;
}

