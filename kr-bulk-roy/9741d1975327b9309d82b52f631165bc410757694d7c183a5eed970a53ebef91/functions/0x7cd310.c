
void FUN_007cd310(void)

{
  int unaff_ESI;
  
  if (0xf < *(uint *)(unaff_ESI + 0x40)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x2c));
  }
  *(undefined4 *)(unaff_ESI + 0x40) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  *(undefined1 *)(unaff_ESI + 0x2c) = 0;
  return;
}

