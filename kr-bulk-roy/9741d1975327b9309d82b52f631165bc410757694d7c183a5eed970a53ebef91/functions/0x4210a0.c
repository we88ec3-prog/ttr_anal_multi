
void FUN_004210a0(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(*(int *)(in_ECX + 0x104) + 0x20) == *(int *)(param_1 + 8))) {
    FUN_00421260();
  }
  return;
}

