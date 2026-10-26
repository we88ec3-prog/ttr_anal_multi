
void FUN_004d0f10(float *param_1)

{
  int *in_ECX;
  float local_c;
  float local_8;
  
  local_c = (float)in_ECX[0x28] + *param_1;
  local_8 = (float)in_ECX[0x29] + param_1[1];
  (**(code **)(*in_ECX + 0x44))(&local_c,1);
  return;
}

