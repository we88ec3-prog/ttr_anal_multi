
bool FUN_0081b590(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return false;
  }
  return *(int *)(*(int *)(*(int *)(param_1 + 0x1c) + 8) + 0x28) == *(int *)(in_ECX + 8);
}

