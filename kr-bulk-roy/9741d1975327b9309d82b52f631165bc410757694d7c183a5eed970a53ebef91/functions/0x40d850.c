
void FUN_0040d850(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 0x9c) + 0x84) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0xa0) + 0x84) = 2;
  (**(code **)(**(int **)(in_ECX + 0x9c) + 0x90))(1);
  (**(code **)(**(int **)(in_ECX + 0xa0) + 0x90))(1);
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  (**(code **)(**(int **)(in_ECX + 0xa4) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0xa8) + 0x94))(0);
  *(undefined2 *)(in_ECX + 0xb5) = 0;
  *(undefined1 *)(in_ECX + 0xb4) = 1;
  return;
}

