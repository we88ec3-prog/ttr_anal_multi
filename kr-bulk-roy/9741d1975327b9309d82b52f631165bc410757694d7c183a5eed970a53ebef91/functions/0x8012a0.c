
void FUN_008012a0(void)

{
  float fVar1;
  int iVar2;
  float *unaff_ESI;
  undefined4 *unaff_EDI;
  
  iVar2 = FUN_0089289d();
  unaff_EDI[1] = (((float)iVar2 / 32767.0) * unaff_ESI[2] + *unaff_ESI) - unaff_ESI[2] * 0.5;
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_ESI[3] + unaff_ESI[1]) - unaff_ESI[3] * 0.5;
  unaff_EDI[2] = fVar1;
  if ((float)unaff_EDI[1] != fVar1) {
    *unaff_EDI = 1;
    return;
  }
  *unaff_EDI = 0;
  return;
}

