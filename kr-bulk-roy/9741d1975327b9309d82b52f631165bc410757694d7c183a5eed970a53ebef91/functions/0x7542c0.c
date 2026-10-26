
void FUN_007542c0(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(in_ECX + 0xb4);
  *(undefined4 *)(in_ECX + 0xa8) = *(undefined4 *)(in_ECX + 0xb8);
  *(int *)(in_ECX + 0xac) =
       (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xbc)) - *(int *)(in_ECX + 8);
  iVar2 = *(int *)(in_ECX + 0xc4);
  *(int *)(in_ECX + 0xb0) =
       (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc)) - *(int *)(in_ECX + 0xc0);
  *(int *)(in_ECX + 0xa4) = *(int *)(in_ECX + 0xa4) + iVar2;
  iVar1 = *(int *)(in_ECX + 0xac) - iVar2;
  if (iVar1 < *(int *)(in_ECX + 0xa4)) {
    iVar1 = *(int *)(in_ECX + 0xa4);
  }
  *(int *)(in_ECX + 0xa8) = *(int *)(in_ECX + 0xa8) + iVar2;
  *(int *)(in_ECX + 0xac) = iVar1;
  iVar2 = *(int *)(in_ECX + 0xb0) - iVar2;
  if (iVar2 < *(int *)(in_ECX + 0xa8)) {
    *(int *)(in_ECX + 0xb0) = *(int *)(in_ECX + 0xa8);
    return;
  }
  *(int *)(in_ECX + 0xb0) = iVar2;
  return;
}

