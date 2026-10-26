
undefined4 FUN_00707af0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  uVar2 = FUN_006fec70(param_1,"cannot close standard file",0x1a);
  *puVar1 = uVar2;
  puVar1[2] = 4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 2;
}

