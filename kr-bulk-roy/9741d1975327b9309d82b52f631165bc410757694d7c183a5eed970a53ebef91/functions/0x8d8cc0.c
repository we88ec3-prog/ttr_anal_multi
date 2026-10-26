
void FUN_008d8cc0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = **(undefined4 **)(unaff_ESI + 0x1c);
  FUN_008b9f80(uVar1,*(undefined4 *)(unaff_ESI + 8));
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *(undefined4 *)(unaff_ESI + 4) = 0;
  FUN_008b9f80(uVar1,*(undefined4 *)(unaff_ESI + 0x18));
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  *(undefined1 *)(unaff_ESI + 0x20) = 0;
  return;
}

