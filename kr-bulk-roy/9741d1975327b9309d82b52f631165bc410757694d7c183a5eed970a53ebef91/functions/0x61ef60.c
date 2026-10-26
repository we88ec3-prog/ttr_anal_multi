
void FUN_0061ef60(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x76c) {
    FUN_0061f010();
  }
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
      FUN_00621930(*(undefined4 *)(in_ECX + 0xf8));
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
      FUN_0061ff40(*(undefined4 *)(in_ECX + 0xf8));
    }
  }
  return;
}

