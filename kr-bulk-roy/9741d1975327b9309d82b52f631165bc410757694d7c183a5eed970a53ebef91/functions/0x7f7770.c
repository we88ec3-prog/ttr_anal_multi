
void FUN_007f7770(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x40) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x40));
    *(undefined4 *)(unaff_ESI + 0x40) = 0;
  }
  if (*(int *)(unaff_ESI + 0x38) != 0) {
    FUN_00891d3d(*(int *)(unaff_ESI + 0x38));
    *(undefined4 *)(unaff_ESI + 0x38) = 0;
  }
  if (0xf < *(uint *)(unaff_ESI + 0x74)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x60));
  }
  *(undefined4 *)(unaff_ESI + 0x74) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x70) = 0;
  *(undefined1 *)(unaff_ESI + 0x60) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x58)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x44));
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  *(undefined1 *)(unaff_ESI + 0x44) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x1c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 8));
  }
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0xf;
  *(undefined1 *)(unaff_ESI + 8) = 0;
  return;
}

