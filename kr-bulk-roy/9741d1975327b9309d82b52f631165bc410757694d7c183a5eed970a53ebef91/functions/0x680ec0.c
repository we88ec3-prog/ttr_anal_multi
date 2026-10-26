
void FUN_00680ec0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x10c) + 0xa0))(0);
  (**(code **)(**(int **)(in_ECX + 0x110) + 0xa0))(0);
  (**(code **)(**(int **)(in_ECX + 0x114) + 0xa0))(0);
  *(undefined4 *)(in_ECX + 0x100) = 0xffffffff;
  return;
}

