
void FUN_008bb620(undefined4 param_1)

{
  int iVar1;
  int unaff_EDI;
  
  if (unaff_EDI != 0) {
    iVar1 = 0;
    if (0 < *(int *)(unaff_EDI + 0x24)) {
      do {
        FUN_008ba7b0();
        *(undefined4 *)(*(int *)(unaff_EDI + 0x28) + iVar1 * 4) = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_EDI + 0x24));
    }
    FUN_008b9f80(param_1,*(undefined4 *)(unaff_EDI + 0x28));
    *(undefined4 *)(unaff_EDI + 0x28) = 0;
    *(undefined4 *)(unaff_EDI + 0x24) = 0;
  }
  return;
}

