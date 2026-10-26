
undefined4 FUN_00708d20(int param_1)

{
  FILE *_File;
  double *pdVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  long lVar5;
  undefined4 uVar6;
  
  piVar2 = (int *)FUN_006f6140("FILE*");
  if (*piVar2 == 0) {
    FUN_006f5f30(param_1,"attempt to use a closed file");
  }
  _File = (FILE *)*piVar2;
  iVar3 = FUN_006f5fa0(param_1,2);
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
  if (((puVar4 < *(undefined4 **)(param_1 + 8)) && (puVar4 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x28))) {
    lVar5 = FUN_006f6370(param_1,3);
  }
  else {
    lVar5 = 0;
  }
  iVar3 = _fseek(_File,lVar5,*(int *)(&DAT_00c0ba04 + iVar3 * 4));
  if (iVar3 != 0) {
    piVar2 = __errno();
    iVar3 = *piVar2;
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    uVar6 = FUN_00898466(iVar3);
    FUN_006f5580(param_1,&DAT_00bfc638,uVar6);
    pdVar1 = *(double **)(param_1 + 8);
    *pdVar1 = (double)iVar3;
    *(undefined4 *)(pdVar1 + 1) = 3;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 3;
  }
  lVar5 = _ftell(_File);
  pdVar1 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)lVar5;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

