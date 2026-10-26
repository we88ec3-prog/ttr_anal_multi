
void FUN_00797a00(void)

{
  void *_Dst;
  undefined4 *puVar1;
  int *unaff_EDI;
  
  puVar1 = (undefined4 *)*unaff_EDI;
  if (puVar1 != (undefined4 *)unaff_EDI[1]) {
    do {
      FUN_0089120c(*puVar1);
      puVar1 = puVar1 + 1;
    } while (puVar1 != (undefined4 *)unaff_EDI[1]);
  }
  _Dst = (void *)*unaff_EDI;
  if (_Dst != (void *)unaff_EDI[1]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_EDI[1],0);
    unaff_EDI[1] = (int)_Dst;
  }
  return;
}

