
void FUN_00874550(void)

{
  void *_Dst;
  undefined4 *in_ECX;
  
  *in_ECX = gbAniMeshController::vftable;
  FUN_00874d70(in_ECX[0xc],in_ECX[0xd]);
  _Dst = (void *)in_ECX[0xc];
  if (_Dst != (void *)in_ECX[0xd]) {
    FID_conflict__memcpy(_Dst,(void *)in_ECX[0xd],0);
    in_ECX[0xd] = _Dst;
  }
  if (in_ECX[0xc] != 0) {
    FUN_0089120c(in_ECX[0xc]);
  }
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  *in_ECX = gbBase::vftable;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = gbRefCount::vftable;
  return;
}

