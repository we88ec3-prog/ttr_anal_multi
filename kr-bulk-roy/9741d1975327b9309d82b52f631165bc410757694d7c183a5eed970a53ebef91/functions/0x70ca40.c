
undefined4 FUN_0070ca40(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  iVar2 = param_1;
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 == &DAT_00c0bfc8) || (puVar1[2] != 5)) {
      if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
         ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_0070ca73;
      pcVar3 = (&PTR_DAT_00c0be1c)[puVar1[2]];
      goto LAB_0070ca81;
    }
  }
  else {
LAB_0070ca73:
    pcVar3 = "no value";
LAB_0070ca81:
    FUN_006f5580(param_1,"%s expected, got %s","table",pcVar3);
    FUN_006f5da0(1);
  }
  piVar6 = *(int **)(param_1 + 0xc);
  if (*(int **)(param_1 + 8) <= piVar6) {
    piVar6 = &DAT_00c0bfc8;
  }
  switch(piVar6[2]) {
  case 3:
    iVar4 = FUN_006fb5d0();
    if (iVar4 == 0) {
      param_1 = 0;
    }
    else {
      param_1 = *(undefined4 *)(*piVar6 + 0xc);
    }
    break;
  case 4:
    param_1 = *(undefined4 *)(*piVar6 + 0xc);
    break;
  case 5:
    param_1 = FUN_006f9f10();
    break;
  default:
    param_1 = 0;
    break;
  case 7:
    param_1 = *(undefined4 *)(*piVar6 + 0x10);
  }
  iVar4 = FUN_006f5170();
  if (iVar4 == 0) {
    FUN_006f5f30(iVar2,"stack overflow (%s)",&DAT_00bf2375);
  }
  iVar4 = *(int *)(iVar2 + 0xc);
  puVar1 = *(undefined4 **)(iVar2 + 8);
  puVar5 = (undefined4 *)(iVar4 + 0x10);
  if (((puVar1 <= puVar5) || (puVar5 == &DAT_00c0bfc8)) || (*(int *)(iVar4 + 0x18) < 1))
  goto LAB_0070cb92;
  if (puVar5 < puVar1) {
    if ((puVar5 != &DAT_00c0bfc8) && (*(int *)(iVar4 + 0x18) == 6)) goto LAB_0070cb92;
    if ((puVar1 <= puVar5) || ((puVar5 == &DAT_00c0bfc8 || (*(int *)(iVar4 + 0x18) == -1))))
    goto LAB_0070cb64;
    pcVar3 = (&PTR_DAT_00c0be1c)[*(int *)(iVar4 + 0x18)];
  }
  else {
LAB_0070cb64:
    pcVar3 = "no value";
  }
  FUN_006f5580(iVar2,"%s expected, got %s","function",pcVar3);
  FUN_006f5da0(2);
LAB_0070cb92:
  if (*(uint *)(iVar2 + 8) < *(int *)(iVar2 + 0xc) + 0x20U) {
    do {
      *(undefined4 *)(*(int *)(iVar2 + 8) + 8) = 0;
      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 0x10;
    } while (*(uint *)(iVar2 + 8) < *(int *)(iVar2 + 0xc) + 0x20U);
  }
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 0xc) + 0x20;
  FUN_0070c5d0(iVar2,1,param_1);
  return 0;
}

