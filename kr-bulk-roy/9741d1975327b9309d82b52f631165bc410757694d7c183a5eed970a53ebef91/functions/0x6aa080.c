
void FUN_006aa080(int param_1)

{
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_006a9f70(in_ECX);
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  return;
}

