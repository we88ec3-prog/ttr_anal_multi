
void FUN_007a5790(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x1c) != 2) && (*(int *)(in_ECX + 0x1c) != 3)) {
    FUN_007a8e70(in_ECX + -8);
  }
  if (*(int *)(in_ECX + 0x100) != 0) {
    FUN_007bdf90();
    return;
  }
  return;
}

