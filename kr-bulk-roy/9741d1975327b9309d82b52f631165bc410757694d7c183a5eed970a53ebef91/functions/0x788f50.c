
void FUN_00788f50(void)

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
  *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
  *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(in_ECX + 0x24);
  *(undefined4 *)(in_EAX + 0x28) = *(undefined4 *)(in_ECX + 0x28);
  *(undefined4 *)(in_EAX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  if ((undefined4 *)(in_EAX + 0x30) != (undefined4 *)(in_ECX + 0x30)) {
    *(undefined4 *)(in_EAX + 0x3c) = *(undefined4 *)(in_ECX + 0x3c);
    *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(in_ECX + 0x30);
    *(undefined4 *)(in_EAX + 0x34) = *(undefined4 *)(in_ECX + 0x34);
    *(undefined4 *)(in_EAX + 0x38) = *(undefined4 *)(in_ECX + 0x38);
  }
  if ((undefined4 *)(in_EAX + 0x40) != (undefined4 *)(in_ECX + 0x40)) {
    *(undefined4 *)(in_EAX + 0x4c) = *(undefined4 *)(in_ECX + 0x4c);
    *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(in_ECX + 0x40);
    *(undefined4 *)(in_EAX + 0x44) = *(undefined4 *)(in_ECX + 0x44);
    *(undefined4 *)(in_EAX + 0x48) = *(undefined4 *)(in_ECX + 0x48);
  }
  return;
}

