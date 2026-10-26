
undefined4 FUN_00706c70(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] == -1))
  {
    FUN_006f5da0(1);
  }
  iVar3 = FUN_006f64f0();
  if (iVar3 != 0) {
    return 1;
  }
  piVar4 = *(int **)(param_1 + 0xc);
  piVar2 = *(int **)(param_1 + 8);
  if (piVar4 < piVar2) {
    if (piVar4 != &DAT_00c0bfc8) {
      switch(piVar4[2]) {
      case 0:
        FUN_006f54d0(&DAT_00c42c44,3);
        return 1;
      case 1:
        iVar3 = FUN_006f53d0();
        pcVar5 = "true";
        if (iVar3 == 0) {
          pcVar5 = "false";
        }
        FUN_006f5510(pcVar5);
        return 1;
      case 3:
        if (piVar2 <= piVar4) {
          piVar4 = &DAT_00c0bfc8;
        }
        if (piVar4[2] != 4) {
          iVar3 = FUN_006fb5d0();
          if (iVar3 == 0) {
            FUN_006f5510(0);
            return 1;
          }
          if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <=
              *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
            FUN_006fb3a0();
          }
          piVar4 = *(int **)(param_1 + 0xc);
          if (*(int **)(param_1 + 8) <= piVar4) {
            piVar4 = &DAT_00c0bfc8;
          }
        }
        FUN_006f5510(*piVar4 + 0x10);
        return 1;
      case 4:
        FUN_006f5300();
        return 1;
      }
    }
    piVar6 = piVar4;
    if (piVar2 <= piVar4) goto LAB_00706da8;
  }
  else {
LAB_00706da8:
    piVar6 = &DAT_00c0bfc8;
  }
  switch(piVar6[2]) {
  case 2:
  case 7:
    piVar6 = &DAT_00c0bfc8;
    if (piVar4 < piVar2) {
      piVar6 = piVar4;
    }
    if (piVar6[2] == 2) goto switchD_00706dbc_caseD_5;
    if (piVar6[2] == 7) {
      iVar3 = *piVar6 + 0x18;
      break;
    }
  default:
    iVar3 = 0;
    break;
  case 5:
  case 6:
  case 8:
switchD_00706dbc_caseD_5:
    iVar3 = *piVar6;
  }
  if (((piVar4 < piVar2) && (piVar4 != &DAT_00c0bfc8)) && (piVar4[2] != -1)) {
    pcVar5 = (&PTR_DAT_00c0be1c)[piVar4[2]];
  }
  else {
    pcVar5 = "no value";
  }
  FUN_006f5580(param_1,"%s: %p",pcVar5,iVar3);
  return 1;
}

