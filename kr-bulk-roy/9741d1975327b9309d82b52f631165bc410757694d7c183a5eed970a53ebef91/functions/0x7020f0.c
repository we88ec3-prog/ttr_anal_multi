
undefined4 FUN_007020f0(int param_1)

{
  double *pdVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_006f6290(param_1,1);
  fVar2 = (float10)FUN_00892d30((double)fVar2);
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)fVar2;
  *(undefined4 *)(pdVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

