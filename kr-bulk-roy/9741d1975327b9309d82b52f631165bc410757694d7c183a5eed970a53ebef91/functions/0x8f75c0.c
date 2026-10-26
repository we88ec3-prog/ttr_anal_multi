
void FUN_008f75c0(void)

{
  undefined4 uVar1;
  int in_EAX;
  
  uVar1 = **(undefined4 **)(in_EAX + 4);
  _memset((void *)(in_EAX + 0x14),0,0xb4);
  FUN_008f42a0(uVar1);
  FUN_008bb050(uVar1,in_EAX + 0x1c);
  return;
}

