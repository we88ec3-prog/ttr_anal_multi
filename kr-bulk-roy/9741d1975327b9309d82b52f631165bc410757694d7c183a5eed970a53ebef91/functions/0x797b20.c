
void FUN_00797b20(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xa0) != 0) {
    FUN_00798c00();
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0xa0));
  }
  *(undefined4 *)(unaff_ESI + 0xa0) = 0;
  *(undefined4 *)(unaff_ESI + 0xa4) = 0;
  *(undefined4 *)(unaff_ESI + 0xa8) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x94)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x80));
  }
  *(undefined4 *)(unaff_ESI + 0x94) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  *(undefined1 *)(unaff_ESI + 0x80) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x4c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x38));
  }
  *(undefined4 *)(unaff_ESI + 0x4c) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(undefined1 *)(unaff_ESI + 0x38) = 0;
  return;
}

