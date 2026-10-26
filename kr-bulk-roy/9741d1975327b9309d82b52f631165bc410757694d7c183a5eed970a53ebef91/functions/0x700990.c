
undefined4 FUN_00700990(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((*(undefined4 **)(param_1 + 8) <= puVar2) || (puVar2 == &DAT_00c0bfc8)) ||
     ((iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x18), iVar3 != 0 && (iVar3 != 5)))) {
    FUN_006f5da0(2);
  }
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x20;
  iVar3 = FUN_006f5910();
  puVar1 = *(uint **)(param_1 + 8);
  puVar1[2] = 1;
  *puVar1 = (uint)(iVar3 != 0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

