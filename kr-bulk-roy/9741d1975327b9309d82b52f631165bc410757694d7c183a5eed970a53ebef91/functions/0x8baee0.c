
void * FUN_008baee0(undefined4 param_1,size_t param_2,int *param_3)

{
  void *_Dst;
  int local_8;
  
  _Dst = (void *)FUN_008b9f30(param_1,param_2,&local_8);
  if (local_8 != 0) {
    *param_3 = local_8;
    return _Dst;
  }
  if (0 < (int)param_2) {
    _memset(_Dst,0,param_2);
    *param_3 = 0;
    return _Dst;
  }
  *param_3 = 0;
  return _Dst;
}

