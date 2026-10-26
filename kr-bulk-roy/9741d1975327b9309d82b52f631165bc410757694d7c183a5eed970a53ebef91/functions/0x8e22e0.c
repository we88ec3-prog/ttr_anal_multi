
int FUN_008e22e0(void)

{
  uint in_ECX;
  int in_EDX;
  int extraout_EDX;
  
  if (*(uint *)(in_EDX + 0x14) <= in_ECX) {
    FUN_008e0760();
    in_ECX = 0;
    in_EDX = extraout_EDX;
  }
  return *(int *)(in_EDX + 8) * in_ECX + *(int *)(in_EDX + 0x1c);
}

