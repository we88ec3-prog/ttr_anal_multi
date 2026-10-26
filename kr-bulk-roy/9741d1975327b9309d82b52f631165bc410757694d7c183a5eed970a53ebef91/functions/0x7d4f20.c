
void FUN_007d4f20(void)

{
  int in_ECX;
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28) >> 2;
  if (uVar2 != 0) {
    do {
      (**(code **)(**(int **)(*(int *)(in_ECX + 0x28) + uVar1 * 4) + 0x18))();
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  return;
}

