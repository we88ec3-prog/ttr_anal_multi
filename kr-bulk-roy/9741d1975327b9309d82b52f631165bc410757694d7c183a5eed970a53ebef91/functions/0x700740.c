
void FUN_00700740(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_ESI + 4);
  if (*(int *)(unaff_ESI + 0x20) != 0x11f) {
    *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 0x20);
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_ESI + 0x24);
    *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x28);
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x2c);
    *(undefined4 *)(unaff_ESI + 0x20) = 0x11f;
    return;
  }
  uVar1 = FUN_006ffec0(unaff_ESI + 0x18);
  *(undefined4 *)(unaff_ESI + 0x10) = uVar1;
  return;
}

