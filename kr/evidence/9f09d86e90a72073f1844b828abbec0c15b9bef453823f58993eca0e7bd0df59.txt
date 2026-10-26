
void FUN_00500110(void)

{
  int iVar1;
  ushort *puVar2;
  short *psVar3;
  uint unaff_ESI;
  int unaff_EDI;
  
  iVar1 = 0;
  puVar2 = (ushort *)(unaff_EDI + 0x5ed0);
  do {
    if (*puVar2 == unaff_ESI) {
      return;
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x14);
  iVar1 = 0;
  psVar3 = (short *)(unaff_EDI + 0x5ed0);
  do {
    if (*psVar3 == 0) {
      *(short *)(unaff_EDI + 0x5ed0 + iVar1 * 2) = (short)unaff_ESI;
      return;
    }
    iVar1 = iVar1 + 1;
    psVar3 = psVar3 + 1;
  } while (iVar1 < 0x14);
  return;
}

