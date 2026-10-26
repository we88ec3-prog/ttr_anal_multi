
undefined4 FUN_00706620(int param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    FUN_006f6210(param_1);
  }
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 != &DAT_00c0bfc8) && (puVar1[2] == 6)) goto LAB_007066b6;
    if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
       ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_0070667f;
    pcVar2 = (&PTR_DAT_00c0be1c)[puVar1[2]];
  }
  else {
LAB_0070667f:
    pcVar2 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","function",pcVar2);
  FUN_006f5da0(1);
LAB_007066b6:
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x30U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x30U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x30;
  iVar3 = FUN_006fe990(param_1);
  if (iVar3 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f52b0();
    return 2;
  }
  return 1;
}

