
void FUN_00560090(undefined4 *param_1)

{
  int *piVar1;
  
  switch(*param_1) {
  case 1:
    *(undefined4 *)(DAT_00fe2770 + 0x20) = 2;
    FUN_006d6120();
    (**(code **)(**(int **)(DAT_00fe2770 + 0x18) + 0x24))();
    *param_1 = 2;
    return;
  case 2:
    if (*(int *)(*(int *)(DAT_00fe2770 + 0x18) + 0xc) == 2) {
      *(undefined4 *)(*(int *)(DAT_00fe2770 + 0x18) + 0x7c) = 0x3f800000;
    }
    *param_1 = 3;
    return;
  case 3:
    goto switchD_005600a6_caseD_3;
  case 4:
    *param_1 = 5;
    return;
  case 5:
    *param_1 = 6;
    return;
  case 6:
    piVar1 = (int *)(DAT_00fe2770 + 0x20);
    *piVar1 = 0;
    FUN_006d6120();
    if (*piVar1 == 0) {
      FUN_006d6120();
    }
    *param_1 = 0;
switchD_005600a6_caseD_3:
    return;
  default:
    return;
  }
}

