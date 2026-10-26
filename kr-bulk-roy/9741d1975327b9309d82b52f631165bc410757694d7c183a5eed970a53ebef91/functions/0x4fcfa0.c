
void FUN_004fcfa0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x2c) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x2c));
  }
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x24)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x10));
  }
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 7;
  *(undefined2 *)(unaff_ESI + 0x10) = 0;
  return;
}

