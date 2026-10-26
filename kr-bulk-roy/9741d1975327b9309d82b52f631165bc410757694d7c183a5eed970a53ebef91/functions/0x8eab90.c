
void FUN_008eab90(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x68);
  FUN_008b9f80(*(undefined4 *)(iVar1 + 0x1c),*(undefined4 *)(in_EAX + 0x2d0));
  *(undefined4 *)(in_EAX + 0x2d0) = 0;
  FUN_008bab90(iVar1,in_EAX + 0x2c0);
  return;
}

