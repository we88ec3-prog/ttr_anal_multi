
void FUN_004f0e50(void)

{
  int unaff_ESI;
  
  if (7 < *(uint *)(unaff_ESI + 0x58)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x44));
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 7;
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  *(undefined2 *)(unaff_ESI + 0x44) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x3c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x28));
  }
  *(undefined4 *)(unaff_ESI + 0x3c) = 7;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined2 *)(unaff_ESI + 0x28) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x1c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 8));
  }
  *(undefined4 *)(unaff_ESI + 0x1c) = 7;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined2 *)(unaff_ESI + 8) = 0;
  return;
}

