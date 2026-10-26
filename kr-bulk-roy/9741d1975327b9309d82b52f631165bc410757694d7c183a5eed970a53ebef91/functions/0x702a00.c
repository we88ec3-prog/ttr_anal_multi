
undefined4 FUN_00702a00(int param_1)

{
  double *pdVar1;
  
  FUN_006f6210(param_1);
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)param_1;
  *(undefined4 *)(pdVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

