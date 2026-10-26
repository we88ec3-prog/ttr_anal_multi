
float10 FUN_007cb860(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_ECX;
  float *in_EDX;
  float10 fVar5;
  
  fVar1 = *in_ECX - *param_1;
  fVar2 = in_ECX[1] - param_1[1];
  fVar3 = in_ECX[2] - param_1[2];
  fVar4 = fVar3 * (in_EDX[2] - param_1[2]) +
          fVar2 * (in_EDX[1] - param_1[1]) + fVar1 * (*in_EDX - *param_1);
  if (fVar4 < 0.0) {
    return (float10)-1.0;
  }
  if ((fVar4 <= param_2) &&
     (fVar5 = (float10)((fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3) - (fVar4 * fVar4) / param_2)
     , fVar5 <= (float10)param_3)) {
    return fVar5;
  }
  return (float10)-1.0;
}

