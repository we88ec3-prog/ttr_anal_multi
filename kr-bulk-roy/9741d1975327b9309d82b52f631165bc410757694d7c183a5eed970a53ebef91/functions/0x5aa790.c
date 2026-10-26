
void FUN_005aa790(int param_1)

{
  undefined4 in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0xf429d) {
    FUN_005aa820(in_ECX);
  }
  else if (*(int *)(param_1 + 0x10) == 0xf429e) {
    FUN_005aa870(in_ECX);
    FUN_005a44e0(param_1);
    return;
  }
  FUN_005a44e0(param_1);
  return;
}

