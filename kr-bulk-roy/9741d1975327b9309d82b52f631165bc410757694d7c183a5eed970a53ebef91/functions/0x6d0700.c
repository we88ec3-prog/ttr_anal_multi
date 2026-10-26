
void FUN_006d0700(void)

{
  void *_Dst;
  int in_EAX;
  undefined4 *puVar1;
  int local_8;
  
  puVar1 = (undefined4 *)(in_EAX + 4);
  local_8 = 0x28;
  do {
    _Dst = (void *)puVar1[-1];
    if (_Dst != (void *)*puVar1) {
      FID_conflict__memcpy(_Dst,(void *)*puVar1,0);
      *puVar1 = _Dst;
    }
    puVar1 = puVar1 + 4;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}

