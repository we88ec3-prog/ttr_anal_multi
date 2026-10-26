
void FUN_0076b1a0(int param_1)

{
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == 1) {
      (**(code **)(*in_ECX + 0x184))();
      return;
    }
    if (*(int *)(param_1 + 8) == 2) {
      (**(code **)(*in_ECX + 0x188))();
    }
  }
  return;
}

