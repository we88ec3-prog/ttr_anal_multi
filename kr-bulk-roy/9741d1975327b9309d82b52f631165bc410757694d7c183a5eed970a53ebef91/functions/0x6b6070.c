
void FUN_006b6070(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20))) {
    FUN_006b5dd0(in_ECX);
  }
  return;
}

