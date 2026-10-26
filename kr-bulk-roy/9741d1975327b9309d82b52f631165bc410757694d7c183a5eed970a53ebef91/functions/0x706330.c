
undefined4 FUN_00706330(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0xc);
  if (puVar5 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar5 != &DAT_00c0bfc8) && (puVar5[2] == 5)) goto LAB_0070638f;
    if ((*(undefined4 **)(param_1 + 8) <= puVar5) ||
       ((puVar5 == &DAT_00c0bfc8 || (puVar5[2] == -1)))) goto LAB_00706363;
    pcVar4 = (&PTR_DAT_00c0be1c)[puVar5[2]];
  }
  else {
LAB_00706363:
    pcVar4 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar4);
  FUN_006f5da0(1);
LAB_0070638f:
  iVar1 = **(int **)(*(int *)(param_1 + 0x14) + 4);
  puVar5 = (undefined4 *)(iVar1 + 0x18);
  if (*(char *)(iVar1 + 7) == '\0') {
    puVar5 = &DAT_00c0bfc8;
  }
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = *puVar5;
  puVar2[1] = puVar5[1];
  puVar2[2] = puVar5[2];
  puVar5 = *(undefined4 **)(param_1 + 0xc);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar2 = *(undefined4 **)(param_1 + 8);
  if (puVar2 <= puVar5) {
    puVar5 = &DAT_00c0bfc8;
  }
  *puVar2 = *puVar5;
  puVar2[1] = puVar5[1];
  puVar2[2] = puVar5[2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar3 = *(undefined8 **)(param_1 + 8);
  *puVar3 = 0;
  *(undefined4 *)(puVar3 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 3;
}

