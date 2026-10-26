
void FUN_0087b030(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *in_EAX = in_ECX[8] * param_1[2] + in_ECX[4] * param_1[1] + *in_ECX * *param_1;
  in_EAX[1] = param_1[2] * in_ECX[9] + in_ECX[5] * param_1[1] + in_ECX[1] * *param_1;
  in_EAX[2] = param_1[2] * in_ECX[10] + in_ECX[6] * param_1[1] + in_ECX[2] * *param_1;
  in_EAX[3] = param_1[2] * in_ECX[0xb] + in_ECX[7] * param_1[1] + in_ECX[3] * *param_1;
  in_EAX[4] = in_ECX[8] * param_1[5] + param_1[3] * *in_ECX + param_1[4] * in_ECX[4];
  in_EAX[5] = in_ECX[9] * param_1[5] + in_ECX[1] * param_1[3] + in_ECX[5] * param_1[4];
  in_EAX[6] = in_ECX[10] * param_1[5] + in_ECX[2] * param_1[3] + in_ECX[6] * param_1[4];
  in_EAX[7] = in_ECX[0xb] * param_1[5] + in_ECX[3] * param_1[3] + in_ECX[7] * param_1[4];
  in_EAX[8] = in_ECX[8] * param_1[8] + param_1[6] * *in_ECX + param_1[7] * in_ECX[4];
  in_EAX[9] = in_ECX[9] * param_1[8] + param_1[6] * in_ECX[1] + in_ECX[5] * param_1[7];
  in_EAX[10] = in_ECX[10] * param_1[8] + param_1[6] * in_ECX[2] + in_ECX[6] * param_1[7];
  in_EAX[0xb] = in_ECX[0xb] * param_1[8] + in_ECX[3] * param_1[6] + in_ECX[7] * param_1[7];
  in_EAX[0xc] = in_ECX[8] * param_1[0xb] + param_1[9] * *in_ECX + param_1[10] * in_ECX[4] +
                in_ECX[0xc];
  in_EAX[0xd] = in_ECX[9] * param_1[0xb] + param_1[9] * in_ECX[1] + param_1[10] * in_ECX[5] +
                in_ECX[0xd];
  in_EAX[0xe] = in_ECX[10] * param_1[0xb] + param_1[9] * in_ECX[2] + param_1[10] * in_ECX[6] +
                in_ECX[0xe];
  in_EAX[0xf] = in_ECX[0xb] * param_1[0xb] + param_1[9] * in_ECX[3] + in_ECX[7] * param_1[10] +
                in_ECX[0xf];
  return;
}

