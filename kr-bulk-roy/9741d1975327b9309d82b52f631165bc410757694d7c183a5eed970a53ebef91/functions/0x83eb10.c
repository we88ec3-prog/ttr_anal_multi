
int FUN_0083eb10(void)

{
  uint uVar1;
  uint *in_EAX;
  uint uVar2;
  int unaff_EDI;
  
  uVar1 = *in_EAX;
  if (uVar1 == 0) {
    return 0;
  }
  uVar2 = uVar1 & 0xffff;
  if ((uVar2 < (uint)((*(int *)(unaff_EDI + 0x14) - *(int *)(unaff_EDI + 0x10)) / 0x34)) &&
     (*(uint *)(*(int *)(unaff_EDI + 0x20) + uVar2 * 4) == uVar1 >> 0x10)) {
    return *(int *)(unaff_EDI + 0x10) + uVar2 * 0x34;
  }
  return 0;
}

