
void * FUN_008ddf90(undefined4 param_1)

{
  undefined4 uVar1;
  int in_EAX;
  void *_Dst;
  size_t local_10;
  void *local_c;
  int local_8;
  
  uVar1 = *(undefined4 *)(*(int *)(in_EAX + 0x14) + 0x1c);
  local_8 = FUN_008dde20(param_1,&local_c,&local_10);
  if (local_8 == 0) {
    _Dst = (void *)FUN_008baee0(uVar1,local_10 + 1,&local_8);
    if (local_8 == 0) {
      FID_conflict__memcpy(_Dst,local_c,local_10);
      *(undefined1 *)(local_10 + (int)_Dst) = 0;
    }
    FUN_008ddf70();
    return _Dst;
  }
  return (void *)0x0;
}

