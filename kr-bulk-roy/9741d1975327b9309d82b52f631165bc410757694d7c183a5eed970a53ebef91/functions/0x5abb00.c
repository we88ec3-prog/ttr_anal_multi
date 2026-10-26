
void FUN_005abb00(int param_1)

{
  int *in_ECX;
  
  FUN_005a44e0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf426c) {
    (**(code **)(*in_ECX + 0x1a4))();
  }
  if (*(int *)(param_1 + 0x10) == 0xf426b) {
    FUN_005abc50();
  }
  return;
}

