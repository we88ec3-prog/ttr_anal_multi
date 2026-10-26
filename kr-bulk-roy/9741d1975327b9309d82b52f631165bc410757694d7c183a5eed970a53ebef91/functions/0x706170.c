
undefined4 FUN_00706170(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  if (puVar4 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar4 != &DAT_00c0bfc8) && (puVar4[2] == 5)) goto LAB_007061cf;
    if ((*(undefined4 **)(param_1 + 8) <= puVar4) ||
       ((puVar4 == &DAT_00c0bfc8 || (puVar4[2] == -1)))) goto LAB_007061a3;
    pcVar3 = (&PTR_DAT_00c0be1c)[puVar4[2]];
  }
  else {
LAB_007061a3:
    pcVar3 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar3);
  FUN_006f5da0(1);
LAB_007061cf:
  iVar1 = **(int **)(*(int *)(param_1 + 0x14) + 4);
  puVar4 = (undefined4 *)(iVar1 + 0x18);
  if (*(char *)(iVar1 + 7) == '\0') {
    puVar4 = &DAT_00c0bfc8;
  }
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = *puVar4;
  puVar2[1] = puVar4[1];
  puVar2[2] = puVar4[2];
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar2 = *(undefined4 **)(param_1 + 8);
  if (puVar2 <= puVar4) {
    puVar4 = &DAT_00c0bfc8;
  }
  *puVar2 = *puVar4;
  puVar2[1] = puVar4[1];
  puVar2[2] = puVar4[2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 3;
}

