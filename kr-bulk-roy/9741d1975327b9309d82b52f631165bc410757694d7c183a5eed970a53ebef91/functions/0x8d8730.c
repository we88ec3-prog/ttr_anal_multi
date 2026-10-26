
void FUN_008d8730(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  FUN_008b9f80();
  *(undefined4 *)(unaff_ESI + 0x50) = 0;
  FUN_008b9f80();
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  FUN_008b9f80();
  *(undefined4 *)(unaff_ESI + 0x58) = 0;
  FUN_008b9f80();
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  FUN_008b9f80();
  *(undefined4 *)(unaff_ESI + 100) = 0;
  *(undefined4 *)(unaff_ESI + 0x5c) = 0;
  *(undefined4 *)(unaff_ESI + 0x60) = 0;
  FUN_008b9f80();
  *(undefined4 *)(unaff_ESI + 0x80) = 0;
  *(undefined4 *)(unaff_ESI + 0x78) = 0;
  *(undefined4 *)(unaff_ESI + 0x7c) = 0;
  FUN_008b9f80();
  puVar1 = *(undefined4 **)(unaff_ESI + 0x88);
  *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  while (puVar1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar1;
    FUN_008b9f80();
  }
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  *(undefined4 *)(unaff_ESI + 0x8c) = 0;
  *(undefined4 *)(unaff_ESI + 0x84) = 0;
  return;
}

