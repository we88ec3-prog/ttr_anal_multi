
undefined4 FUN_007077c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  double *pdVar3;
  int *piVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  piVar4 = __errno();
  iVar1 = *piVar4;
  if (param_1 != 0) {
    puVar2 = *(undefined4 **)(unaff_ESI + 8);
    *puVar2 = 1;
    puVar2[2] = 1;
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    return 1;
  }
  *(undefined4 *)(*(int *)(unaff_ESI + 8) + 8) = 0;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  FUN_00898466(iVar1);
  if (unaff_EDI == 0) {
    FUN_006f5580();
  }
  else {
    FUN_006f5580();
  }
  pdVar3 = *(double **)(unaff_ESI + 8);
  *(undefined4 *)(pdVar3 + 1) = 3;
  *pdVar3 = (double)iVar1;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return 3;
}

