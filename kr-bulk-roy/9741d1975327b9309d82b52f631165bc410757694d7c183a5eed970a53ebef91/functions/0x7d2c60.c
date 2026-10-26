
void FUN_007d2c60(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    iVar1 = *(int *)(in_ECX + 0x18);
    uVar2 = 0;
    if (*(int *)(in_ECX + 0x1c) - iVar1 >> 2 != 0) {
      do {
        (**(code **)(**(int **)(iVar1 + uVar2 * 4) + 0x2c))();
        iVar1 = *(int *)(in_ECX + 0x18);
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)(*(int *)(in_ECX + 0x1c) - iVar1 >> 2));
    }
  }
  return;
}

