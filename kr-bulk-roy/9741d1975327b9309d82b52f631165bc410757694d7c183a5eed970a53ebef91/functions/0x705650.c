
undefined4 FUN_00705650(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    iVar3 = FUN_006f6370(param_1,2);
  }
  else {
    iVar3 = 1;
  }
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U);
  }
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 **)(param_1 + 8) = puVar2 + 4;
  if ((((puVar2 < puVar2 + 4) && (puVar2 != &DAT_00c0bfc8)) &&
      ((puVar2[2] == 4 || (puVar2[2] == 3)))) && (0 < iVar3)) {
    FUN_006f5e90();
    puVar2 = *(undefined4 **)(param_1 + 0xc);
    puVar1 = *(undefined4 **)(param_1 + 8);
    if (puVar1 <= puVar2) {
      puVar2 = &DAT_00c0bfc8;
    }
    *puVar1 = *puVar2;
    puVar1[1] = puVar2[1];
    puVar1[2] = puVar2[2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    FUN_006fc080(param_1,2,(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + -1);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  }
  FUN_006f8ad0();
  return 0;
}

