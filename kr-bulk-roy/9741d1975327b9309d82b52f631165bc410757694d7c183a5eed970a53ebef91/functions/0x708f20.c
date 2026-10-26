
undefined4 FUN_00708f20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  double *pdVar3;
  FILE *_File;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  _File = (FILE *)FUN_00707ff0(2);
  iVar4 = _fflush(_File);
  piVar5 = __errno();
  iVar1 = *piVar5;
  if (iVar4 == 0) {
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

