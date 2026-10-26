
undefined4 FUN_004a2a70(int *param_1)

{
  int *piVar1;
  double *pdVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  pcVar3 = DAT_00fe17a0;
  iVar5 = *param_1;
  iVar4 = *(int *)(iVar5 + 8);
  if (*(int *)(iVar4 + -8) != 4) {
    iVar4 = FUN_006fb5d0();
    if (iVar4 == 0) {
      iVar5 = 0;
      goto LAB_004a2ac3;
    }
    if (*(uint *)(*(int *)(iVar5 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar5 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar4 = *(int *)(iVar5 + 8);
  }
  iVar5 = *(int *)(iVar4 + -0x10) + 0x10;
LAB_004a2ac3:
  iVar4 = (*pcVar3)(iVar5);
  iVar5 = *param_1;
  pdVar2 = *(double **)(iVar5 + 8);
  *pdVar2 = (double)iVar4;
  *(undefined4 *)(pdVar2 + 1) = 3;
  piVar1 = (int *)(iVar5 + 8);
  *piVar1 = *piVar1 + 0x10;
  return 1;
}

