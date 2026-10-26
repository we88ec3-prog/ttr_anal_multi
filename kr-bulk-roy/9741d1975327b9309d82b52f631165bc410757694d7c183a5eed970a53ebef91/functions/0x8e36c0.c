
void FUN_008e36c0(void)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int unaff_EDI;
  
  iVar2 = FUN_008e1d20();
  if ((iVar2 != 0) && (uVar3 = 0, *(int *)(unaff_EDI + 0xc) != 0)) {
    do {
      uVar1 = FUN_008e1d90();
      *(undefined1 *)(unaff_EDI + 0x10 + uVar3) = uVar1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(unaff_EDI + 0xc));
  }
  return;
}

