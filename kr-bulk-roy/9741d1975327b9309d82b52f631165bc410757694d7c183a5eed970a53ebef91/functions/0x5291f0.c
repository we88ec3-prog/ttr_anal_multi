
void FUN_005291f0(void)

{
  int unaff_ESI;
  
  if (7 < *(uint *)(unaff_ESI + 0x34)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x20));
  }
  *(undefined4 *)(unaff_ESI + 0x34) = 7;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined2 *)(unaff_ESI + 0x20) = 0;
  if (7 < *(uint *)(unaff_ESI + 0x18)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 4));
  }
  *(undefined4 *)(unaff_ESI + 0x18) = 7;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined2 *)(unaff_ESI + 4) = 0;
  return;
}

