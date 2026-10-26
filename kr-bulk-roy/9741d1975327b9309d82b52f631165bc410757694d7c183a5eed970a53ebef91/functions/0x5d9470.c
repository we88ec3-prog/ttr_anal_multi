
void FUN_005d9470(int param_1)

{
  int in_ECX;
  
  FUN_005d6fb0(param_1);
  if (*(int *)(param_1 + 0x10) == 0x7c) {
    if (*(int *)(in_ECX + 0x2a0) == 0) {
      FUN_0067f1f0(0);
      FUN_0067f1f0(1);
      FUN_0067f1f0(2);
      return;
    }
    FUN_0067f1f0(*(int *)(in_ECX + 0x2a0));
  }
  return;
}

