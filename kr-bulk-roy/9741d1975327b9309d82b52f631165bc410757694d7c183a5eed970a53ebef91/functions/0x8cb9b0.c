
void FUN_008cb9b0(void)

{
  int iVar1;
  int *in_ECX;
  int in_EDX;
  
  iVar1 = *in_ECX;
  if (iVar1 != 0) {
    while (iVar1 != in_EDX) {
      in_ECX = (int *)(iVar1 + 4);
      iVar1 = *in_ECX;
      if (iVar1 == 0) {
        return;
      }
    }
    *in_ECX = *(int *)(iVar1 + 4);
  }
  return;
}

