
void FUN_00848090(void)

{
  int *unaff_ESI;
  
  if (*unaff_ESI != 0) {
    FUN_00848b60();
    FUN_0089120c(*unaff_ESI);
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  return;
}

