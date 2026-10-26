
void FUN_00626ed0(void)

{
  int iVar1;
  int unaff_EDI;
  
  if ((*(int *)(*(int *)(unaff_EDI + 0xf8) + 0xcc) != 0) &&
     (*(int *)(*(int *)(unaff_EDI + 0xf8) + 0xd8) != 0)) {
    iVar1 = FUN_005f55a0();
    if (iVar1 != -1) {
      *(int *)(*(int *)(unaff_EDI + 0x10c + iVar1 * 4) + 0x114) = iVar1;
      FUN_0062b1d0();
    }
    if (iVar1 == 3) {
      FUN_0062b1d0();
      return;
    }
  }
  return;
}

