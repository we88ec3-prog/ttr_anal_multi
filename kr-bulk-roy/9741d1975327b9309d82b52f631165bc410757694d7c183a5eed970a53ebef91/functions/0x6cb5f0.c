
void FUN_006cb5f0(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x154) + 0x20))) {
    FUN_006cb640(in_ECX);
  }
  return;
}

