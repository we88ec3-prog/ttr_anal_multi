
undefined4 FUN_00708e20(int param_1)

{
  FILE *_File;
  double *pdVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  size_t _Size;
  int iVar5;
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
    _Size = FUN_006f6370(param_1,3);
  }
  else {
    _Size = 0x200;
  }
  iVar5 = _setvbuf(_File,(char *)0x0,*(int *)(&DAT_00c0ba88 + iVar3 * 4),_Size);
  piVar2 = __errno();
  iVar3 = *piVar2;
  if (iVar5 == 0) {
    puVar4 = *(undefined4 **)(param_1 + 8);
    *puVar4 = 1;
    puVar4[2] = 1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
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

