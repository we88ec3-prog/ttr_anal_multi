
undefined4 FUN_00708fb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  double *pdVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  piVar4 = (int *)FUN_006f6140("FILE*");
  if (*piVar4 == 0) {
    FUN_006f5f30(param_1,"attempt to use a closed file");
  }
  iVar5 = _fflush((FILE *)*piVar4);
  piVar4 = __errno();
  iVar1 = *piVar4;
  if (iVar5 == 0) {
    puVar2 = *(undefined4 **)(param_1 + 8);
    *puVar2 = 1;
    puVar2[2] = 1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  uVar6 = FUN_00898466(iVar1);
  FUN_006f5580(param_1,&DAT_00bfc638,uVar6);
  pdVar3 = *(double **)(param_1 + 8);
  *pdVar3 = (double)iVar1;
  *(undefined4 *)(pdVar3 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 3;
}

