
void FUN_00872a50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  iVar2 = *(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x184) >> 2;
  if (1 < iVar2) {
    do {
      (**(code **)(**(int **)(*(int *)(in_ECX + 0x184) + iVar1 * 4) + 0x44))
                (param_1,param_2,param_3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  return;
}

