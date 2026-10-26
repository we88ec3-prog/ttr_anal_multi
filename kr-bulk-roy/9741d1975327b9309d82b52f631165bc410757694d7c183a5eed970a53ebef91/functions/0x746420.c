
uint FUN_00746420(void)

{
  uint uVar1;
  uint in_EAX;
  
  uVar1 = *(uint *)(in_EAX + 0x28);
  while( true ) {
    if ((uVar1 >> 8 & 1) == 0) {
      return in_EAX & 0xffffff00;
    }
    in_EAX = *(uint *)(in_EAX + 0x60);
    if (in_EAX == 0) break;
    uVar1 = *(uint *)(in_EAX + 0x28);
  }
  return 1;
}

