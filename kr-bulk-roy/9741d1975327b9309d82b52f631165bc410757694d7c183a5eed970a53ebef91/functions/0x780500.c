
void FUN_00780500(void)

{
  float *unaff_ESI;
  float *unaff_EDI;
  float10 fVar1;
  float10 fVar2;
  
  *unaff_ESI = 0.0;
  unaff_ESI[1] = 0.0;
  unaff_ESI[2] = 0.0;
  unaff_ESI[3] = 1.0;
  fVar1 = (float10)FUN_004ad080();
  if ((float10)0 < fVar1) {
    fVar2 = (float10)FUN_008fedca();
    fVar1 = fVar2 / (float10)(double)fVar1;
  }
  *unaff_ESI = (float)((float10)*unaff_EDI * fVar1);
  unaff_ESI[1] = (float)((float10)unaff_EDI[1] * fVar1);
  unaff_ESI[2] = (float)(fVar1 * (float10)unaff_EDI[2]);
  unaff_ESI[3] = 0.0;
  return;
}

