
void FUN_007e5ec0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x94) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x94));
  }
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  *(undefined4 *)(unaff_ESI + 0x98) = 0;
  *(undefined4 *)(unaff_ESI + 0x9c) = 0;
  if (*(int *)(unaff_ESI + 0x84) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x84));
  }
  *(undefined4 *)(unaff_ESI + 0x84) = 0;
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  *(undefined4 *)(unaff_ESI + 0x8c) = 0;
  FUN_0089120c();
  return;
}

