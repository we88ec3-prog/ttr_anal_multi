
void FUN_008d0210(undefined4 *param_1)

{
  undefined4 uVar1;
  void *_Src;
  undefined4 *puVar2;
  void *_Dst;
  
  puVar2 = param_1;
  uVar1 = param_1[8];
  _Src = (void *)*param_1;
  if (_Src != (void *)0x0) {
    _Dst = (void *)FUN_008baee0(uVar1,param_1[1],&param_1);
    *puVar2 = _Dst;
    if (param_1 == (undefined4 *)0x0) {
      FID_conflict__memcpy(_Dst,_Src,puVar2[1]);
      FUN_008d00d0(_Src);
      puVar2[2] = puVar2[1];
      FUN_008b9f80(uVar1,_Src);
    }
  }
  return;
}

