
void FUN_0081c710(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x28) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x28));
  }
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x20)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0xc));
  }
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  *(undefined4 *)(unaff_ESI + 0x20) = 7;
  *(undefined2 *)(unaff_ESI + 0xc) = 0;
  return;
}

