
void FUN_0050dde0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x44) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x44));
  }
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x3c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x28));
  }
  *(undefined4 *)(unaff_ESI + 0x3c) = 7;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined2 *)(unaff_ESI + 0x28) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 7;
  *(undefined2 *)(unaff_ESI + 4) = 0;
  return;
}

