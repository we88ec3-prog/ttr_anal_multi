
void FUN_005d4d30(void)

{
  int in_ECX;
  
  FUN_005cf270();
  *(undefined1 *)(in_ECX + 0x380) = 1;
  (**(code **)(**(int **)(in_ECX + 900) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x388) + 0x94))(1);
  return;
}

