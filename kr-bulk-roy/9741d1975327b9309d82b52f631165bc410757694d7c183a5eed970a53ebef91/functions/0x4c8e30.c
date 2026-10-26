
void FUN_004c8e30(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x15c);
  if ((iVar1 != 0) && (*(int *)(in_ECX + 0x370) != 0)) {
    if (*(int *)(iVar1 + 0xac) != 0) {
      (**(code **)(**(int **)(iVar1 + 0xac) + 0xc))();
      return;
    }
    return;
  }
  return;
}

