
undefined4 FUN_00705c60(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar2) || (puVar2 == &DAT_00c0bfc8)) || (puVar2[2] == -1))
  {
    FUN_006f5da0(1);
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((*(undefined4 **)(param_1 + 8) <= puVar2) || (puVar2 == &DAT_00c0bfc8)) ||
     (*(int *)(*(int *)(param_1 + 0xc) + 0x18) == -1)) {
    FUN_006f5da0(2);
  }
  puVar3 = *(uint **)(param_1 + 0xc);
  puVar1 = *(uint **)(param_1 + 8);
  puVar5 = &DAT_00c0bfc8;
  if (puVar3 < puVar1) {
    puVar5 = puVar3;
  }
  puVar3 = puVar3 + 4;
  if (puVar1 <= puVar3) {
    puVar3 = &DAT_00c0bfc8;
  }
  if ((puVar5 == &DAT_00c0bfc8) || (puVar3 == &DAT_00c0bfc8)) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_006f7710();
  }
  puVar1[2] = 1;
  *puVar1 = (uint)(iVar4 != 0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

