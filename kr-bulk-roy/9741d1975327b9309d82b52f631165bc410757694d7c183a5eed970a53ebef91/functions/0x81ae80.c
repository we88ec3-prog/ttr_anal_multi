
uint FUN_0081ae80(void)

{
  uint uVar1;
  int in_EAX;
  
  uVar1 = *(uint *)(in_EAX + 0x18);
  if (*(uint *)(in_EAX + 0x14) == uVar1) {
    return uVar1 & 0xffffff00;
  }
  return ((int)(uVar1 - *(uint *)(in_EAX + 0x14)) >> 2) - 1;
}

