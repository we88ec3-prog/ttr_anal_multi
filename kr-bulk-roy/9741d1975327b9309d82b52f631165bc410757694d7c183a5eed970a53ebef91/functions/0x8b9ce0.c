
int FUN_008b9ce0(void)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = (in_EAX ^ (int)in_EAX >> 0x1f) - ((int)in_EAX >> 0x1f);
  uVar4 = uVar1 & 0xffff;
  uVar1 = uVar1 >> 0x10;
  uVar3 = uVar4 * 0xdbd9 + uVar1 * 0x5b16;
  uVar5 = uVar4 * 0x5b16 >> 0x10;
  uVar4 = uVar3;
  if (uVar3 <= uVar5) {
    uVar4 = uVar5;
  }
  iVar2 = uVar1 * 0xdbd9 + (uVar3 + uVar5 >> 0x10);
  if (uVar3 + uVar5 < uVar4) {
    iVar2 = iVar2 + 0x10000;
  }
  if ((int)in_EAX < 0) {
    iVar2 = -iVar2;
  }
  return iVar2;
}

