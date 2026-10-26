
undefined4 FUN_0075cdb0(void)

{
  int iVar1;
  int in_EAX;
  
  if ((*(int *)(in_EAX + 0x24c) != 0) &&
     (iVar1 = *(int *)(*(int *)(in_EAX + 0x24c) + 0xcc), iVar1 != 0)) {
    return *(undefined4 *)(iVar1 + 0xdc);
  }
  return 0;
}

