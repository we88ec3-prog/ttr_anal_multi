
void FUN_00765af0(void)

{
  int iVar1;
  void *_Dst;
  int unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(unaff_ESI + 0x114) - *(int *)(unaff_ESI + 0x110) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(unaff_ESI + 0x110) + uVar2 * 4) != 0) {
        iVar1 = *(int *)(*(int *)(unaff_ESI + 0x110) + uVar2 * 4);
        if (iVar1 != 0) {
          FUN_00757640(iVar1);
          FUN_0089120c(iVar1);
        }
        *(undefined4 *)(*(int *)(unaff_ESI + 0x110) + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_ESI + 0x114) - *(int *)(unaff_ESI + 0x110) >> 2));
  }
  _Dst = *(void **)(unaff_ESI + 0x110);
  if (_Dst != *(void **)(unaff_ESI + 0x114)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_ESI + 0x114),0);
    *(void **)(unaff_ESI + 0x114) = _Dst;
  }
  *(undefined4 *)(unaff_ESI + 0x140) = 0;
  *(undefined4 *)(unaff_ESI + 0x13c) = 0;
  *(undefined4 *)(unaff_ESI + 0x14c) = 0;
  *(undefined4 *)(unaff_ESI + 0x154) = 0;
  *(undefined4 *)(unaff_ESI + 0x150) = 0;
  *(undefined4 *)(unaff_ESI + 0x158) = 0;
  *(undefined4 *)(unaff_ESI + 0x134) = 0;
  return;
}

