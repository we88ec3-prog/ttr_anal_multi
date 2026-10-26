
void FUN_0075e7e0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xd8) + *(int *)(in_ECX + 0xc4);
  if (iVar1 < *(int *)(in_ECX + 0xb8)) {
    *(int *)(in_ECX + 0xc4) = iVar1;
    return;
  }
  *(int *)(in_ECX + 0xc4) = *(int *)(in_ECX + 0xb8);
  return;
}

