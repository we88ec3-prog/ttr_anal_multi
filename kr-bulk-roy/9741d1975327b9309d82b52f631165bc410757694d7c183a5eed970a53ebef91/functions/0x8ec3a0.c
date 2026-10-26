
uint FUN_008ec3a0(void)

{
  uint in_EAX;
  uint uVar1;
  uint uVar2;
  uint in_ECX;
  uint uVar3;
  uint uVar4;
  
  uVar4 = in_ECX ^ in_EAX;
  if ((int)in_ECX < 0) {
    in_ECX = -in_ECX;
  }
  if ((int)in_EAX < 0) {
    in_EAX = -in_EAX;
  }
  uVar1 = ((int)in_ECX >> 0x10 & 0xffffU) * in_EAX;
  uVar2 = uVar1 * 0x10000 + 0x2000;
  uVar3 = (in_ECX & 0xffff) * in_EAX + uVar2;
  uVar1 = uVar1 >> 0x10;
  if (uVar3 < uVar2) {
    uVar1 = uVar1 + 1;
  }
  uVar1 = uVar1 << 0x12 | uVar3 >> 0xe;
  if ((int)uVar4 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}

