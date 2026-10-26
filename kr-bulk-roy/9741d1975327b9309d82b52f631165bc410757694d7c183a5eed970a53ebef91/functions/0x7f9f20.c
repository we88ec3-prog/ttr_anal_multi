
void FUN_007f9f20(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    fVar1 = (float)in_ECX[1];
  }
  else {
    fVar1 = (float)in_ECX[2] * param_1 + (1.0 - param_1) * (float)in_ECX[1];
  }
  if (in_ECX[9] == 0) {
    fVar2 = (float)in_ECX[10];
  }
  else {
    fVar2 = (float)in_ECX[0xb] * param_1 + (1.0 - param_1) * (float)in_ECX[10];
  }
  if (in_ECX[6] == 0) {
    fVar3 = (float)in_ECX[7];
  }
  else {
    fVar3 = (float)in_ECX[8] * param_1 + (1.0 - param_1) * (float)in_ECX[7];
  }
  if (in_ECX[3] == 0) {
    fVar4 = (float)in_ECX[4];
  }
  else {
    fVar4 = (1.0 - param_1) * (float)in_ECX[4] + (float)in_ECX[5] * param_1;
  }
  *in_EAX = fVar4;
  in_EAX[1] = fVar3;
  in_EAX[2] = fVar2;
  in_EAX[3] = fVar1;
  return;
}

