
void FUN_00780480(void)

{
  float *unaff_ESI;
  float10 fVar1;
  
  fVar1 = (float10)FUN_004ad080(unaff_ESI[3] * unaff_ESI[3] +
                                unaff_ESI[2] * unaff_ESI[2] +
                                *unaff_ESI * *unaff_ESI + unaff_ESI[1] * unaff_ESI[1]);
  if (fVar1 == (float10)0) {
    unaff_ESI[3] = 1.0;
    *unaff_ESI = 0.0;
    unaff_ESI[2] = 0.0;
    unaff_ESI[1] = 0.0;
    return;
  }
  fVar1 = (float10)1 / fVar1;
  *unaff_ESI = (float)((float10)*unaff_ESI * fVar1);
  unaff_ESI[1] = (float)((float10)unaff_ESI[1] * fVar1);
  unaff_ESI[2] = (float)((float10)unaff_ESI[2] * fVar1);
  unaff_ESI[3] = (float)(fVar1 * (float10)unaff_ESI[3]);
  return;
}

