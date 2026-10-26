
undefined4 FUN_006f5f30(int param_1)

{
  FUN_006f5e90();
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  FUN_006f7860(&stack0x0000000c);
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  FUN_006fc080(param_1,2,(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + -1);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  FUN_006f8ad0();
  return 0;
}

