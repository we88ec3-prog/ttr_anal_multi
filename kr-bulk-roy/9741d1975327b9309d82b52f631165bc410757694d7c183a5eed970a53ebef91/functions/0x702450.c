
undefined4 FUN_00702450(int param_1)

{
  double *pdVar1;
  int _Y;
  undefined4 extraout_ECX;
  float10 fVar2;
  double dVar3;
  
  _Y = FUN_006f6370();
  fVar2 = (float10)FUN_006f6290(param_1,1,extraout_ECX);
  dVar3 = _ldexp((double)fVar2,_Y);
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = dVar3;
  *(undefined4 *)(pdVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

