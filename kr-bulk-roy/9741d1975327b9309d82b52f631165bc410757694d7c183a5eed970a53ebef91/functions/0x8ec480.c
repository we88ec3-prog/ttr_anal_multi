
undefined4 FUN_008ec480(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x100) != 0) {
    return *(undefined4 *)(unaff_ESI + 0x100);
  }
  if (*(short *)(unaff_ESI + 0x128) == 0) {
    *(undefined4 *)(unaff_ESI + 0x100) = *(undefined4 *)(unaff_ESI + 0xf4);
    return *(undefined4 *)(unaff_ESI + 0xf4);
  }
  if (*(short *)(unaff_ESI + 0x126) == 0) {
    *(undefined4 *)(unaff_ESI + 0x100) = *(undefined4 *)(unaff_ESI + 0xf8);
    return *(undefined4 *)(unaff_ESI + 0xf8);
  }
  uVar1 = FUN_008ec3a0();
  uVar2 = FUN_008ec3a0();
  uVar1 = FUN_008ba200(uVar1,uVar2);
  *(undefined4 *)(unaff_ESI + 0x100) = uVar1;
  return uVar1;
}

