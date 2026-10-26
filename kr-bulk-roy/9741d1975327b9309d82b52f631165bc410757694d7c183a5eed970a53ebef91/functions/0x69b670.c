
void FUN_0069b670(void)

{
  void *_Dst;
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  
  if ((*(int *)(unaff_EDI + 0x168) - *(int *)(unaff_EDI + 0x164) & 0xfffffffcU) != 0) {
    piVar2 = (int *)(unaff_EDI + 0x9c);
    iVar1 = 8;
    do {
      if (((int *)*piVar2)[0x95] != -1) {
        (**(code **)(*(int *)*piVar2 + 0x19c))(0xffffffff,0xffffffff,0,0);
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    _Dst = *(void **)(unaff_EDI + 0x164);
    if (_Dst != *(void **)(unaff_EDI + 0x168)) {
      FID_conflict__memcpy(_Dst,*(void **)(unaff_EDI + 0x168),0);
      *(void **)(unaff_EDI + 0x168) = _Dst;
    }
    (**(code **)(**(int **)(unaff_EDI + 0x98) + 200))();
    (**(code **)(**(int **)(unaff_EDI + 0xbc) + 0x90))
              (*(int *)(unaff_EDI + 0x164) != *(int *)(unaff_EDI + 0x168));
  }
  return;
}

