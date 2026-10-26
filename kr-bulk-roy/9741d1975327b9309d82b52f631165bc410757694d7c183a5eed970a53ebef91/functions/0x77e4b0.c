
void FUN_0077e4b0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (*(int *)(iVar1 + 0x208) != 0) {
    (**(code **)(**(int **)(iVar1 + 0x208) + 0x108))(*(int **)(iVar1 + 0x208));
    (**(code **)(**(int **)(iVar1 + 0x208) + 0x10c))(*(int **)(iVar1 + 0x208));
  }
  return;
}

