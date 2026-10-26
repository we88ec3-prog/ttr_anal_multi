
void FUN_004ba610(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_0089120c(*(int *)(in_ECX + 0x18));
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}

