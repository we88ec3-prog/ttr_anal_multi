
undefined4 FUN_004e66b0(int param_1)

{
  float fVar1;
  int in_ECX;
  
  fVar1 = (float)*(int *)(param_1 + 2);
  if (*(int *)(param_1 + 2) < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  *(float *)(in_ECX + 0x6994) = fVar1;
  return 0;
}

