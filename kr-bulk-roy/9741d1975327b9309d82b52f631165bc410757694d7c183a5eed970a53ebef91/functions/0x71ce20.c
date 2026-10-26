
void FUN_0071ce20(undefined4 param_1,void *param_2,int param_3)

{
  undefined1 *_Dst;
  uint _Size;
  undefined1 local_28 [32];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _Size = param_3 - (int)param_2;
  _Dst = local_28;
  if (0x1f < _Size) {
    _Dst = (undefined1 *)(*(code *)PTR_FUN_00d63d48)(_Size + 1);
    if (_Dst == (undefined1 *)0x0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  FID_conflict__memcpy(_Dst,param_2,_Size);
  _Dst[_Size] = 0;
  FUN_00721540(param_1);
  if (_Dst != local_28) {
    (*(code *)PTR_FUN_00d63d4c)(_Dst);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

