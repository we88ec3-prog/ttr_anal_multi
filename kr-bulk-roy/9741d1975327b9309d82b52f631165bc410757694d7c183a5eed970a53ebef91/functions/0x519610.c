
void FUN_00519610(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x1c));
  }
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  return;
}

