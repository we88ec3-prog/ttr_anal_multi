
void FUN_0075e7c0(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 0xc4) - *(int *)(in_ECX + 0xd8);
  *(uint *)(in_ECX + 0xc4) = uVar1 & ((int)uVar1 < 1) - 1;
  return;
}

