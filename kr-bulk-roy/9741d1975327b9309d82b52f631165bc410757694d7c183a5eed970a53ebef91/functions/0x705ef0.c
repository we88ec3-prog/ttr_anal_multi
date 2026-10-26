
undefined4 FUN_00705ef0(int param_1)

{
  double *pdVar1;
  int iVar2;
  
  iVar2 = FUN_006f5ae0(param_1,0);
  pdVar1 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)iVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

