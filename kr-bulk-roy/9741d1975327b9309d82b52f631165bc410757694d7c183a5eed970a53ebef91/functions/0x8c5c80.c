
undefined4 FUN_008c5c80(void)

{
  undefined4 uVar1;
  undefined4 in_ECX;
  int unaff_ESI;
  uint unaff_EDI;
  
  if (*(uint *)(unaff_ESI + 0x1c) < unaff_EDI) {
    *(undefined4 *)(unaff_ESI + 0x24) = in_ECX;
    uVar1 = FUN_008bc7d0();
    *(undefined4 *)(unaff_ESI + 0x20) = uVar1;
    *(uint *)(unaff_ESI + 0x1c) = unaff_EDI;
  }
  return 0;
}

