
void FUN_004ccf90(void)

{
  int unaff_ESI;
  
  if (0xf < *(uint *)(unaff_ESI + 0x6c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x58));
  }
  *(undefined4 *)(unaff_ESI + 0x6c) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  *(undefined1 *)(unaff_ESI + 0x58) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x50)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x3c));
  }
  *(undefined4 *)(unaff_ESI + 0x50) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  *(undefined1 *)(unaff_ESI + 0x3c) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x34)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x20));
  }
  *(undefined4 *)(unaff_ESI + 0x34) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined1 *)(unaff_ESI + 0x20) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x18) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined1 *)(unaff_ESI + 4) = 0;
  return;
}

