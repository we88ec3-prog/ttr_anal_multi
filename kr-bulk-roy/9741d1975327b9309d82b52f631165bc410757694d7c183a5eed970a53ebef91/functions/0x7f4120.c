
void FUN_007f4120(void)

{
  void *_Dst;
  int *piVar1;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  if (piVar1 != (int *)unaff_EDI[1]) {
    do {
      if (*piVar1 != 0) {
        FUN_0089120c(*piVar1);
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 != (int *)unaff_EDI[1]);
  }
  _Dst = (void *)*unaff_EDI;
  if (_Dst != (void *)unaff_EDI[1]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_EDI[1],0);
    unaff_EDI[1] = (int)_Dst;
  }
  return;
}

