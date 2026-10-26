
void FUN_007aaa50(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 != 0) {
    FUN_007aa9a0(iVar1);
    FUN_0089120c(iVar1);
  }
  return;
}

