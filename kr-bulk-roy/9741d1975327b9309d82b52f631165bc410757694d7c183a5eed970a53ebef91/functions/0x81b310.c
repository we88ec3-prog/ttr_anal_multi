
bool FUN_0081b310(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (iVar1 = **(int **)(*(int *)(param_1 + 0xc) + 8), iVar1 != 0)) {
    return (1 << (*(byte *)(iVar1 + 4) & 0x1f) & *(uint *)(in_ECX + 8)) != 0;
  }
  return false;
}

