
void FUN_00473700(undefined4 *param_1)

{
  void *_Dst;
  undefined1 in_AL;
  undefined4 in_ECX;
  int unaff_EDI;
  
  *(undefined1 *)(unaff_EDI + 0x268) = in_AL;
  *(undefined4 *)(unaff_EDI + 0x264) = in_ECX;
  _Dst = *(void **)(unaff_EDI + 0x254);
  if (_Dst != *(void **)(unaff_EDI + 600)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_EDI + 600),0);
    *(void **)(unaff_EDI + 600) = _Dst;
  }
  FUN_00474490(*(undefined4 *)(unaff_EDI + 0x254),*param_1,param_1[1],param_1);
  FUN_007597b0(0);
  return;
}

