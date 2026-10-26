
int FUN_008ce7e0(void)

{
  int iVar1;
  int iVar2;
  uint unaff_ESI;
  uint unaff_EDI;
  
  iVar2 = (unaff_ESI ^ (int)unaff_ESI >> 0x1f) - ((int)unaff_ESI >> 0x1f);
  iVar1 = (unaff_EDI ^ (int)unaff_EDI >> 0x1f) - ((int)unaff_EDI >> 0x1f);
  if (iVar1 * 0xc < iVar2) {
    return (uint)(-1 < (int)unaff_ESI) * 4 + -2;
  }
  if (iVar2 * 0xc < iVar1) {
    return (uint)((int)unaff_EDI < 0) * 2 + -1;
  }
  return 4;
}

