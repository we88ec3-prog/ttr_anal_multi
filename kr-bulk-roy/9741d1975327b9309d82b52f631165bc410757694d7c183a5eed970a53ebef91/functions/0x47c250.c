
uint FUN_0047c250(void)

{
  uint uVar1;
  uint in_EAX;
  int in_EDX;
  
  uVar1 = *(uint *)(in_EDX + 4);
  while( true ) {
    if (uVar1 == 0) {
      return in_EAX & 0xffffff00;
    }
    LOCK();
    in_EAX = *(uint *)(in_EDX + 4);
    if (uVar1 == in_EAX) {
      *(uint *)(in_EDX + 4) = uVar1 + 1;
      in_EAX = uVar1;
    }
    UNLOCK();
    if (in_EAX == uVar1) break;
    uVar1 = *(uint *)(in_EDX + 4);
  }
  return CONCAT31((int3)(in_EAX >> 8),1);
}

