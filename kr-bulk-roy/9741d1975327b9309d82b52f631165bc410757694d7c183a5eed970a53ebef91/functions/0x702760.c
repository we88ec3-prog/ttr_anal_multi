
undefined4 FUN_00702760(int param_1)

{
  double *pdVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  float10 fVar6;
  
  iVar3 = FUN_0089289d();
  pdVar1 = *(double **)(param_1 + 8);
  iVar4 = (int)pdVar1 - *(int *)(param_1 + 0xc) >> 4;
  dVar2 = (double)(iVar3 % 0x7fff) / 32767.0;
  if (iVar4 == 0) {
    *pdVar1 = dVar2;
    *(undefined4 *)(pdVar1 + 1) = 3;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
  if (iVar4 != 1) {
    if (iVar4 != 2) {
      uVar5 = FUN_006f5f30(param_1,"wrong number of arguments");
      return uVar5;
    }
    iVar3 = FUN_006f6370(param_1,1);
    iVar4 = FUN_006f6370(param_1,2);
    if (iVar4 < iVar3) {
      FUN_006f5da0();
    }
    pdVar1 = *(double **)(param_1 + 8);
    fVar6 = (float10)FUN_008ff2e0((double)((iVar4 - iVar3) + 1) * dVar2);
    *(undefined4 *)(pdVar1 + 1) = 3;
    *pdVar1 = (double)(fVar6 + (float10)iVar3);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
  iVar3 = FUN_006f6370(param_1,1);
  if (iVar3 < 1) {
    FUN_006f5da0();
  }
  pdVar1 = *(double **)(param_1 + 8);
  fVar6 = (float10)FUN_008ff2e0((double)iVar3 * dVar2);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)(fVar6 + (float10)1.0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

