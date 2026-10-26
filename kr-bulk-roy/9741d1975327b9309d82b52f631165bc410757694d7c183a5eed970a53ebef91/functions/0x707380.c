
undefined4 FUN_00707380(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  iVar3 = FUN_006f7390();
  piVar4 = *(int **)(param_1 + 8);
  *piVar4 = iVar3;
  piVar4[2] = 8;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  piVar4 = *(int **)(param_1 + 0xc);
  if (((piVar4 < *(int **)(param_1 + 8)) && (piVar4 != &DAT_00c0bfc8)) && (piVar4[2] == 6)) {
    if (*(int **)(param_1 + 8) <= piVar4) {
      piVar4 = &DAT_00c0bfc8;
    }
    if ((piVar4[2] != 6) || (*(char *)(*piVar4 + 6) == '\0')) goto LAB_007073f2;
  }
  FUN_006f5da0(1);
LAB_007073f2:
  puVar5 = *(undefined4 **)(param_1 + 0xc);
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 <= puVar5) {
    puVar5 = &DAT_00c0bfc8;
  }
  *puVar1 = *puVar5;
  puVar1[1] = puVar5[1];
  puVar1[2] = puVar5[2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar2 = *(int *)(param_1 + 8);
  if (param_1 != iVar3) {
    *(undefined4 **)(param_1 + 8) = (undefined4 *)(iVar2 + -0x10);
    puVar5 = *(undefined4 **)(iVar3 + 8);
    *(undefined4 **)(iVar3 + 8) = puVar5 + 4;
    *puVar5 = *(undefined4 *)(iVar2 + -0x10);
    puVar5[1] = *(undefined4 *)(iVar2 + -0xc);
    puVar5[2] = *(undefined4 *)(iVar2 + -8);
  }
  return 1;
}

