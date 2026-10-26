
undefined4 FUN_0070b720(int param_1)

{
  double *pdVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int local_c;
  int local_8;
  
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  if (puVar4 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar4 == &DAT_00c0bfc8) || (puVar4[2] != 5)) {
      if ((*(undefined4 **)(param_1 + 8) <= puVar4) ||
         ((puVar4 == &DAT_00c0bfc8 || (puVar4[2] == -1)))) goto LAB_0070b756;
      pcVar2 = (&PTR_DAT_00c0be1c)[puVar4[2]];
      goto LAB_0070b764;
    }
  }
  else {
LAB_0070b756:
    pcVar2 = "no value";
LAB_0070b764:
    FUN_006f5580(param_1,"%s expected, got %s","table",pcVar2);
    FUN_006f5da0(1);
  }
  piVar6 = *(int **)(param_1 + 0xc);
  if (*(int **)(param_1 + 8) <= piVar6) {
    piVar6 = &DAT_00c0bfc8;
  }
  switch(piVar6[2]) {
  case 3:
    iVar3 = FUN_006fb5d0();
    if (iVar3 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(int *)(*piVar6 + 0xc);
    }
    break;
  case 4:
    local_8 = *(int *)(*piVar6 + 0xc);
    break;
  case 5:
    local_8 = FUN_006f9f10();
    break;
  default:
    local_8 = 0;
    break;
  case 7:
    local_8 = *(int *)(*piVar6 + 0x10);
  }
  iVar3 = *(int *)(param_1 + 0xc);
  puVar4 = (undefined4 *)(iVar3 + 0x10);
  if (puVar4 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar4 != &DAT_00c0bfc8) && (*(int *)(iVar3 + 0x18) == 6)) goto LAB_0070b841;
    if ((*(undefined4 **)(param_1 + 8) <= puVar4) ||
       ((puVar4 == &DAT_00c0bfc8 || (*(int *)(iVar3 + 0x18) == -1)))) goto LAB_0070b813;
    pcVar2 = (&PTR_DAT_00c0be1c)[*(int *)(iVar3 + 0x18)];
  }
  else {
LAB_0070b813:
    pcVar2 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","function",pcVar2);
  FUN_006f5da0(2);
LAB_0070b841:
  local_c = 1;
  if (0 < local_8) {
    do {
      puVar4 = *(undefined4 **)(param_1 + 8);
      puVar5 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
      if (puVar4 <= puVar5) {
        puVar5 = &DAT_00c0bfc8;
      }
      *puVar4 = *puVar5;
      puVar4[1] = puVar5[1];
      puVar4[2] = puVar5[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      pdVar1 = *(double **)(param_1 + 8);
      *pdVar1 = (double)local_c;
      *(undefined4 *)(pdVar1 + 1) = 3;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      puVar4 = *(undefined4 **)(param_1 + 8);
      puVar5 = (undefined4 *)FUN_006f9b70(local_c);
      *puVar4 = *puVar5;
      puVar4[1] = puVar5[1];
      puVar4[2] = puVar5[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x30,1);
      puVar4 = (undefined4 *)(*(int *)(param_1 + 8) + -0x10);
      if ((puVar4 == &DAT_00c0bfc8) || (*(int *)(*(int *)(param_1 + 8) + -8) != 0)) {
        return 1;
      }
      *(undefined4 **)(param_1 + 8) = puVar4;
      local_c = local_c + 1;
    } while (local_c <= local_8);
  }
  return 0;
}

