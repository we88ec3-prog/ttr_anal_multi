
undefined4 FUN_0070d950(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10) != 0x11d) {
    FUN_006f7c30(*(undefined4 *)(unaff_ESI + 0x34),"\'%s\' expected","<name>");
                    /* WARNING: Subroutine does not return */
    FUN_006ff130();
  }
  uVar1 = *(undefined4 *)(unaff_ESI + 0x18);
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_ESI + 4);
  if (*(int *)(unaff_ESI + 0x20) != 0x11f) {
    *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 0x20);
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_ESI + 0x24);
    *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x28);
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x2c);
    *(undefined4 *)(unaff_ESI + 0x20) = 0x11f;
    return uVar1;
  }
  uVar2 = FUN_006ffec0(unaff_ESI + 0x18);
  *(undefined4 *)(unaff_ESI + 0x10) = uVar2;
  return uVar1;
}

