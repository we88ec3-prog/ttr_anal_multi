
void FUN_00872aa0(undefined4 param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  iVar2 = *(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x184) >> 2;
  if (1 < iVar2) {
    do {
      (**(code **)(**(int **)(*(int *)(in_ECX + 0x184) + iVar1 * 4) + 0x48))(param_1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  return;
}

