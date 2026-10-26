
void FUN_007d4f70(uint param_1)

{
  int in_ECX;
  
  if (param_1 < (uint)(*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28) >> 2)) {
    (**(code **)(**(int **)(*(int *)(in_ECX + 0x28) + param_1 * 4) + 0x10))();
  }
  return;
}

