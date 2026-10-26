
undefined4 FUN_007023f0(int param_1)

{
  double *pdVar1;
  float10 fVar2;
  double dVar3;
  int *_Y;
  int local_44 [16];
  
  _Y = local_44;
  fVar2 = (float10)FUN_006f6290(param_1,1);
  dVar3 = _frexp((double)fVar2,_Y);
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = dVar3;
  *(undefined4 *)(pdVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)local_44[0];
  *(undefined4 *)(pdVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 2;
}

