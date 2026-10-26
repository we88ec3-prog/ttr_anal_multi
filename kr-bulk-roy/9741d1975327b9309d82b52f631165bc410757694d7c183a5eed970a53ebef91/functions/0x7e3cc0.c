
void FUN_007e3cc0(void)

{
  int *unaff_ESI;
  
  if (*unaff_ESI != 0) {
    FUN_007e40a0();
    FUN_0089120c(*unaff_ESI);
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  return;
}

