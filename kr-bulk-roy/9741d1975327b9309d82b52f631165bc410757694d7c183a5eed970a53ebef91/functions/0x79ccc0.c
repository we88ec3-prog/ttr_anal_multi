
void FUN_0079ccc0(float param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x3c) == 0) {
    param_1 = param_1 * 10.0;
    *(float *)(in_ECX + 0x14) = param_1;
    if (*(int *)(in_ECX + 4) != 0) {
      FUN_0077ef50(param_1,param_1,param_1);
      return;
    }
  }
  else if (*(int *)(in_ECX + 0x3c) == 1) {
    param_1 = param_1 * 6.0;
    *(float *)(in_ECX + 0x14) = param_1;
    if (*(int *)(in_ECX + 4) != 0) {
      FUN_0077ef50(param_1,param_1,param_1);
      return;
    }
  }
  return;
}

