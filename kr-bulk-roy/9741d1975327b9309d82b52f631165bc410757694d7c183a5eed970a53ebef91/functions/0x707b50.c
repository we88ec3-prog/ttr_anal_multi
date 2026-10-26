
undefined4 FUN_00707b50(int param_1)

{
  int iVar1;
  double *pdVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  puVar3 = (undefined4 *)FUN_006f6140("FILE*");
  iVar4 = __pclose((FILE *)*puVar3);
  *puVar3 = 0;
  piVar5 = __errno();
  iVar1 = *piVar5;
  if (iVar4 != -1) {
    puVar3 = *(undefined4 **)(param_1 + 8);
    *puVar3 = 1;
    puVar3[2] = 1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  uVar6 = FUN_00898466(iVar1);
  FUN_006f5580(param_1,&DAT_00bfc638,uVar6);
  pdVar2 = *(double **)(param_1 + 8);
  *pdVar2 = (double)iVar1;
  *(undefined4 *)(pdVar2 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 3;
}

