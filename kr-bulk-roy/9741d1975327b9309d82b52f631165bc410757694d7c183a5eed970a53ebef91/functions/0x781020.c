
void FUN_00781020(float param_1)

{
  float *unaff_ESI;
  float10 fVar1;
  
  fVar1 = (float10)FUN_004ad080(unaff_ESI[2] * unaff_ESI[2] +
                                *unaff_ESI * *unaff_ESI + unaff_ESI[1] * unaff_ESI[1]);
  if ((float10)0 == fVar1) {
    *unaff_ESI = 1.0;
    unaff_ESI[1] = 0.0;
    unaff_ESI[2] = 0.0;
    return;
  }
  fVar1 = (float10)param_1 / fVar1;
  *unaff_ESI = (float)((float10)*unaff_ESI * fVar1);
  unaff_ESI[1] = (float)((float10)unaff_ESI[1] * fVar1);
  unaff_ESI[2] = (float)(fVar1 * (float10)unaff_ESI[2]);
  return;
}

