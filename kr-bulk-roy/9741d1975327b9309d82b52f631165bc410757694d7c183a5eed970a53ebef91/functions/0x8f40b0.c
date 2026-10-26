
uint FUN_008f40b0(void)

{
  uint in_EAX;
  int in_ECX;
  
  if (in_EAX < *(uint *)(in_ECX + 4)) {
    return *(byte *)(*(int *)(in_ECX + 8) + in_EAX) & 0x80;
  }
  return in_EAX & 0xffffff00;
}

