
void FUN_0077e880(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  in_EAX[3] = ((in_ECX[3] * param_1[3] - *in_ECX * *param_1) - in_ECX[1] * param_1[1]) -
              in_ECX[2] * param_1[2];
  *in_EAX = (param_1[2] * in_ECX[1] + in_ECX[3] * *param_1 + param_1[3] * *in_ECX) -
            in_ECX[2] * param_1[1];
  in_EAX[1] = (in_ECX[2] * *param_1 + in_ECX[3] * param_1[1] + param_1[3] * in_ECX[1]) -
              param_1[2] * *in_ECX;
  in_EAX[2] = (*in_ECX * param_1[1] + in_ECX[3] * param_1[2] + param_1[3] * in_ECX[2]) -
              *param_1 * in_ECX[1];
  return;
}

