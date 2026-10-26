
undefined4 FUN_0075cdd0(void)

{
  int in_EAX;
  int iVar1;
  
  if (*(int *)(in_EAX + 0x24c) != 0) {
    iVar1 = *(int *)(*(int *)(in_EAX + 0x24c) + 0xcc);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
    }
    if (iVar1 != 0) {
      return *(undefined4 *)(iVar1 + 0x20);
    }
  }
  return 0xffffffff;
}

