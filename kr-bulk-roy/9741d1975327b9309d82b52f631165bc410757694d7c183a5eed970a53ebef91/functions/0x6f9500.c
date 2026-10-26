
void FUN_006f9500(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI + 1U < 0x10000000) {
    uVar1 = FUN_00700880();
  }
  else {
    uVar1 = FUN_00700860();
  }
  iVar3 = *(int *)(unaff_ESI + 0x1c);
  *(undefined4 *)(unaff_ESI + 0xc) = uVar1;
  if (iVar3 < unaff_EDI) {
    iVar2 = iVar3 << 4;
    iVar3 = unaff_EDI - iVar3;
    do {
      *(undefined4 *)(*(int *)(unaff_ESI + 0xc) + 8 + iVar2) = 0;
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *(int *)(unaff_ESI + 0x1c) = unaff_EDI;
  return;
}

