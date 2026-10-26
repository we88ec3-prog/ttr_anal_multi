
void FUN_008fd370(void)

{
  char cVar1;
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 0x2c) != '\0') {
    FUN_00572110();
    FUN_00572100();
    cVar1 = FUN_00572220();
    while (cVar1 != '\0') {
      thunk_FUN_00572200();
      FUN_008fd200();
      FUN_005721f0();
      cVar1 = FUN_00572220();
    }
  }
  if (*(char *)(unaff_EDI + 0x2d) != '\0') {
    FUN_00572110();
    FUN_00572100();
    cVar1 = FUN_00572220();
    while (cVar1 != '\0') {
      thunk_FUN_00572200();
      FUN_008fd1c0();
      FUN_005721f0();
      cVar1 = FUN_00572220();
    }
  }
  *(undefined4 *)(unaff_EDI + 0x50) = 0;
  *(undefined4 *)(unaff_EDI + 0x54) = 0;
  *(undefined4 *)(unaff_EDI + 0x58) = 0;
  *(undefined4 *)(unaff_EDI + 0x5c) = 0;
  *(undefined4 *)(unaff_EDI + 0x18) = 0;
  *(undefined1 *)(unaff_EDI + 0x60) = 0;
  *(undefined1 *)(unaff_EDI + 0x1c) = 1;
  *(undefined4 *)(unaff_EDI + 0x68) = 0xffffffff;
  *(undefined4 *)(unaff_EDI + 0x6c) = 0xffffffff;
  *(undefined4 *)(unaff_EDI + 100) = 0xffffffff;
  return;
}

