
void FUN_00425d20(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x24) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x24));
  }
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x1c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 8));
  }
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 7;
  *(undefined2 *)(unaff_ESI + 8) = 0;
  return;
}

