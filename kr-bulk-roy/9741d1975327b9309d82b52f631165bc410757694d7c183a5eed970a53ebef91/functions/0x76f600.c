
void FUN_0076f600(undefined4 param_1)

{
  int in_ECX;
  
  *(char *)(in_ECX + 0xf6) = (char)param_1;
  if (*(int *)(in_ECX + 0xec) != 0) {
    (**(code **)(**(int **)(*(int *)(in_ECX + 0xec) + 0x100) + 0x94))(param_1);
  }
  return;
}

