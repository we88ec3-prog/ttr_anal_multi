
void FUN_007cd1c0(float *param_1)

{
  float *in_EAX;
  float *in_EDX;
  
  *in_EAX = param_1[6] * in_EDX[2] + *in_EDX * *param_1 + param_1[3] * in_EDX[1] + param_1[9];
  in_EAX[1] = param_1[7] * in_EDX[2] + param_1[4] * in_EDX[1] + param_1[1] * *in_EDX + param_1[10];
  in_EAX[2] = param_1[8] * in_EDX[2] + param_1[5] * in_EDX[1] + param_1[2] * *in_EDX + param_1[0xb];
  return;
}

