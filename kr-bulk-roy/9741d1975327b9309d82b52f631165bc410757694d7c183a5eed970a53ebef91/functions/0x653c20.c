
void FUN_00653c20(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 300) + 0x20))) {
    FUN_00653c50(in_ECX);
  }
  return;
}

