
undefined4 FUN_005033b0(void)

{
  void *_Dst;
  int iVar1;
  int in_ECX;
  
  _Dst = *(void **)(in_ECX + 0x5eb0);
  if (_Dst != *(void **)(in_ECX + 0x5eb4)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x5eb4),0);
    *(void **)(in_ECX + 0x5eb4) = _Dst;
  }
  iVar1 = FUN_0040f060();
  FUN_00500240(in_ECX,*(undefined4 *)(iVar1 + 0x8c));
  return 0;
}

