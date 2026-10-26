
int FUN_008d0100(undefined4 param_1)

{
  undefined4 uVar1;
  void *_Src;
  void *_Dst;
  undefined4 *unaff_ESI;
  int local_8;
  
  uVar1 = unaff_ESI[8];
  _Src = (void *)*unaff_ESI;
  _Dst = (void *)FUN_008baee0(uVar1,param_1,&local_8);
  *unaff_ESI = _Dst;
  if (local_8 != 0) {
    *unaff_ESI = _Src;
    return local_8;
  }
  if (_Src != (void *)0x0) {
    FID_conflict__memcpy(_Dst,_Src,unaff_ESI[2]);
    FUN_008d00d0(_Src);
    FUN_008b9f80(uVar1,_Src);
  }
  unaff_ESI[2] = param_1;
  return 0;
}

