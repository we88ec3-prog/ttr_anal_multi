
void FUN_007eede0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = *(int *)(unaff_ESI + 8) - *(int *)(unaff_ESI + 4) >> 4;
  if (iVar2 != 0) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(*(int *)(unaff_ESI + 4) + 4 + iVar3);
      if (*(int *)(*(int *)(unaff_ESI + 4) + 0xc + iVar3) == unaff_EDI) {
        *(undefined4 *)(iVar1 + 0x70) = 0;
      }
      else {
        *(undefined4 *)(iVar1 + 0x70) = 1;
      }
      iVar3 = iVar3 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

