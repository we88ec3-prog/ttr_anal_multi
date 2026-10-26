
void FUN_005095f0(void)

{
  int iVar1;
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x50dc) = 0;
  FUN_00797a00();
  iVar1 = *(int *)(in_EAX + 0x50e0);
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  *(int *)(in_EAX + 0x50e0) = 0;
  *(undefined4 *)(in_EAX + 0x50e4) = 0;
  *(undefined4 *)(in_EAX + 0x50e8) = 0;
  FUN_007b6d70();
  FUN_0089120c(*(undefined4 *)(in_EAX + 0x50c0));
  *(undefined4 *)(in_EAX + 0x50c0) = 0;
  return;
}

