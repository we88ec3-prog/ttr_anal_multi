
void FUN_007e5f20(void *param_1)

{
  void *_Dst;
  int unaff_ESI;
  size_t unaff_EDI;
  
  if (*(int *)(unaff_ESI + 0x148) != 0) {
    FUN_00891d3d(*(int *)(unaff_ESI + 0x148));
    *(undefined4 *)(unaff_ESI + 0x148) = 0;
  }
  *(size_t *)(unaff_ESI + 0x14c) = unaff_EDI;
  _Dst = (void *)FUN_0087dc3d();
  *(void **)(unaff_ESI + 0x148) = _Dst;
  FID_conflict__memcpy(_Dst,param_1,unaff_EDI);
  return;
}

