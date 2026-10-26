
void FUN_004dc7f0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x54));
    *(undefined4 *)(unaff_ESI + 0x54) = 0;
  }
  if (*(int *)(unaff_ESI + 0x44) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x44));
  }
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  if (*(int *)(unaff_ESI + 0x34) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x34));
  }
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  FUN_0089120c();
  return;
}

