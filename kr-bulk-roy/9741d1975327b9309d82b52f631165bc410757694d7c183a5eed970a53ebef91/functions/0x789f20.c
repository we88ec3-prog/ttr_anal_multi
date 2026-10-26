
void FUN_00789f20(void)

{
  int in_EAX;
  int in_ECX;
  
  if ((undefined4 *)(in_EAX + 4) != (undefined4 *)(in_ECX + 4)) {
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(in_EAX + 4) = *(undefined4 *)(in_ECX + 4);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_ECX + 8);
    *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(in_ECX + 0xc);
  }
  *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  if ((undefined4 *)(in_EAX + 0x1c) != (undefined4 *)(in_ECX + 0x1c)) {
    *(undefined4 *)(in_EAX + 0x28) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
    *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
  }
  if ((undefined4 *)(in_EAX + 0x2c) != (undefined4 *)(in_ECX + 0x2c)) {
    *(undefined4 *)(in_EAX + 0x38) = *(undefined4 *)(in_ECX + 0x38);
    *(undefined4 *)(in_EAX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(in_ECX + 0x30);
    *(undefined4 *)(in_EAX + 0x34) = *(undefined4 *)(in_ECX + 0x34);
  }
  return;
}

