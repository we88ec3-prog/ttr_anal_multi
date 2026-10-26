
float10 FUN_00791180(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  float *unaff_ESI;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004ad080(unaff_ESI[2] * unaff_ESI[2] +
                                *unaff_ESI * *unaff_ESI + unaff_ESI[1] * unaff_ESI[1]);
  if ((float10)(double)CONCAT44(param_2,param_1) < fVar2) {
    fVar1 = (float)((float10)1 / fVar2);
    *unaff_ESI = fVar1 * *unaff_ESI;
    unaff_ESI[1] = fVar1 * unaff_ESI[1];
    unaff_ESI[2] = fVar1 * unaff_ESI[2];
    return fVar2;
  }
  return (float10)0;
}

