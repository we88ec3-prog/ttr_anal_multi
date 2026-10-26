
int FUN_00707230(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_1 + 0xc);
  if (*(int **)(param_1 + 8) <= piVar2) {
    piVar2 = &DAT_00c0bfc8;
  }
  if (piVar2[2] == 8) {
    iVar3 = *piVar2;
    if (iVar3 != 0) goto LAB_00707265;
  }
  else {
    iVar3 = 0;
  }
  FUN_006f5da0(1);
LAB_00707265:
  iVar3 = FUN_00707110(param_1,iVar3,(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + -1);
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar1[2] = 1;
  if (iVar3 < 0) {
    *puVar1 = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f52b0();
    return 2;
  }
  *puVar1 = 1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006f52b0();
  return iVar3 + 1;
}

