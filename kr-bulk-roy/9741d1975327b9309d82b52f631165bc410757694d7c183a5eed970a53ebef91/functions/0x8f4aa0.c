
void FUN_008f4aa0(void)

{
  uint in_EAX;
  int *piVar1;
  int iVar2;
  uint unaff_EBX;
  int iVar3;
  uint unaff_EDI;
  
  iVar3 = *(int *)(unaff_EDI + 0x18) - *(int *)(unaff_EDI + 0x1c);
  if (iVar3 != 0) {
    if (in_EAX < unaff_EDI) {
      piVar1 = (int *)(in_EAX + 0x18);
      iVar2 = ((unaff_EDI - in_EAX) - 1) / 0x28 + 1;
      do {
        *piVar1 = piVar1[1] + iVar3;
        piVar1 = piVar1 + 10;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    while (unaff_EDI + 0x28 <= unaff_EBX) {
      *(int *)(unaff_EDI + 0x40) = *(int *)(unaff_EDI + 0x44) + iVar3;
      unaff_EDI = unaff_EDI + 0x28;
    }
  }
  return;
}

