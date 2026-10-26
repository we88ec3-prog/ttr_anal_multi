
void FUN_0075e690(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 0xc4) - *(int *)(in_ECX + 0xd8);
  *(uint *)(in_ECX + 0xc4) = uVar1 & ((int)uVar1 < 1) - 1;
  if (*(int *)(in_ECX + 0x24) != 0) {
    *(undefined4 *)(in_ECX + 0xdc) = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x1330);
  }
  return;
}

