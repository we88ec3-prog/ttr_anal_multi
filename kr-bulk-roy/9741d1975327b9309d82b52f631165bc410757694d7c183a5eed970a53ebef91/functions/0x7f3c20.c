
void FUN_007f3c20(void)

{
  int iVar1;
  int unaff_ESI;
  
  FUN_007f4120();
  iVar1 = *(int *)(unaff_ESI + 0x24);
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  *(int *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  if (*(int *)(unaff_ESI + 0x14) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x14));
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  FUN_0089120c();
  return;
}

