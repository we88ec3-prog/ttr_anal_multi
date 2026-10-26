
void FUN_008b7d00(void)

{
  uint in_EAX;
  uint uVar1;
  uint in_ECX;
  uint uVar2;
  uint uVar3;
  uint *unaff_EBX;
  
  uVar2 = (in_ECX & 0xffff) * (in_EAX >> 0x10);
  uVar1 = (in_ECX >> 0x10) * (in_EAX & 0xffff) + uVar2;
  uVar3 = (in_ECX & 0xffff) * (in_EAX & 0xffff) + uVar1 * 0x10000;
  *unaff_EBX = uVar3;
  unaff_EBX[1] = (uint)(uVar3 < uVar1 * 0x10000) +
                 (uint)(uVar1 < uVar2) * 0x10000 + (in_ECX >> 0x10) * (in_EAX >> 0x10) +
                 (uVar1 >> 0x10);
  return;
}

