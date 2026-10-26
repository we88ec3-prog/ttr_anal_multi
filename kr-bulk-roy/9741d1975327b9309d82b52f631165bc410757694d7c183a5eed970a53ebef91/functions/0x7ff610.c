
void FUN_007ff610(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  iVar1 = *(int *)(in_ECX + 0x24);
  uVar3 = 0;
  if (*(int *)(iVar1 + 0x60) - *(int *)(iVar1 + 0x5c) >> 2 != 0) {
    do {
      iVar2 = *(int *)(*(int *)(iVar1 + 0x5c) + uVar3 * 4);
      (**(code **)(**(int **)(iVar2 + 8) + 0x1c))(iVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(iVar1 + 0x60) - *(int *)(iVar1 + 0x5c) >> 2));
  }
  return;
}

