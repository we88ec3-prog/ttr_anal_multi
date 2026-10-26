
void FUN_007b8f30(void)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  int unaff_EDI;
  
  uVar2 = 0;
  if (*(int *)(unaff_EDI + 0x48) - *(int *)(unaff_EDI + 0x44) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(unaff_EDI + 0x44) + uVar2 * 4) != 0) {
        iVar1 = *(int *)(*(int *)(unaff_EDI + 0x44) + uVar2 * 4);
        if (iVar1 != 0) {
          if (0xf < *(uint *)(iVar1 + 0x40)) {
            FUN_0089120c(*(undefined4 *)(iVar1 + 0x2c));
          }
          *(undefined4 *)(iVar1 + 0x40) = 0xf;
          *(undefined4 *)(iVar1 + 0x3c) = 0;
          *(undefined1 *)(iVar1 + 0x2c) = 0;
          FUN_0089120c(iVar1);
        }
        *(undefined4 *)(*(int *)(unaff_EDI + 0x44) + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_EDI + 0x48) - *(int *)(unaff_EDI + 0x44) >> 2));
  }
  _Dst = *(void **)(unaff_EDI + 0x44);
  if (_Dst != *(void **)(unaff_EDI + 0x48)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_EDI + 0x48),0);
    *(void **)(unaff_EDI + 0x48) = _Dst;
  }
  return;
}

