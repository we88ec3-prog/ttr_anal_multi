
uint FUN_008ce310(void)

{
  int in_EAX;
  uint uVar1;
  int in_EDX;
  uint uVar2;
  
  uVar1 = ((in_EAX + 0x20 + in_EDX & 0xffffffc0U) - in_EAX) - in_EDX;
  uVar2 = (in_EAX + 0x20U & 0xffffffc0) - in_EAX;
  if ((int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) <
      (int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f))) {
    uVar2 = uVar1;
  }
  return uVar2;
}

