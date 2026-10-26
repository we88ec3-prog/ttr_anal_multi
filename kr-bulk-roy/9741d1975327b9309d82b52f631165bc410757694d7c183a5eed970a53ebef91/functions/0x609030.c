
void FUN_00609030(void)

{
  int unaff_ESI;
  
  if (7 < *(uint *)(unaff_ESI + 0x2c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x18));
  }
  *(undefined4 *)(unaff_ESI + 0x2c) = 7;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  *(undefined2 *)(unaff_ESI + 0x18) = 0;
  return;
}

