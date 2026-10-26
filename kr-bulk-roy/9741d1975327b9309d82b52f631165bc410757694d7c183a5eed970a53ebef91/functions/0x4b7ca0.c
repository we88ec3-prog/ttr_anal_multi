
void FUN_004b7ca0(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  pdVar2 = *(double **)(iVar4 + 8);
  *pdVar2 = (double)param_2;
  *(undefined4 *)(pdVar2 + 1) = 3;
  piVar1 = (int *)(iVar4 + 8);
  *piVar1 = *piVar1 + 0x10;
  iVar4 = *param_1;
  iVar3 = *(int *)(iVar4 + 8) + -0x10;
  FUN_006fb850(iVar4,*(int *)(iVar4 + 8) + -0x20,iVar3,iVar3);
  iVar4 = *param_1;
  iVar3 = *(int *)(iVar4 + 8);
  if (*(int *)(iVar3 + -8) != 4) {
    iVar3 = FUN_006fb5d0();
    if (iVar3 == 0) {
      iVar4 = 0;
      goto LAB_004b7d10;
    }
    if (*(uint *)(*(int *)(iVar4 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar4 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar3 = *(int *)(iVar4 + 8);
  }
  iVar4 = *(int *)(iVar3 + -0x10) + 0x10;
LAB_004b7d10:
  *param_3 = iVar4;
  FUN_006f5220();
  return;
}

