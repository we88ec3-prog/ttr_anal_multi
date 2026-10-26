
void FUN_004229c0(int param_1)

{
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(in_ECX[0x3e] + 0x20) == *(int *)(param_1 + 8)) {
      FUN_00422be0(in_ECX);
      return;
    }
    if (*(int *)(in_ECX[0x3f] + 0x20) == *(int *)(param_1 + 8)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  return;
}

