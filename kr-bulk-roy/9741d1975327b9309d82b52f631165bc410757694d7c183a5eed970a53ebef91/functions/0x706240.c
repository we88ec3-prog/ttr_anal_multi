
byte FUN_00706240(int param_1)

{
  undefined4 *puVar1;
  double *pdVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  
  iVar3 = FUN_006f6370(param_1,2);
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 != &DAT_00c0bfc8) && (puVar1[2] == 5)) goto LAB_007062af;
    if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
       ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_00706281;
    pcVar4 = (&PTR_DAT_00c0be1c)[puVar1[2]];
  }
  else {
LAB_00706281:
    pcVar4 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar4);
  FUN_006f5da0(1);
LAB_007062af:
  pdVar2 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)(iVar3 + 1);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar5 = (undefined4 *)FUN_006f9b70(iVar3 + 1);
  *puVar1 = *puVar5;
  puVar1[1] = puVar5[1];
  puVar1[2] = puVar5[2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if (*(undefined **)(param_1 + 8) == &DAT_00c0bfd8) {
    return 2;
  }
  return -(*(int *)(*(undefined **)(param_1 + 8) + -8) != 0) & 2;
}

