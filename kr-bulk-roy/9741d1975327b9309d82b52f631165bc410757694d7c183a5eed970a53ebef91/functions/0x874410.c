
void FUN_00874410(void)

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
  if (unaff_ESI[2] != 0) {
    FUN_00891d3d(unaff_ESI[2]);
    unaff_ESI[2] = 0;
  }
  if (unaff_ESI[3] != 0) {
    FUN_00891d3d(unaff_ESI[3]);
    unaff_ESI[3] = 0;
  }
  if (unaff_ESI[4] != 0) {
    FUN_00891d3d(unaff_ESI[4]);
    unaff_ESI[4] = 0;
  }
  return;
}

