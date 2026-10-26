
void FUN_007487d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14c0) = 0xc;
  }
  return;
}

