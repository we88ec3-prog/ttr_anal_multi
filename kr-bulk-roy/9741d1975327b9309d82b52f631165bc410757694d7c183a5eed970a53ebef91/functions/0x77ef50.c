
void FUN_0077ef50(float param_1,float param_2,float param_3)

{
  int in_ECX;
  
  if (((param_1 == *(float *)(in_ECX + 0x84)) && (param_2 == *(float *)(in_ECX + 0x88))) &&
     (param_3 == *(float *)(in_ECX + 0x8c))) {
    return;
  }
  *(undefined4 *)(in_ECX + 0xc0) = 0;
  *(float *)(in_ECX + 0x84) = param_1;
  *(float *)(in_ECX + 0x88) = param_2;
  *(float *)(in_ECX + 0x8c) = param_3;
  return;
}

