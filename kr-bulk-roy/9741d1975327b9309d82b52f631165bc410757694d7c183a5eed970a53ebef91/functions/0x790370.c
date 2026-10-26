
void FUN_00790370(void)

{
  int in_EAX;
  int in_ECX;
  
  *(undefined4 *)(in_EAX + -0x14) = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_EAX + -0x10) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_EAX + -0xc) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_EAX + -8) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(in_EAX + -4) = *(undefined4 *)(in_ECX + 0x14);
  FUN_0078f9c0();
  return;
}

