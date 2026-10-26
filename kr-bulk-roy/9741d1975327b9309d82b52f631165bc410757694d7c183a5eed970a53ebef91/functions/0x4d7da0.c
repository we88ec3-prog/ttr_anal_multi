
void FUN_004d7da0(void)

{
  int unaff_ESI;
  
  if (7 < *(uint *)(unaff_ESI + 0x1c)) {
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 8));
  }
  *(undefined4 *)(unaff_ESI + 0x1c) = 7;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined2 *)(unaff_ESI + 8) = 0;
  FUN_0089120c();
  return;
}

