
void FUN_0075e700(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xd8) + *(int *)(in_ECX + 0xc4);
  if (*(int *)(in_ECX + 0xb8) <= iVar1) {
    iVar1 = *(int *)(in_ECX + 0xb8);
  }
  *(int *)(in_ECX + 0xc4) = iVar1;
  if (*(int *)(in_ECX + 0x24) != 0) {
    *(undefined4 *)(in_ECX + 0xdc) = *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x1330);
  }
  return;
}

