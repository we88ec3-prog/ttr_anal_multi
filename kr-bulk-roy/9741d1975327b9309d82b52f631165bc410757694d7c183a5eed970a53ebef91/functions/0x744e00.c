
void FUN_00744e00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
    *(int *)(*(int *)(in_ECX + 0x24) + 0x13e8) = in_ECX;
  }
  return;
}

