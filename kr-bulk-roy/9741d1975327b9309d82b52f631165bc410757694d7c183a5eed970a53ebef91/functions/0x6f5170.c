
undefined4 FUN_006f5170(void)

{
  int in_EAX;
  uint uVar1;
  int in_ECX;
  
  if (0x7fff < (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 0xc) >> 4) + in_EAX) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) <= in_EAX * 0x10) {
    FUN_006fdcb0();
  }
  uVar1 = *(int *)(in_ECX + 8) + in_EAX * 0x10;
  if (*(uint *)(*(int *)(in_ECX + 0x14) + 8) < uVar1) {
    *(uint *)(*(int *)(in_ECX + 0x14) + 8) = uVar1;
  }
  return 1;
}

