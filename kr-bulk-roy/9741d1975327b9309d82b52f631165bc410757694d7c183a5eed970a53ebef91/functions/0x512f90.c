
void FUN_00512f90(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 100) != 0) {
    FUN_00512f50(*(undefined4 *)(unaff_ESI + 0x68));
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 100));
  }
  *(undefined4 *)(unaff_ESI + 100) = 0;
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x54));
  }
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  *(undefined4 *)(unaff_ESI + 0x58) = 0;
  *(undefined4 *)(unaff_ESI + 0x5c) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x4c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x38));
  }
  *(undefined4 *)(unaff_ESI + 0x4c) = 7;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(undefined2 *)(unaff_ESI + 0x38) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 7;
  *(undefined2 *)(unaff_ESI + 4) = 0;
  return;
}

