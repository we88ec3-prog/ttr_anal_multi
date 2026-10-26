
void FUN_006a7800(void)

{
  int in_ECX;
  
  FUN_006a71a0();
  FUN_006a7660();
  *(undefined1 *)(*(int *)(in_ECX + 0x100) + 0xc9) = 0;
  (**(code **)(**(int **)(in_ECX + 0x108) + 0x90))(0);
  return;
}

