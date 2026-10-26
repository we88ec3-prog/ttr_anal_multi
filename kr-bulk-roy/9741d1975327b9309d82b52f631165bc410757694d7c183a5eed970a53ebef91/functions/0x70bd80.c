
undefined4 FUN_0070bd80(int param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 == &DAT_00c0bfc8) || (puVar1[2] != 5)) {
      if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
         ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_0070bdb6;
      pcVar2 = (&PTR_DAT_00c0be1c)[puVar1[2]];
      goto LAB_0070bdc4;
    }
  }
  else {
LAB_0070bdb6:
    pcVar2 = "no value";
LAB_0070bdc4:
    FUN_006f5580(param_1,"%s expected, got %s","table",pcVar2);
    FUN_006f5da0(1);
  }
  piVar8 = *(int **)(param_1 + 0xc);
  if (*(int **)(param_1 + 8) <= piVar8) {
    piVar8 = &DAT_00c0bfc8;
  }
  switch(piVar8[2]) {
  case 3:
    iVar3 = FUN_006fb5d0();
    if (iVar3 != 0) {
      iVar3 = *(int *)(*piVar8 + 0xc);
      break;
    }
  default:
    iVar3 = 0;
    break;
  case 4:
    iVar3 = *(int *)(*piVar8 + 0xc);
    break;
  case 5:
    iVar3 = FUN_006f9f10();
    break;
  case 7:
    iVar3 = *(int *)(*piVar8 + 0x10);
  }
  iVar3 = iVar3 + 1;
  iVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4;
  iVar6 = iVar3;
  if (iVar4 != 2) {
    if (iVar4 != 3) {
      uVar5 = FUN_006f5f30(param_1,"wrong number of arguments to \'insert\'");
      return uVar5;
    }
    iVar6 = FUN_006f6370(param_1,2);
    iVar4 = iVar3;
    if (iVar6 > iVar3) {
      iVar4 = iVar6;
    }
    if (iVar4 != iVar6 && SBORROW4(iVar4,iVar6) == (iVar6 <= iVar3 && iVar3 - iVar6 < 0)) {
      do {
        iVar3 = iVar4 + -1;
        puVar7 = (undefined4 *)FUN_006f9b70(iVar3);
        puVar1 = *(undefined4 **)(param_1 + 8);
        *puVar1 = *puVar7;
        puVar1[1] = puVar7[1];
        puVar1[2] = puVar7[2];
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        FUN_006f5870(iVar4);
        iVar4 = iVar3;
      } while (iVar6 < iVar3);
    }
  }
  FUN_006f5870(iVar6);
  return 0;
}

