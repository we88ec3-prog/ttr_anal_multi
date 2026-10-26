
float10 FUN_007a8e10(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  
  fVar1 = *(float *)(in_ECX + 0xe0) - *param_1;
  fVar2 = *(float *)(in_ECX + 0xe4) - param_1[1];
  fVar3 = *(float *)(in_ECX + 0xe8) - param_1[2];
  return (float10)(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
}

