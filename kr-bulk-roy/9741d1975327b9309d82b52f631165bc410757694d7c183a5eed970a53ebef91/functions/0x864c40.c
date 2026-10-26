
void FUN_00864c40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x1a0))(*(int **)(in_ECX + 4),*(int *)(in_ECX + 0x18));
  }
  return;
}

