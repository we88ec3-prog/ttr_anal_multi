
void FUN_0063f7b0(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0xf43c6) {
    if (uVar1 == 0xf43c5) {
      FUN_006c6050();
      return;
    }
    if (uVar1 == 0x578) {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == (*(int **)(in_ECX + 0x110))[8]) {
        (**(code **)(**(int **)(in_ECX + 0x110) + 0xa0))(1);
        if (*(int *)(*(int *)(in_ECX + 0xfc) + 0xcc) != 0) {
          FUN_0042c8e0(0xffffffff);
        }
      }
      else {
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
          FUN_0063f9e0();
          return;
        }
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
          FUN_004054c0();
          FUN_0058aad0(0xf42fc);
          return;
        }
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
          FUN_0063f8a0();
          return;
        }
      }
    }
    else if (uVar1 == 0x70b) {
      (**(code **)(**(int **)(in_ECX + 0x110) + 0xa0))(0);
      return;
    }
  }
  else if (uVar1 == 0xf43c6) {
    FUN_0063ffa0();
    return;
  }
  return;
}

