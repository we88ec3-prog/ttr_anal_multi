
undefined4 FUN_00700900(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] == -1))
  {
    FUN_006f5da0(1);
  }
  piVar3 = *(int **)(param_1 + 0xc);
  piVar2 = *(int **)(param_1 + 8);
  if (piVar2 <= piVar3) {
    piVar3 = &DAT_00c0bfc8;
  }
  iVar4 = piVar3[2];
  if (iVar4 == 5) {
    iVar4 = *(int *)(*piVar3 + 8);
  }
  else if (iVar4 == 7) {
    iVar4 = *(int *)(*piVar3 + 8);
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0x98 + iVar4 * 4);
  }
  if (iVar4 != 0) {
    *piVar2 = iVar4;
    piVar2[2] = 5;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
  piVar2[2] = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

