
undefined4 FUN_00707070(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (*(int **)(param_1 + 8) <= piVar1) {
    piVar1 = &DAT_00c0bfc8;
  }
  if (piVar1[2] == 8) {
    iVar3 = *piVar1;
    if (iVar3 != 0) goto LAB_007070a8;
  }
  else {
    iVar3 = 0;
  }
  FUN_006f5da0(1);
LAB_007070a8:
  if (param_1 == iVar3) {
    iVar3 = 0;
  }
  else if (*(char *)(iVar3 + 6) == '\0') {
    iVar2 = FUN_006f7dd0();
    if (iVar2 < 1) {
      iVar3 = (-(uint)((*(int *)(iVar3 + 8) - *(int *)(iVar3 + 0xc) & 0xfffffff0U) != 0) &
              0xfffffffe) + 3;
    }
    else {
      iVar3 = 2;
    }
  }
  else if (*(char *)(iVar3 + 6) == '\x01') {
    iVar3 = 1;
  }
  else {
    iVar3 = 3;
  }
  FUN_006f5510((&PTR_s_running_00c0bc58)[iVar3]);
  return 1;
}

