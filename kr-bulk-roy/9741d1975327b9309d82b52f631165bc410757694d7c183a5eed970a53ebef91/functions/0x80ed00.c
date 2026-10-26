
undefined4 FUN_0080ed00(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x14))();
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

