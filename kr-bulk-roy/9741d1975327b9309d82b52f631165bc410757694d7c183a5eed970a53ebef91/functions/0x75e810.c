
void FUN_0075e810(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 0xc4) - *(int *)(in_ECX + 0xd8);
  uVar1 = ((int)uVar1 < 1) - 1 & uVar1;
  *(uint *)(in_ECX + 0xc4) = uVar1;
  iVar2 = FUN_0075e270();
  if (iVar2 < (int)uVar1) {
    *(uint *)(in_ECX + 0xc4) = uVar1;
    return;
  }
  *(int *)(in_ECX + 0xc4) = iVar2;
  return;
}

