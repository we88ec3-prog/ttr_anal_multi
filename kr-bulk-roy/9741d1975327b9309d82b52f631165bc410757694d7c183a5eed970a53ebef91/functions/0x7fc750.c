
undefined4 FUN_007fc750(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x20);
}

