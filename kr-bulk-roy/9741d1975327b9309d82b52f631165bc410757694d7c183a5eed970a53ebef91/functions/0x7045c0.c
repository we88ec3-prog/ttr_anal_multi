
undefined4 FUN_007045c0(int param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  FUN_006f6210(param_1);
  FUN_006f6210(param_1);
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U);
  }
  iVar1 = *(int *)(param_1 + 0xc);
  puVar2 = (undefined8 *)(iVar1 + 0x20);
  *(undefined8 **)(param_1 + 8) = puVar2;
  *puVar2 = 0;
  *(undefined4 *)(iVar1 + 0x28) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006f55b0(FUN_007043c0,3);
  return 1;
}

