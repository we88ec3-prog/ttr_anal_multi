
void FUN_00769450(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14c0) = 5;
  }
  return;
}

