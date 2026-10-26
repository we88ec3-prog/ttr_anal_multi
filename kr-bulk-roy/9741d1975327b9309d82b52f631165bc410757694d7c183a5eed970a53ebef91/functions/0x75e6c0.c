
void FUN_0075e6c0(void)

{
  uint uVar1;
  int in_ECX;
  
  if (0.5 < *(float *)(*(int *)(in_ECX + 0x24) + 0x1330) - *(float *)(in_ECX + 0xdc)) {
    uVar1 = *(int *)(in_ECX + 0xc4) - *(int *)(in_ECX + 0xd8);
    *(uint *)(in_ECX + 0xc4) = uVar1 & ((int)uVar1 < 1) - 1;
  }
  return;
}

