
void FUN_00527fd0(void)

{
  undefined4 in_ECX;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x6c) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x6c));
  }
  *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  *(undefined4 *)(unaff_ESI + 0x70) = 0;
  *(undefined4 *)(unaff_ESI + 0x74) = 0;
  if (0xf < *(uint *)(unaff_ESI + 100)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x50));
  }
  *(undefined4 *)(unaff_ESI + 100) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x60) = 0;
  *(undefined1 *)(unaff_ESI + 0x50) = 0;
  if (*(int *)(unaff_ESI + 0x40) != 0) {
    FUN_00528460(*(undefined4 *)(unaff_ESI + 0x44),in_ECX);
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x40));
  }
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x38)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x24));
  }
  *(undefined4 *)(unaff_ESI + 0x38) = 7;
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined2 *)(unaff_ESI + 0x24) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 7;
  *(undefined2 *)(unaff_ESI + 4) = 0;
  return;
}

