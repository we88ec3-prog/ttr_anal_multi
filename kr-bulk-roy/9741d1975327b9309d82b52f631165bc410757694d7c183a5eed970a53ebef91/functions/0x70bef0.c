
undefined4 FUN_0070bef0(int param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int local_8;
  
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if (puVar2 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar2 != &DAT_00c0bfc8) && (puVar2[2] == 5)) goto LAB_0070bf54;
    if ((*(undefined4 **)(param_1 + 8) <= puVar2) ||
       ((puVar2 == &DAT_00c0bfc8 || (puVar2[2] == -1)))) goto LAB_0070bf26;
    pcVar1 = (&PTR_DAT_00c0be1c)[puVar2[2]];
  }
  else {
LAB_0070bf26:
    pcVar1 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar1);
  FUN_006f5da0(1);
LAB_0070bf54:
  piVar5 = *(int **)(param_1 + 0xc);
  if (*(int **)(param_1 + 8) <= piVar5) {
    piVar5 = &DAT_00c0bfc8;
  }
  switch(piVar5[2]) {
  case 3:
    iVar3 = FUN_006fb5d0();
    if (iVar3 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(int *)(*piVar5 + 0xc);
    }
    break;
  case 4:
    local_8 = *(int *)(*piVar5 + 0xc);
    break;
  case 5:
    local_8 = FUN_006f9f10();
    break;
  default:
    local_8 = 0;
    break;
  case 7:
    local_8 = *(int *)(*piVar5 + 0x10);
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  iVar3 = local_8;
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    iVar3 = FUN_006f6370(param_1,2);
  }
  if ((0 < iVar3) && (iVar3 <= local_8)) {
    puVar4 = (undefined4 *)FUN_006f9b70(iVar3);
    puVar2 = *(undefined4 **)(param_1 + 8);
    *puVar2 = *puVar4;
    puVar2[1] = puVar4[1];
    puVar2[2] = puVar4[2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    while (iVar3 < local_8) {
      puVar4 = (undefined4 *)FUN_006f9b70(iVar3 + 1);
      puVar2 = *(undefined4 **)(param_1 + 8);
      *puVar2 = *puVar4;
      puVar2[1] = puVar4[1];
      puVar2[2] = puVar4[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_006f5870(iVar3);
      iVar3 = iVar3 + 1;
    }
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f5870(local_8);
    return 1;
  }
  return 0;
}

