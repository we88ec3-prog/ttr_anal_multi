
void FUN_0079ca60(undefined4 param_1,undefined4 param_2,float param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_2;
  *(float *)(in_ECX + 0x10) = param_3;
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0077f030(param_1,param_2,param_3 + 0.1);
  }
  return;
}

