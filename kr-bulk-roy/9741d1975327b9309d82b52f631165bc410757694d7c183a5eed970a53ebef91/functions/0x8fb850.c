
int FUN_008fb850(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  *(int *)(unaff_EDI + 0x204c) = unaff_EDI + 0x1048;
  *(int *)(unaff_EDI + 0x18) = unaff_EDI + 0x1048;
  *(undefined4 *)(unaff_EDI + 0x1c) = 0x1000;
  iVar2 = 0;
  while( true ) {
    if ((*(int *)(unaff_EDI + 0x10) == 0) && (iVar2 = FUN_008fb7d0(), iVar2 != 0)) {
      return iVar2;
    }
    iVar1 = FUN_008fb0b0(0);
    if (iVar1 == 1) {
      *(int *)(unaff_EDI + 0x2050) = *(int *)(unaff_EDI + 0x18);
      if (*(int *)(unaff_EDI + 0x18) != *(int *)(unaff_EDI + 0x204c)) {
        return iVar2;
      }
      return 0x55;
    }
    if (iVar1 != 0) break;
    if (*(int *)(unaff_EDI + 0x1c) == 0) {
      return iVar2;
    }
  }
  return 0x55;
}

