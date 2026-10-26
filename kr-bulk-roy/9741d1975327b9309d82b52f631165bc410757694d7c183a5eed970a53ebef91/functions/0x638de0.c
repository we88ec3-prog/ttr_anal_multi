
void FUN_00638de0(int param_1)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    puVar1 = (undefined4 *)(in_ECX + 0xd8);
    iVar2 = 0x29;
    do {
      if (*(int *)(puVar1[-0x33] + 0x20) == *(int *)(param_1 + 8)) {
        (*(code *)*puVar1)();
      }
      puVar1 = puVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

