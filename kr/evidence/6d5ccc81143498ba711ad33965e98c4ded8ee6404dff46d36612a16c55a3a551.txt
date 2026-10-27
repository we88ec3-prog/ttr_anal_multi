
void FUN_007dd1f0(void)

{
  void *_Dst;
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 100));
  iVar1 = *(int *)(unaff_ESI + 0x7c);
  uVar2 = 0;
  if (*(int *)(unaff_ESI + 0x80) - iVar1 >> 2 != 0) {
    do {
      FUN_007be0f0(*(undefined4 *)(iVar1 + uVar2 * 4));
      if (*(int *)(*(int *)(unaff_ESI + 0x7c) + uVar2 * 4) != 0) {
        iVar1 = *(int *)(*(int *)(unaff_ESI + 0x7c) + uVar2 * 4);
        if (iVar1 != 0) {
          FUN_007bd850();
          FUN_0089120c(iVar1);
        }
        *(undefined4 *)(*(int *)(unaff_ESI + 0x7c) + uVar2 * 4) = 0;
      }
      iVar1 = *(int *)(unaff_ESI + 0x7c);
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_ESI + 0x80) - iVar1 >> 2));
  }
  _Dst = *(void **)(unaff_ESI + 0x7c);
  if (_Dst != *(void **)(unaff_ESI + 0x80)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_ESI + 0x80),0);
    *(void **)(unaff_ESI + 0x80) = _Dst;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 100));
  return;
}

