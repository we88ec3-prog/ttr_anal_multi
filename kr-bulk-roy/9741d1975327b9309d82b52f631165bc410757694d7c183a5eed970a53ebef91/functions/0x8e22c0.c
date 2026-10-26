
void FUN_008e22c0(void)

{
  char cVar1;
  uint in_EAX;
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0xc) < in_EAX) && (cVar1 = FUN_008e2230(), cVar1 == '\0')) {
    return;
  }
  *(uint *)(in_ECX + 0x14) = in_EAX;
  return;
}

