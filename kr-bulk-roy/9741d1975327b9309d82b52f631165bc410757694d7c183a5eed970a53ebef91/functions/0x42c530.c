
undefined4 FUN_0042c530(void)

{
  int iVar1;
  int in_EAX;
  
  if ((*(int *)(in_EAX + 0xcc) != 0) &&
     (iVar1 = *(int *)(*(int *)(in_EAX + 0xcc) + 0xdc), iVar1 != 0)) {
    return *(undefined4 *)(iVar1 + 0x20);
  }
  return 0xffffffff;
}

