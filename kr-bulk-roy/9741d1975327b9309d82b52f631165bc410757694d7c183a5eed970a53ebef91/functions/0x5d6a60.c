
void FUN_005d6a60(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x110) + 0x20)) {
      FUN_005d5fd0();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) {
      FUN_005d6020();
    }
  }
  else if ((*(int *)(param_1 + 0x10) == 0x641) &&
          (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x104) + 0x20))) {
    FUN_005d6240();
    return;
  }
  return;
}

