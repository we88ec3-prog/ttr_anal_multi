
undefined4 FUN_0055ed60(float param_1)

{
  float fVar1;
  float fVar2;
  float *in_ECX;
  
  fVar1 = in_ECX[1];
  if (0.0 <= fVar1 - *in_ECX) {
    if (param_1 < 0.0) {
      param_1 = -param_1;
    }
    fVar2 = in_ECX[2];
    in_ECX[2] = fVar2 + param_1;
    if (fVar2 + param_1 < fVar1) {
      return 0;
    }
    fVar2 = in_ECX[3];
  }
  else {
    if (0.0 < param_1) {
      param_1 = -param_1;
    }
    fVar2 = in_ECX[2];
    in_ECX[2] = fVar2 + param_1;
    if (fVar1 < fVar2 + param_1) {
      return 0;
    }
    fVar2 = in_ECX[3];
  }
  if (fVar2 != 0.0) {
    in_ECX[2] = *in_ECX;
    return 1;
  }
  in_ECX[2] = fVar1;
  return 1;
}

