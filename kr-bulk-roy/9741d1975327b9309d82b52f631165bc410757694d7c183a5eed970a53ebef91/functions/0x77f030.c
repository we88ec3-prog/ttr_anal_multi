
void FUN_0077f030(float param_1,float param_2,float param_3)

{
  int in_ECX;
  
  if (((param_1 == *(float *)(in_ECX + 0x68)) && (param_2 == *(float *)(in_ECX + 0x6c))) &&
     (param_3 == *(float *)(in_ECX + 0x70))) {
    return;
  }
  *(undefined4 *)(in_ECX + 0xc0) = 0;
  *(float *)(in_ECX + 0x68) = param_1;
  *(float *)(in_ECX + 0x6c) = param_2;
  *(float *)(in_ECX + 0x70) = param_3;
  return;
}

