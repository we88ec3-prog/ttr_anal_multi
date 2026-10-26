
void FUN_0051eb80(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x30) != 0) {
    FUN_0051f410(*(undefined4 *)(unaff_ESI + 0x34));
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x30));
  }
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  if (*(int *)(unaff_ESI + 0x20) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x20));
  }
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 7;
  *(undefined2 *)(unaff_ESI + 4) = 0;
  return;
}

