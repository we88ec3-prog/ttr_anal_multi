
bool FUN_00717e80(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x5c) == 'r')) {
    if (*(int *)(iVar1 + 0x3c) != 0) {
      return true;
    }
    return *(int *)(iVar1 + 0x38) == 1;
  }
  return false;
}

