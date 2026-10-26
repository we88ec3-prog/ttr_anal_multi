
void FUN_0064e660(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
      FUN_0064e6c0(*(char *)(in_ECX + 0x104) == '\0');
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
      FUN_0064e970((byte)(*(uint *)(*(int *)(in_ECX + 0x100) + 0x28) >> 9) & 1);
    }
  }
  return;
}

