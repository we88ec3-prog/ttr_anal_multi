
void FUN_005c73d0(void)

{
  int *unaff_ESI;
  
  if (*unaff_ESI != 0) {
    FUN_005c7ba0(unaff_ESI[1]);
    FUN_0089120c(*unaff_ESI);
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  return;
}

