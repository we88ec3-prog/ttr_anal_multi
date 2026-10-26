
void FUN_005b1b30(int param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_005b7750(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xf42d9) {
    iVar1 = **(int **)(in_ECX + 0x300);
    if (((uint)(*(int **)(in_ECX + 0x300))[10] >> 8 & 1) != 0) {
      (**(code **)(iVar1 + 0xd4))();
      return;
    }
    (**(code **)(iVar1 + 0xd0))();
  }
  else {
    if (iVar1 == 0xf42da) {
      iVar1 = **(int **)(in_ECX + 0x304);
      if (((uint)(*(int **)(in_ECX + 0x304))[10] >> 8 & 1) != 0) {
        (**(code **)(iVar1 + 0xd4))();
        return;
      }
      (**(code **)(iVar1 + 0xd0))();
      return;
    }
    if (iVar1 == 0xf42e7) {
      FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x30c));
      return;
    }
  }
  return;
}

