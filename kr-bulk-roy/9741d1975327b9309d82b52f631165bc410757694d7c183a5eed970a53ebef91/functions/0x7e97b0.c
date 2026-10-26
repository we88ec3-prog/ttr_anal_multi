
undefined4 FUN_007e97b0(float param_1,float param_2)

{
  int in_ECX;
  
  if ((((*(float *)(in_ECX + 8) <= param_2) && (param_2 <= *(float *)(in_ECX + 0x10))) &&
      (*(float *)(in_ECX + 4) <= param_1)) && (param_1 <= *(float *)(in_ECX + 0xc))) {
    return 1;
  }
  return 0;
}

