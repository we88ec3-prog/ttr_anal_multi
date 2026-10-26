
void FUN_005b1bd0(int param_1)

{
  int in_ECX;
  
  FUN_005b7c50(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf4249) {
    if ((*(uint *)(*(int *)(in_ECX + 0x304) + 0x28) >> 8 & 1) != 0) {
      FUN_0066f750(*(int *)(in_ECX + 0x304));
    }
  }
  else if ((*(int *)(param_1 + 0x10) == 0xf424a) &&
          ((*(uint *)(*(int *)(in_ECX + 0x300) + 0x28) >> 8 & 1) != 0)) {
    FUN_00670d90();
    return;
  }
  return;
}

