
void FUN_005abb40(int param_1)

{
  int *in_ECX;
  
  FUN_005a4310(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf439f) {
    (**(code **)(*in_ECX + 0x1ac))();
    return;
  }
  if (*(int *)(param_1 + 0x10) == 0xf43a0) {
    (**(code **)(*in_ECX + 0x1a8))(param_1);
  }
  return;
}

