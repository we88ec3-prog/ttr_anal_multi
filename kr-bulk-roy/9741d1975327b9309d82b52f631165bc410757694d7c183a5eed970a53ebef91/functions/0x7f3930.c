
void FUN_007f3930(void)

{
  int *unaff_ESI;
  
  if (*unaff_ESI != 0) {
    FUN_00891d3d(*unaff_ESI);
    *unaff_ESI = 0;
  }
  if (unaff_ESI[1] != 0) {
    FUN_00891d3d(unaff_ESI[1]);
    unaff_ESI[1] = 0;
  }
  FUN_0089120c();
  return;
}

