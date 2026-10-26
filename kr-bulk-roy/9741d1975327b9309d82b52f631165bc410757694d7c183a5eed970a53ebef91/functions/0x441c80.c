
undefined4 FUN_00441c80(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0xf8) + 0x24c);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0xcc);
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

