
void FUN_007bd850(void)

{
  int *piVar1;
  void *_Dst;
  int *piVar2;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 8);
  for (piVar2 = *(int **)(unaff_EDI + 4); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      FUN_0089120c(*piVar2);
      *piVar2 = 0;
    }
  }
  _Dst = *(void **)(unaff_EDI + 4);
  if (_Dst != *(void **)(unaff_EDI + 8)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_EDI + 8),0);
    *(void **)(unaff_EDI + 8) = _Dst;
  }
  if (*(int *)(unaff_EDI + 4) != 0) {
    FUN_0089120c(*(int *)(unaff_EDI + 4));
  }
  *(undefined4 *)(unaff_EDI + 4) = 0;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *(undefined4 *)(unaff_EDI + 0xc) = 0;
  return;
}

