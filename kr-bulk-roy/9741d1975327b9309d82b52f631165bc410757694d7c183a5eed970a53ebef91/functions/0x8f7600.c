
void FUN_008f7600(void)

{
  int unaff_ESI;
  
  FUN_008f42c0(unaff_ESI + 0x20);
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  FUN_008ba2a0(*(undefined4 *)(unaff_ESI + 0x1c));
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  return;
}

