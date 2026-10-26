
void FUN_00559d10(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x28) != 0) {
    FUN_0049bf30();
    FUN_0089120c(*(undefined4 *)(in_EAX + 0x28));
  }
  *(undefined4 *)(in_EAX + 0x28) = 0;
  *(undefined4 *)(in_EAX + 0x2c) = 0;
  *(undefined4 *)(in_EAX + 0x30) = 0;
  FUN_0046fba0();
  FUN_0089120c(*(undefined4 *)(in_EAX + 0x10));
  *(undefined4 *)(in_EAX + 0x10) = 0;
  return;
}

