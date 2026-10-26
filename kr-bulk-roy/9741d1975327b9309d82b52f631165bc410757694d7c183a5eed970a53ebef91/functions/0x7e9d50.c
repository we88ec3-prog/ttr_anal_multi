
void FUN_007e9d50(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_ECX;
  
  fVar1 = in_ECX[0xe];
  in_ECX[0xe] = param_1 + fVar1;
  in_ECX[10] = in_ECX[10] - param_1;
  if ((in_ECX[0xc] < 0.0) || (in_ECX[0xc] < param_1 + fVar1)) {
    fVar1 = *in_ECX + in_ECX[3] * param_1;
    *in_ECX = fVar1;
    fVar2 = in_ECX[1] + in_ECX[4] * param_1;
    in_ECX[1] = fVar2;
    fVar3 = in_ECX[2] + in_ECX[5] * param_1;
    in_ECX[2] = fVar3;
    in_ECX[6] = param_1 * fVar1 + in_ECX[6];
    in_ECX[7] = in_ECX[7] + fVar2 * param_1;
    in_ECX[8] = in_ECX[8] + fVar3 * param_1;
  }
  fVar1 = in_ECX[9] + in_ECX[0xb] * param_1;
  in_ECX[9] = fVar1;
  if (fVar1 < 0.0) {
    in_ECX[9] = 0.0;
  }
  if (0.0 <= in_ECX[10]) {
    return;
  }
  in_ECX[10] = 0.0;
  in_ECX[0xf] = 1.4013e-45;
  return;
}

