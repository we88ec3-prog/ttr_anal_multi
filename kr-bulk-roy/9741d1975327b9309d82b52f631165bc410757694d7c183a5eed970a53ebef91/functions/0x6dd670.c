
void FUN_006dd670(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x10);
  if (iVar1 != 0) {
    if ((*(int *)(iVar1 + 0x11c) != 0) && (*(int *)(iVar1 + 0xa8) == 0x11)) {
      FUN_007a6970(*(undefined4 *)(unaff_ESI + 0x78),0x3f800000);
      return;
    }
    if ((*(int *)(iVar1 + 0xa8) != *(int *)(unaff_ESI + 0x78)) &&
       (*(char *)(unaff_ESI + 0x80) != '\0')) {
      if (*(int *)(iVar1 + 0xa8) != 0xf) {
        FUN_007a6970(*(int *)(unaff_ESI + 0x78),0x3f800000);
        *(undefined1 *)(unaff_ESI + 0x80) = 0;
        return;
      }
      FUN_007a6970(0x11,0x3f800000);
      *(undefined1 *)(unaff_ESI + 0x80) = 0;
    }
  }
  return;
}

