
void FUN_007a3b70(void)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  int *unaff_EDI;
  
  uVar2 = 0;
  if (unaff_EDI[1] - *unaff_EDI >> 2 != 0) {
    do {
      if (*(int *)(*unaff_EDI + uVar2 * 4) != 0) {
        iVar1 = *(int *)(*unaff_EDI + uVar2 * 4);
        if (iVar1 != 0) {
          FUN_007a37f0();
          FUN_0089120c(iVar1);
        }
        *(undefined4 *)(*unaff_EDI + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(unaff_EDI[1] - *unaff_EDI >> 2));
  }
  _Dst = (void *)*unaff_EDI;
  if (_Dst != (void *)unaff_EDI[1]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_EDI[1],0);
    unaff_EDI[1] = (int)_Dst;
  }
  if (*unaff_EDI != 0) {
    FUN_0089120c(*unaff_EDI);
  }
  *unaff_EDI = 0;
  unaff_EDI[1] = 0;
  unaff_EDI[2] = 0;
  return;
}

