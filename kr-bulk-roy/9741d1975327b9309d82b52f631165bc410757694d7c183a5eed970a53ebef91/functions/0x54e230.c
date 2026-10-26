
void FUN_0054e230(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) & 0xfffffffcU) == 0) {
    *(undefined4 *)(in_ECX + 0x40) = 0;
    return;
  }
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 1;
  return;
}

