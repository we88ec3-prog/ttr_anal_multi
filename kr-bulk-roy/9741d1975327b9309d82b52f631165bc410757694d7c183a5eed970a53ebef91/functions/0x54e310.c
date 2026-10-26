
undefined4 FUN_0054e310(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    iVar1 = *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2;
    if ((iVar1 == 0) ||
       (*(int *)(in_ECX + 0x44) <= *(int *)(*(int *)(*(int *)(in_ECX + 8) + -4 + iVar1 * 4) + 0x24))
       ) {
      return 0;
    }
  }
  return 1;
}

