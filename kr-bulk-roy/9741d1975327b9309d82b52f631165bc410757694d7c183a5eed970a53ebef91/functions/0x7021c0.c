
undefined4 FUN_007021c0(int param_1)

{
  double *pdVar1;
  float10 fVar2;
  undefined8 *puVar3;
  undefined8 local_48 [8];
  
  puVar3 = local_48;
  fVar2 = (float10)FUN_006f6290(param_1,1);
  fVar2 = (float10)FUN_008990c0((double)fVar2,puVar3);
  puVar3 = *(undefined8 **)(param_1 + 8);
  *puVar3 = local_48[0];
  *(undefined4 *)(puVar3 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)fVar2;
  *(undefined4 *)(pdVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 2;
}

