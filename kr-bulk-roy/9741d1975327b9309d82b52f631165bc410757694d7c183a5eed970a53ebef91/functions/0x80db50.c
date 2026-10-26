
undefined4 FUN_0080db50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) != 0) {
    return 0;
  }
  InterlockedExchange((LONG *)(in_ECX + 0xc),0);
  InterlockedExchange((LONG *)(in_ECX + 0x10),0);
  InterlockedExchange((LONG *)(in_ECX + 0x14),0);
  if (*(int **)(in_ECX + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x3c) + 8))();
    *(undefined4 *)(in_ECX + 0x3c) = 0;
  }
  return 1;
}

