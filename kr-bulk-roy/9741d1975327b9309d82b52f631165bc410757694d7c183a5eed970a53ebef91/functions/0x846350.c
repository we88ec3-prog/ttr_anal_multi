
void FUN_00846350(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if (*(int **)(in_ECX + 0x74) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x74) + 0x1c))(param_1);
  }
  return;
}

