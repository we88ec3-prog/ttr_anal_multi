
undefined4 FUN_007060a0(int param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 != &DAT_00c0bfc8) && (puVar1[2] == 5)) goto LAB_007060ff;
    if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
       ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_007060d3;
    pcVar2 = (&PTR_DAT_00c0be1c)[puVar1[2]];
  }
  else {
LAB_007060d3:
    pcVar2 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar2);
  FUN_006f5da0(1);
LAB_007060ff:
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U);
  }
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 **)(param_1 + 8) = puVar1 + 8;
  puVar4 = &DAT_00c0bfc8;
  if (puVar1 < puVar1 + 8) {
    puVar4 = puVar1;
  }
  iVar3 = FUN_006f9270(*puVar4);
  if (iVar3 != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 2;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

