
void FUN_004a8810(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 4) / 2;
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 8) / 2 + -0x3c;
  return;
}

