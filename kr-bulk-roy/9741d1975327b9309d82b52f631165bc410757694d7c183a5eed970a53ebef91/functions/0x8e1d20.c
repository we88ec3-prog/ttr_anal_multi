
uint FUN_008e1d20(void)

{
  uint in_EAX;
  int in_EDX;
  
  if (0x60 < in_EAX) {
    FUN_008e0760();
    return 0;
  }
  *(uint *)(in_EDX + 8) = in_EAX;
  *(uint *)(in_EDX + 0xc) = in_EAX + 7 >> 3;
  *(undefined2 *)(in_EDX + 4) = 0x101;
  return in_EAX;
}

