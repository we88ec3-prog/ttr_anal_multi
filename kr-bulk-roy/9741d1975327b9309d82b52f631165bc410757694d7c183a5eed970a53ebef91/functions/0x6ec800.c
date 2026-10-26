
void FUN_006ec800(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = 0;
  if (0 < *(int *)(unaff_EDI + 0x58)) {
    do {
      iVar1 = *(int *)(*(int *)(unaff_EDI + 0x54) + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_006eca30();
        FUN_0089120c(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(unaff_EDI + 0x58));
  }
  if (*(void **)(unaff_EDI + 0x54) != (void *)0x0) {
    _free(*(void **)(unaff_EDI + 0x54));
    *(undefined4 *)(unaff_EDI + 0x54) = 0;
  }
  *(undefined4 *)(unaff_EDI + 0x58) = 0;
  *(undefined4 *)(unaff_EDI + 0x5c) = 0;
  return;
}

