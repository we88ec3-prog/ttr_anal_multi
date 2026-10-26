
void FUN_00730a70(void)

{
  int unaff_ESI;
  
  if ((*(byte *)(unaff_ESI + 0x40) & 1) != 0) {
    FUN_0089120c(**(undefined4 **)(unaff_ESI + 0x10));
  }
  **(undefined4 **)(unaff_ESI + 0x10) = 0;
  **(undefined4 **)(unaff_ESI + 0x20) = 0;
  **(undefined4 **)(unaff_ESI + 0x30) = 0;
  **(undefined4 **)(unaff_ESI + 0x14) = 0;
  **(undefined4 **)(unaff_ESI + 0x24) = 0;
  **(undefined4 **)(unaff_ESI + 0x34) = 0;
  *(uint *)(unaff_ESI + 0x40) = *(uint *)(unaff_ESI + 0x40) & 0xfffffffe;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  return;
}

