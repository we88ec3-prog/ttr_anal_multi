
void FUN_007f2ae0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x84);
  if (iVar1 != 0) {
    FUN_007d8890(iVar1);
    FUN_0089120c(iVar1);
    *(undefined4 *)(in_ECX + 0x84) = 0;
  }
  return;
}

