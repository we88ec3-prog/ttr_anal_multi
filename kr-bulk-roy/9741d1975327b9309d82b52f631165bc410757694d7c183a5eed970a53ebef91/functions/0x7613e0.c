
void FUN_007613e0(void)

{
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(unaff_EDI + 0x168) = 0;
  *(undefined4 *)(unaff_EDI + 0x160) = 0;
  *(undefined4 *)(unaff_EDI + 0x164) = 0;
  *(undefined4 *)(unaff_EDI + 0x14c) = 0;
  return;
}

