
void FUN_007add00(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x30) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x30));
  }
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x28)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x14));
  }
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0xf;
  *(undefined1 *)(unaff_ESI + 0x14) = 0;
  return;
}

