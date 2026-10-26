
undefined4 FUN_00702370(int param_1)

{
  double *pdVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_006f6290(param_1,1);
  pdVar1 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)(fVar2 / (float10)0.017453292519943295);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

