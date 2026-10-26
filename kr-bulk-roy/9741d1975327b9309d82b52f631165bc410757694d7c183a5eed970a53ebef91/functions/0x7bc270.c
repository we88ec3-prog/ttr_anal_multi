
void FUN_007bc270(void)

{
  int unaff_ESI;
  
  if (0xf < *(uint *)(unaff_ESI + 0x3c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x28));
  }
  *(undefined4 *)(unaff_ESI + 0x3c) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined1 *)(unaff_ESI + 0x28) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x20)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0xc));
  }
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  *(undefined4 *)(unaff_ESI + 0x20) = 0xf;
  *(undefined1 *)(unaff_ESI + 0xc) = 0;
  return;
}

