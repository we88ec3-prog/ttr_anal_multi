
void FUN_007b61a0(void)

{
  int unaff_ESI;
  
  if (0xf < *(uint *)(unaff_ESI + 0x24)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x10));
  }
  *(undefined4 *)(unaff_ESI + 0x24) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined1 *)(unaff_ESI + 0x10) = 0;
  FUN_0089120c();
  return;
}

