
void FUN_008cdf80(void)

{
  undefined4 *unaff_ESI;
  
  FUN_008b9f80();
  unaff_ESI[6] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[7] = 0;
  FUN_008b9f80();
  unaff_ESI[3] = 0;
  FUN_008b9f80();
  unaff_ESI[2] = 0;
  unaff_ESI[1] = 0;
  *unaff_ESI = 0;
  unaff_ESI[4] = 0;
  return;
}

