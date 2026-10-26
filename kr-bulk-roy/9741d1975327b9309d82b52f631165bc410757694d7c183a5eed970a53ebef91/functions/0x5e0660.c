
void FUN_005e0660(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_00408e60(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x298) = *(undefined4 *)(unaff_EDI + 0x298);
  *(undefined4 *)(unaff_ESI + 0x29c) = *(undefined4 *)(unaff_EDI + 0x29c);
  *(undefined4 *)(unaff_ESI + 0x2a0) = *(undefined4 *)(unaff_EDI + 0x2a0);
  *(undefined4 *)(unaff_ESI + 0x2a4) = *(undefined4 *)(unaff_EDI + 0x2a4);
  *(undefined1 *)(unaff_ESI + 0x2a8) = *(undefined1 *)(unaff_EDI + 0x2a8);
  return;
}

