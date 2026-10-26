
void FUN_006eca30(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = 0;
  if (0 < *(int *)(unaff_ESI + 0x660)) {
    do {
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x65c) + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_006ecae0();
        FUN_0089120c(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(unaff_ESI + 0x660));
  }
  if (*(void **)(unaff_ESI + 0x65c) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x65c));
    *(undefined4 *)(unaff_ESI + 0x65c) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x664) = 0;
  *(undefined4 *)(unaff_ESI + 0x660) = 0;
  if (*(void **)(unaff_ESI + 0x65c) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x65c));
    *(undefined4 *)(unaff_ESI + 0x65c) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x664) = 0;
  *(undefined4 *)(unaff_ESI + 0x660) = 0;
  if (*(void **)(unaff_ESI + 0x650) != (void *)0x0) {
    _free(*(void **)(unaff_ESI + 0x650));
    *(undefined4 *)(unaff_ESI + 0x650) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x654) = 0;
  *(undefined4 *)(unaff_ESI + 0x658) = 0;
  return;
}

