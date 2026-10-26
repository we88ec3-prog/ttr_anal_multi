
void FUN_0082d6a0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x38;
  if (iVar2 != 0) {
    iVar1 = 0;
    do {
      *(undefined4 *)(iVar1 + 0x30 + *(int *)(in_ECX + 0x10)) = 0;
      *(undefined4 *)(iVar1 + 0x34 + *(int *)(in_ECX + 0x10)) = 0;
      iVar1 = iVar1 + 0x38;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

