
void FUN_00797510(void)

{
  void *_Dst;
  undefined4 *puVar1;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 4);
  if (puVar1 != *(undefined4 **)(unaff_EDI + 8)) {
    do {
      FUN_0089120c(*puVar1);
      puVar1 = puVar1 + 1;
    } while (puVar1 != *(undefined4 **)(unaff_EDI + 8));
  }
  _Dst = *(void **)(unaff_EDI + 4);
  if (_Dst != *(void **)(unaff_EDI + 8)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_EDI + 8),0);
    *(void **)(unaff_EDI + 8) = _Dst;
  }
  return;
}

