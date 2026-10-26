
void FUN_007cf5b0(void)

{
  int unaff_ESI;
  
  if (0xf < *(uint *)(unaff_ESI + 0x3c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x28));
  }
  *(undefined4 *)(unaff_ESI + 0x3c) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined1 *)(unaff_ESI + 0x28) = 0;
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0xc));
  }
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  FUN_0089120c();
  return;
}

