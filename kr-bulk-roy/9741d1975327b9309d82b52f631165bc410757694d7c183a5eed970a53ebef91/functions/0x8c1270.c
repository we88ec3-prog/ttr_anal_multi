
void FUN_008c1270(void)

{
  int in_EAX;
  undefined4 in_ECX;
  undefined4 in_EDX;
  
  *(undefined4 *)(in_EAX + 0x528) = in_ECX;
  *(undefined4 *)(in_EAX + 0x530) = in_ECX;
  *(undefined4 *)(in_EAX + 0x52c) = in_EDX;
  *(undefined4 *)(in_EAX + 0x2c) = 0;
  *(undefined4 *)(in_EAX + 0x30) = 0;
  *(undefined4 *)(in_EAX + 0x34) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  *(undefined4 *)(in_EAX + 0x24) = 0;
  *(undefined4 *)(in_EAX + 0x28) = 1;
  return;
}

