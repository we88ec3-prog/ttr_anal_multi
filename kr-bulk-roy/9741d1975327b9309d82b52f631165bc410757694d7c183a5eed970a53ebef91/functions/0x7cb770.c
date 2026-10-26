
void FUN_007cb770(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  float *in_EDX;
  float *unaff_ESI;
  
  fVar2 = *in_EDX - *param_1;
  fVar3 = in_EDX[1] - param_1[1];
  fVar4 = in_EDX[2] - param_1[2];
  fVar1 = ((in_EAX[2] - param_1[2]) * fVar4 +
          fVar3 * (in_EAX[1] - param_1[1]) + (*in_EAX - *param_1) * fVar2) /
          (fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2);
  if (0.0 <= fVar1) {
    if (1.0 < fVar1) {
      fVar1 = 1.0;
    }
  }
  else {
    fVar1 = 0.0;
  }
  *unaff_ESI = *param_1 + fVar1 * fVar2;
  unaff_ESI[1] = fVar3 * fVar1 + param_1[1];
  unaff_ESI[2] = param_1[2] + fVar1 * fVar4;
  return;
}

