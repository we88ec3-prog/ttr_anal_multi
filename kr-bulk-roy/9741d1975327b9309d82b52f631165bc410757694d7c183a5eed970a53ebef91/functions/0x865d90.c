
bool FUN_00865d90(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(*(int *)(**(int **)(in_ECX + 0x5c) + 4) + 0xc + (int)*(int **)(in_ECX + 0x5c)) == 0)
  {
    iVar1 = FUN_00866280();
    if (iVar1 != 0) {
      iVar1 = FUN_008661d0();
      return iVar1 != 0;
    }
  }
  return false;
}

