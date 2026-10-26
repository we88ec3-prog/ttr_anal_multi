
void FUN_007b7ef0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x10));
  }
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  FUN_00552640((undefined4 *)(unaff_ESI + 4));
  FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  FUN_0089120c();
  return;
}

