
void FUN_00848190(void)

{
  void *_Dst;
  undefined4 *in_EAX;
  undefined4 *unaff_ESI;
  undefined4 local_8;
  
  local_8 = *in_EAX;
  _Dst = (void *)*unaff_ESI;
  if (_Dst != (void *)unaff_ESI[1]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_ESI[1],0);
    unaff_ESI[1] = _Dst;
  }
  FUN_00848740(unaff_ESI,*unaff_ESI,&local_8);
  return;
}

