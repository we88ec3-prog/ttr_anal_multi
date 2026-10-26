
void FUN_00622190(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) == *(int *)(*(int *)(in_EAX + 0x104) + 0x20)) &&
     (iVar1 = *(int *)(*(int *)(in_EAX + 0x104) + 0x24c), iVar1 != 0)) {
    iVar1 = *(int *)(iVar1 + 0xcc);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
    }
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != -1)) {
      FUN_0061fab0();
      return;
    }
  }
  return;
}

