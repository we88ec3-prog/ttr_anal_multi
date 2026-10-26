
undefined4 FUN_007173e0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x44);
  *(int *)(in_ECX + 0x118) = param_1;
  *(undefined4 *)(in_ECX + 0x11c) = uVar1;
  return 1;
}

