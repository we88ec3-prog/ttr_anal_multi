
void FUN_007ff880(float param_1)

{
  int in_ECX;
  
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x1c) = param_1;
  if (param_1 == 0.0) {
    FUN_007be5b0();
  }
  return;
}

