
void FUN_00864c10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 400))
              (*(int **)(in_ECX + 4),0,*(int *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x20),
               *(undefined4 *)(in_ECX + 0x10));
  }
  return;
}

