
void FUN_0082c2b0(void)

{
  undefined2 *unaff_ESI;
  undefined2 *unaff_EDI;
  
  *unaff_ESI = *unaff_EDI;
  FUN_00403040(unaff_EDI + 2,0,0xffffffff);
  FUN_00403040(unaff_EDI + 0x10,0,0xffffffff);
  FUN_00403040(unaff_EDI + 0x1e,0,0xffffffff);
  FUN_00403040(unaff_EDI + 0x2c,0,0xffffffff);
  *(undefined4 *)(unaff_ESI + 0x3a) = *(undefined4 *)(unaff_EDI + 0x3a);
  *(undefined4 *)(unaff_ESI + 0x3c) = *(undefined4 *)(unaff_EDI + 0x3c);
  *(undefined4 *)(unaff_ESI + 0x3e) = *(undefined4 *)(unaff_EDI + 0x3e);
  *(undefined4 *)(unaff_ESI + 0x40) = *(undefined4 *)(unaff_EDI + 0x40);
  *(undefined4 *)(unaff_ESI + 0x42) = *(undefined4 *)(unaff_EDI + 0x42);
  *(undefined4 *)(unaff_ESI + 0x44) = *(undefined4 *)(unaff_EDI + 0x44);
  *(undefined4 *)(unaff_ESI + 0x46) = *(undefined4 *)(unaff_EDI + 0x46);
  return;
}

