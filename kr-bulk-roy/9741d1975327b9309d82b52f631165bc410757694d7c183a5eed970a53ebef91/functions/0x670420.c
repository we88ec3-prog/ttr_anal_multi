
void FUN_00670420(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20))) {
    FUN_00670450();
  }
  return;
}

