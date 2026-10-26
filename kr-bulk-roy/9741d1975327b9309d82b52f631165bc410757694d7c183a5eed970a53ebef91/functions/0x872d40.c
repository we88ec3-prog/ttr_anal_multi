
void FUN_00872d40(undefined4 param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  FUN_00844af0(param_1);
  iVar2 = 1;
  iVar1 = *(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x184) >> 2;
  if (1 < iVar1) {
    do {
      (**(code **)(**(int **)(*(int *)(in_ECX + 0x184) + iVar2 * 4) + 0x1c))(param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}

