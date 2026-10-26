
int FUN_00740620(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = 0x34;
  if (*(int *)(in_ECX + 0x14) != 0) {
    iVar1 = *(int *)(in_ECX + 0x10) * *(int *)(in_ECX + 8) + 0x34;
  }
  if (*(int *)(in_ECX + 0x2c) != 0) {
    iVar1 = iVar1 + *(int *)(in_ECX + 0xc) * *(int *)(in_ECX + 8) * 4;
  }
  return iVar1;
}

