
void FUN_007e87f0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x20) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x20));
  }
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  if (0xf < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 0xf;
  *(undefined1 *)(unaff_ESI + 4) = 0;
  return;
}

