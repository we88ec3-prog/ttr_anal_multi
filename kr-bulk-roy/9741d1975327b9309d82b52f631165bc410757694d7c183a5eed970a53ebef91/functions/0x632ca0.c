
undefined4 FUN_00632ca0(void)

{
  int iVar1;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x144) != 0) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)(in_EAX + 0x124) + 0xcc);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 != 0)) {
    return *(undefined4 *)(iVar1 + 0x20);
  }
  return 0xffffffff;
}

