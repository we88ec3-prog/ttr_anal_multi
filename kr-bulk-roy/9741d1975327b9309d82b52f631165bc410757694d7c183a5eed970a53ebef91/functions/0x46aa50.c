
int FUN_0046aa50(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0xcc);
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2;
  }
  return 0;
}

