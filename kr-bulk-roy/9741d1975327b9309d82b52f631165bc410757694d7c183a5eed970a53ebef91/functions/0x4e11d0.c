
void FUN_004e11d0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 != 0) {
    FUN_0082f580(iVar1);
    FUN_0089120c(iVar1);
  }
  return;
}

