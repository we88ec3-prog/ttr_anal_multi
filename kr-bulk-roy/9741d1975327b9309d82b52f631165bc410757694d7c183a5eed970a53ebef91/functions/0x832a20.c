
void FUN_00832a20(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x14) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x14));
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  return;
}

