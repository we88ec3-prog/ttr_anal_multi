
void * FUN_008b9fa0(undefined4 param_1,void *param_2,size_t param_3,int *param_4)

{
  void *_Dst;
  int local_8;
  
  _Dst = (void *)FUN_008b9f30(param_1,param_3,&local_8);
  if (local_8 != 0) {
    *param_4 = local_8;
    return _Dst;
  }
  if (param_2 != (void *)0x0) {
    FID_conflict__memcpy(_Dst,param_2,param_3);
    *param_4 = 0;
    return _Dst;
  }
  *param_4 = 0;
  return _Dst;
}

