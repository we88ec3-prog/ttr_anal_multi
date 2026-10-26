
void FUN_004a9090(void)

{
  int unaff_ESI;
  
  if (0xf < *(uint *)(unaff_ESI + 0x2c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x18));
  }
  *(undefined4 *)(unaff_ESI + 0x2c) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  *(undefined1 *)(unaff_ESI + 0x18) = 0;
  return;
}

