
void FUN_00730d00(void)

{
  int in_EAX;
  
  *(int *)(in_EAX + 0x20) = in_EAX + 0x18;
  *(int *)(in_EAX + 0x24) = in_EAX + 0x1c;
  *(int *)(in_EAX + 0x10) = in_EAX + 8;
  *(int *)(in_EAX + 0x30) = in_EAX + 0x28;
  *(undefined4 **)(in_EAX + 0x14) = (undefined4 *)(in_EAX + 0xc);
  *(int *)(in_EAX + 0x34) = in_EAX + 0x2c;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  **(undefined4 **)(in_EAX + 0x24) = 0;
  **(undefined4 **)(in_EAX + 0x34) = 0;
  **(undefined4 **)(in_EAX + 0x10) = 0;
  **(undefined4 **)(in_EAX + 0x20) = 0;
  **(undefined4 **)(in_EAX + 0x30) = 0;
  return;
}

