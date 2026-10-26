
void FUN_00795ee0(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7,float param_8,float param_9,float param_10,
                 float param_11,float param_12,float param_13)

{
  float *in_EAX;
  float *in_ECX;
  
  *in_ECX = param_10 * (param_4 - param_1) + param_11 * (param_7 - param_4);
  in_ECX[1] = (param_5 - param_2) * param_10 + (param_8 - param_5) * param_11;
  in_ECX[2] = (param_6 - param_3) * param_10 + (param_9 - param_6) * param_11;
  *in_EAX = param_12 * (param_4 - param_1) + param_13 * (param_7 - param_4);
  in_EAX[1] = (param_5 - param_2) * param_12 + param_13 * (param_8 - param_5);
  in_EAX[2] = (param_6 - param_3) * param_12 + (param_9 - param_6) * param_13;
  return;
}

