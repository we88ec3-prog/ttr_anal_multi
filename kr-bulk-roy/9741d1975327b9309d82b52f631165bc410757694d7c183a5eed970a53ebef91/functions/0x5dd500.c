
void FUN_005dd500(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x24);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 0x25c) != 0) &&
       (((iVar2 = *(int *)(*(int *)(in_ECX + 0x25c) + 8), iVar2 == 0x10 || (iVar2 == 0x1c)) ||
        (iVar2 == 0x19)))) {
      *(undefined4 *)(iVar1 + 0x14c0) = 0x65;
      return;
    }
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x14c0) = 1;
    }
  }
  return;
}

