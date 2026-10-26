
undefined4 FUN_00542f40(int param_1,float *param_2)

{
  float10 fVar1;
  uint local_14;
  int iStack_10;
  
  if (param_1 == 0) {
    return 0;
  }
  FUN_0071baa0(&DAT_00c0f770);
  if (iStack_10 != 0) {
    if (*(int *)(iStack_10 + 8) != 0) {
      fVar1 = (float10)FUN_00898a3f(*(int *)(iStack_10 + 8),0);
      *param_2 = (float)fVar1;
      return 1;
    }
    *param_2 = 0.0;
    return 1;
  }
  *param_2 = (float)(double)(ulonglong)local_14;
  return 1;
}

