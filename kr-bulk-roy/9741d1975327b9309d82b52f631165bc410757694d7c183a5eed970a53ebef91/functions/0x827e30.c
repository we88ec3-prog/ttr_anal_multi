
void FUN_00827e30(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x74) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x74));
  }
  *(undefined4 *)(unaff_ESI + 0x74) = 0;
  *(undefined4 *)(unaff_ESI + 0x78) = 0;
  *(undefined4 *)(unaff_ESI + 0x7c) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x50)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x3c));
  }
  *(undefined4 *)(unaff_ESI + 0x50) = 7;
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  *(undefined2 *)(unaff_ESI + 0x3c) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x34)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x20));
  }
  *(undefined4 *)(unaff_ESI + 0x34) = 7;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined2 *)(unaff_ESI + 0x20) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 7;
  *(undefined2 *)(unaff_ESI + 4) = 0;
  return;
}

