
void FUN_00863a30(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x20) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x20));
  }
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x10));
  }
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  FUN_00863a70(unaff_ESI);
  return;
}

