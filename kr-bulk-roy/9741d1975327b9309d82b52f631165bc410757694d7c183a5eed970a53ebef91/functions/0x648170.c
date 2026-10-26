
void FUN_00648170(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0xcb) {
    (**(code **)(**(int **)(in_ECX + 0xac) + 0x94))(1);
    return;
  }
  if (((*(int *)(param_1 + 0x10) == 0xcc) && (*(int *)(in_ECX + 0x24) != 0)) &&
     (*(int *)(*(int *)(in_ECX + 0x24) + 0x13cc) != *(int *)(in_ECX + 0xac))) {
    (**(code **)(**(int **)(in_ECX + 0xac) + 0x94))(0);
  }
  return;
}

