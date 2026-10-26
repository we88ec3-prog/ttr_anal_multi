
void FUN_004d4920(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 4) / 2;
  *(undefined4 *)(in_ECX + 0x10) = 0x32;
  return;
}

