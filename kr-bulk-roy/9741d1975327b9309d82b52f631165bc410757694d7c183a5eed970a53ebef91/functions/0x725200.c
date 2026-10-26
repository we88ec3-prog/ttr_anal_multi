
int FUN_00725200(void)

{
  uint *puVar1;
  uint *in_EAX;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  puVar1 = in_EAX + in_ECX;
  iVar2 = 0;
  for (; in_EAX < puVar1; in_EAX = in_EAX + 1) {
    uVar3 = *in_EAX;
    uVar3 = (uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8 | (uVar3 & 0xff00 | uVar3 << 0x10) << 8;
    if (uVar3 < 0x10000) {
      if (uVar3 < 0x80) {
        iVar2 = iVar2 + 1;
      }
      else if (uVar3 < 0x800) {
        iVar2 = iVar2 + 2;
      }
      else {
        iVar2 = iVar2 + 3;
      }
    }
    else {
      iVar2 = iVar2 + 4;
    }
  }
  return iVar2;
}

