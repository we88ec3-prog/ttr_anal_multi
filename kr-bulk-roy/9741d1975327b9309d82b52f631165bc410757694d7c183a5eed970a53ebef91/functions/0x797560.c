
void FUN_00797560(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float *in_ECX;
  float *in_EDX;
  
  fVar1 = in_EDX[2];
  fVar2 = in_EDX[1];
  *param_1 = param_2 * (*in_ECX - *in_EDX) + *in_EDX;
  param_1[1] = fVar2 + param_2 * (in_ECX[1] - fVar2);
  param_1[2] = fVar1 + (in_ECX[2] - fVar1) * param_2;
  return;
}

