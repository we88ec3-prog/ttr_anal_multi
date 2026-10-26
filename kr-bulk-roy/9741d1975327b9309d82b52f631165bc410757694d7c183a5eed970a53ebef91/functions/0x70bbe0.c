
undefined4 FUN_0070bbe0(int param_1)

{
  undefined4 *puVar1;
  double *pdVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  
  iVar3 = param_1;
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 != &DAT_00c0bfc8) && (puVar1[2] == 5)) goto LAB_0070bc41;
    if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
       ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_0070bc13;
    pcVar4 = (&PTR_DAT_00c0be1c)[puVar1[2]];
  }
  else {
LAB_0070bc13:
    pcVar4 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar4);
  FUN_006f5da0(1);
LAB_0070bc41:
  piVar6 = *(int **)(param_1 + 0xc);
  if (*(int **)(param_1 + 8) <= piVar6) {
    piVar6 = &DAT_00c0bfc8;
  }
  switch(piVar6[2]) {
  case 3:
    iVar5 = FUN_006fb5d0();
    if (iVar5 == 0) {
      param_1 = 0;
    }
    else {
      param_1 = *(int *)(*piVar6 + 0xc);
    }
    break;
  case 4:
    param_1 = *(int *)(*piVar6 + 0xc);
    break;
  case 5:
    param_1 = FUN_006f9f10();
    break;
  default:
    param_1 = 0;
    break;
  case 7:
    param_1 = *(int *)(*piVar6 + 0x10);
  }
  pdVar2 = *(double **)(iVar3 + 8);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)param_1;
  piVar6 = (int *)(iVar3 + 8);
  *piVar6 = *piVar6 + 0x10;
  return 1;
}

