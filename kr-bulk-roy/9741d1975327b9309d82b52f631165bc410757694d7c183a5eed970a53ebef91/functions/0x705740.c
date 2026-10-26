
undefined4 FUN_00705740(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] == -1))
  {
    FUN_006f5da0(1);
  }
  piVar4 = *(int **)(param_1 + 0xc);
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 <= piVar4) {
    piVar4 = &DAT_00c0bfc8;
  }
  iVar2 = piVar4[2];
  if (iVar2 == 5) {
    iVar2 = *(int *)(*piVar4 + 8);
  }
  else if (iVar2 == 7) {
    iVar2 = *(int *)(*piVar4 + 8);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x98 + iVar2 * 4);
  }
  if (iVar2 != 0) {
    *piVar3 = iVar2;
    piVar3[2] = 5;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    piVar4 = *(int **)(param_1 + 8);
    piVar3 = *(int **)(param_1 + 0xc);
    if (piVar4 <= piVar3) {
      piVar3 = &DAT_00c0bfc8;
    }
    iVar2 = piVar3[2];
    if (iVar2 == 5) {
      iVar2 = *(int *)(*piVar3 + 8);
    }
    else if (iVar2 == 7) {
      iVar2 = *(int *)(*piVar3 + 8);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x98 + iVar2 * 4);
    }
    if (iVar2 != 0) {
      *piVar4 = iVar2;
      piVar4[2] = 5;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_006f6470();
    }
    return 1;
  }
  piVar3[2] = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

