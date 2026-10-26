
void FUN_00433ba0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  void *_Dst;
  undefined4 *in_ECX;
  
  pcVar2 = (char *)*in_ECX;
  if (pcVar2 != param_1) {
    if (pcVar2 != (char *)0x0) {
      _free(pcVar2);
    }
    *in_ECX = 0;
    if (param_1 != (char *)0x0) {
      cVar1 = *param_1;
      pcVar2 = param_1;
      while (cVar1 != '\0') {
        pcVar2 = pcVar2 + 1;
        cVar1 = *pcVar2;
      }
      _Dst = _malloc((size_t)(pcVar2 + (1 - (int)param_1)));
      *in_ECX = _Dst;
      if (_Dst != (void *)0x0) {
        FID_conflict__memcpy(_Dst,param_1,(size_t)(pcVar2 + (1 - (int)param_1)));
      }
      return;
    }
  }
  return;
}

