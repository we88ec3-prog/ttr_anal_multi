
void FUN_008fd450(void)

{
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if (*(int *)(unaff_ESI + 0x2c) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x2c));
  }
  *(undefined4 *)(unaff_ESI + 0x2c) = unaff_EDI;
  FUN_00571da0(*(undefined4 *)(unaff_ESI + 8));
  return;
}

