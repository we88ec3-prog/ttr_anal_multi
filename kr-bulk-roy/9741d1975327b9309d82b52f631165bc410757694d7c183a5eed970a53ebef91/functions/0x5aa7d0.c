
void FUN_005aa7d0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0xf4304) {
    (**(code **)(**(int **)(in_ECX + 0x168) + 0xd0))();
  }
  if (*(int *)(param_1 + 0x10) == 0xf431d) {
    FUN_005a59e0();
  }
  else if (*(int *)(param_1 + 0x10) == 0xf4328) {
    FUN_005a57d0();
    return;
  }
  return;
}

