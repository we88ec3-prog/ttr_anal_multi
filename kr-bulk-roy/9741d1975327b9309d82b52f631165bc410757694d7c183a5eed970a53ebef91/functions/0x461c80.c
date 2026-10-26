
void FUN_00461c80(int param_1)

{
  int in_ECX;
  
  FUN_005d6fb0(param_1);
  if (*(int *)(param_1 + 0x10) == 0x7c) {
    if (*(int *)(param_1 + 4) == *(int *)(*(int *)(*(int *)(in_ECX + 0x298) + 0xf8) + 0x20)) {
      FUN_00481730();
      return;
    }
    if (*(int *)(param_1 + 4) == *(int *)(*(int *)(*(int *)(in_ECX + 0x298) + 0xfc) + 0x20)) {
      FUN_00481650();
    }
  }
  return;
}

