
void FUN_005b3d90(int param_1)

{
  int in_ECX;
  
  FUN_005b7750(param_1);
  if (*(int *)(param_1 + 0x10) == 0xf42e7) {
    if ((*(uint *)(*(int *)(in_ECX + 0x304) + 0x28) >> 8 & 1) == 0) {
      FUN_00596e00(in_ECX,*(int *)(in_ECX + 0x304));
    }
  }
  else if (*(int *)(param_1 + 0x10) != 0xf42e8) {
    return;
  }
  FUN_00428210(1);
  return;
}

