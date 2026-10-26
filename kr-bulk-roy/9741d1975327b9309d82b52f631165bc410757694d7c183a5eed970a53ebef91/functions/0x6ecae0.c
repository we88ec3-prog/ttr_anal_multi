
void FUN_006ecae0(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = 0;
  if (0 < *(int *)(unaff_EDI + 0x13c)) {
    do {
      iVar1 = *(int *)(*(int *)(unaff_EDI + 0x138) + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_006ec530();
        FUN_0089120c(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(unaff_EDI + 0x13c));
  }
  if (*(void **)(unaff_EDI + 0x138) != (void *)0x0) {
    _free(*(void **)(unaff_EDI + 0x138));
    *(undefined4 *)(unaff_EDI + 0x138) = 0;
  }
  *(undefined4 *)(unaff_EDI + 0x140) = 0;
  *(undefined4 *)(unaff_EDI + 0x13c) = 0;
  if (*(void **)(unaff_EDI + 0x138) != (void *)0x0) {
    _free(*(void **)(unaff_EDI + 0x138));
    *(undefined4 *)(unaff_EDI + 0x138) = 0;
  }
  *(undefined4 *)(unaff_EDI + 0x13c) = 0;
  *(undefined4 *)(unaff_EDI + 0x140) = 0;
  return;
}

