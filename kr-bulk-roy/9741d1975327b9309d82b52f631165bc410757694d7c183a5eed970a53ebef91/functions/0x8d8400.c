
int FUN_008d8400(void *param_1,int param_2,undefined4 *param_3)

{
  void *_Dst;
  int iVar1;
  size_t _Size;
  int local_8;
  
  _Size = param_2 - (int)param_1;
  local_8 = 0;
  iVar1 = 0;
  if (param_3[0x14] == 0) {
    _Dst = (void *)FUN_008baee0(*param_3,_Size + 1,&local_8);
    param_3[0x14] = _Dst;
    iVar1 = local_8;
    if (local_8 == 0) {
      FID_conflict__memcpy(_Dst,param_1,_Size);
      *(undefined1 *)(_Size + param_3[0x14]) = 0;
      return local_8;
    }
  }
  return iVar1;
}

