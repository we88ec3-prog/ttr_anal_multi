
undefined4 FUN_007095c0(int param_1)

{
  double *pdVar1;
  clock_t cVar2;
  
  cVar2 = _clock();
  pdVar1 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)cVar2 / 1000.0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

