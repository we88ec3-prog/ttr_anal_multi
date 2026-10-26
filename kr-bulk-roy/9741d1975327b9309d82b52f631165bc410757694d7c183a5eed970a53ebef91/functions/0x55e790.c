
void FUN_0055e790(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + 1;
    iVar1 = FUN_008fed10(*(undefined4 *)(unaff_ESI + 0x1c));
    if (*(int *)(unaff_ESI + 0x14) == 0) {
      *(int *)(unaff_ESI + 0x10) = iVar1;
      if (0xfe < iVar1) {
        *(undefined4 *)(unaff_ESI + 0x10) = 0xff;
      }
    }
    else {
      *(int *)(unaff_ESI + 0x10) = 0xff - iVar1;
      if (0xff - iVar1 < 1) {
        *(undefined4 *)(unaff_ESI + 0x10) = 0;
        *(undefined4 *)(unaff_ESI + 0xc) = 0;
        return;
      }
    }
  }
  return;
}

