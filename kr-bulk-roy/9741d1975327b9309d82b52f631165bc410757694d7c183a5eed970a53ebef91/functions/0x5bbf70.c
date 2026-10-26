
void FUN_005bbf70(void)

{
  int in_ECX;
  
  if ((*(uint *)(*(int *)(in_ECX + 0x2e0) + 0x28) >> 8 & 1) == 0) {
    FUN_00596e00(in_ECX,*(int *)(in_ECX + 0x2e0));
  }
  return;
}

