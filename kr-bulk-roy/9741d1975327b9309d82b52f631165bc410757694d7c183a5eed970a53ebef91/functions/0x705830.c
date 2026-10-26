
undefined4 FUN_00705830(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  puVar2 = *(undefined4 **)(param_1 + 8);
  if ((puVar1 + 4 < puVar2) && (puVar1 + 4 != &DAT_00c0bfc8)) {
    iVar6 = puVar1[6];
  }
  else {
    iVar6 = -1;
  }
  if (puVar1 < puVar2) {
    if ((puVar1 != &DAT_00c0bfc8) && (puVar1[2] == 5)) goto LAB_007058a6;
    if ((puVar2 <= puVar1) || ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_0070587a;
    pcVar4 = (&PTR_DAT_00c0be1c)[puVar1[2]];
  }
  else {
LAB_0070587a:
    pcVar4 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar4);
  FUN_006f5da0(1);
LAB_007058a6:
  if ((iVar6 != 0) && (iVar6 != 5)) {
    FUN_006f5da0(2);
  }
  piVar5 = *(int **)(param_1 + 0xc);
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 <= piVar5) {
    piVar5 = &DAT_00c0bfc8;
  }
  iVar6 = piVar5[2];
  if (iVar6 == 5) {
    iVar6 = *(int *)(*piVar5 + 8);
  }
  else if (iVar6 == 7) {
    iVar6 = *(int *)(*piVar5 + 8);
  }
  else {
    iVar6 = *(int *)(*(int *)(param_1 + 0x10) + 0x98 + iVar6 * 4);
  }
  if (iVar6 != 0) {
    *piVar3 = iVar6;
    piVar3[2] = 5;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    iVar6 = FUN_006f6470();
    if (iVar6 != 0) {
      FUN_006f5f30(param_1,"cannot change a protected metatable");
    }
  }
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x20;
  FUN_006f5910();
  return 1;
}

