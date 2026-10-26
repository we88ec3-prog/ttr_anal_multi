
void FUN_006a9bd0(int param_1)

{
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x40] + 0x20)) {
      FUN_006a9a90();
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x41] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  return;
}

