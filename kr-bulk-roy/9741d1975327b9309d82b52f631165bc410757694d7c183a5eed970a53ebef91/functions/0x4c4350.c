
void FUN_004c4350(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x40) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x40));
  }
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  return;
}

