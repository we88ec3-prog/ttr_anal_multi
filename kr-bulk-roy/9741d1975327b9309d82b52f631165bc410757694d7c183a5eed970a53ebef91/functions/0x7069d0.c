
int FUN_007069d0(int param_1)

{
  int *piVar1;
  double *pdVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  piVar1 = *(int **)(param_1 + 8);
  piVar3 = *(int **)(param_1 + 0xc);
  iVar6 = (int)piVar1 - (int)piVar3 >> 4;
  if (((piVar1 <= piVar3) || (piVar3 == &DAT_00c0bfc8)) || (piVar3[2] != 4)) goto LAB_00706a6b;
  if (piVar1 <= piVar3) {
    piVar3 = &DAT_00c0bfc8;
  }
  if (piVar3[2] == 4) {
LAB_00706a3e:
    pcVar5 = (char *)(*piVar3 + 0x10);
  }
  else {
    iVar4 = FUN_006fb5d0();
    if (iVar4 != 0) {
      if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44))
      {
        FUN_006fb3a0();
      }
      piVar3 = *(int **)(param_1 + 0xc);
      if (*(int **)(param_1 + 8) <= piVar3) {
        piVar3 = &DAT_00c0bfc8;
      }
      goto LAB_00706a3e;
    }
    pcVar5 = (char *)0x0;
  }
  if (*pcVar5 == '#') {
    pdVar2 = *(double **)(param_1 + 8);
    *(undefined4 *)(pdVar2 + 1) = 3;
    *pdVar2 = (double)(iVar6 + -1);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
LAB_00706a6b:
  param_1 = FUN_006f6370(param_1,1);
  if (param_1 < 0) {
    param_1 = param_1 + iVar6;
  }
  else if (iVar6 < param_1) {
    param_1 = iVar6;
  }
  if (param_1 < 1) {
    FUN_006f5da0(1);
  }
  return iVar6 - param_1;
}

