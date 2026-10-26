
void FUN_00864bf0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1c) != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x15c))(*(int **)(in_ECX + 4),*(int *)(in_ECX + 0x1c));
  }
  return;
}

