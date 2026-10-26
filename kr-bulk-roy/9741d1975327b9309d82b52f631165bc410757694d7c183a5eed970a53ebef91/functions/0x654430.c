
void FUN_00654430(void)

{
  int iVar1;
  byte bVar2;
  byte *unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 4) != 0) && (bVar2 = 0, *unaff_ESI != 0)) {
    do {
      iVar1 = (uint)bVar2 * 4;
      if (*(int *)(*(int *)(unaff_ESI + 4) + iVar1) != 0) {
        FUN_00891d3d(*(undefined4 *)(*(int *)(unaff_ESI + 4) + iVar1));
        *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 4)) = 0;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < *unaff_ESI);
  }
  if (*(int *)(unaff_ESI + 4) != 0) {
    FUN_00891d3d(*(int *)(unaff_ESI + 4));
    unaff_ESI[4] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
  }
  if (*(int *)(unaff_ESI + 0x20) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x20));
  }
  unaff_ESI[0x20] = 0;
  unaff_ESI[0x21] = 0;
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x23] = 0;
  unaff_ESI[0x24] = 0;
  unaff_ESI[0x25] = 0;
  unaff_ESI[0x26] = 0;
  unaff_ESI[0x27] = 0;
  unaff_ESI[0x28] = 0;
  unaff_ESI[0x29] = 0;
  unaff_ESI[0x2a] = 0;
  unaff_ESI[0x2b] = 0;
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    FUN_0089120c(*(int *)(unaff_ESI + 0x10));
  }
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x13] = 0;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1b] = 0;
  return;
}

