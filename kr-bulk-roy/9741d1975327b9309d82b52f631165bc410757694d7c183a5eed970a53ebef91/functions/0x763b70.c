
void FUN_00763b70(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x98) != '\0') {
    if (*(int **)(in_ECX + 8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 8) + 8))();
      *(undefined4 *)(in_ECX + 8) = 0;
    }
    *(undefined4 *)(in_ECX + 0x58) = 0;
    *(undefined4 *)(in_ECX + 0x5c) = 0;
    *(undefined1 *)(in_ECX + 0x98) = 0;
  }
  return;
}

