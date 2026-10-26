
void FUN_00864810(void)

{
  undefined4 in_ECX;
  int *unaff_ESI;
  
  if (unaff_ESI[8] != 0) {
    FUN_0089120c(unaff_ESI[8]);
  }
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  if (unaff_ESI[4] != 0) {
    FUN_0089120c(unaff_ESI[4]);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  if (*unaff_ESI != 0) {
    FUN_00842540(*unaff_ESI,unaff_ESI[1],in_ECX);
    FUN_0089120c(*unaff_ESI);
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  return;
}

