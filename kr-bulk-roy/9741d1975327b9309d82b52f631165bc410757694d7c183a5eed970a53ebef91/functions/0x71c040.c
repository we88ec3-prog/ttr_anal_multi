
void FUN_0071c040(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  char *_Dst;
  size_t _Size;
  char *pcVar3;
  size_t _Size_00;
  
  _Dst = (char *)*param_2;
  if (*_Dst != '\0') {
    pcVar2 = (char *)*param_1;
    if (((*pcVar2 != '\0') || (*(char *)(param_1 + 1) != '\0')) || (*(char *)(param_2 + 1) != '\0'))
    {
      pcVar3 = pcVar2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      _Size_00 = (int)pcVar3 - (int)(pcVar2 + 1);
      pcVar3 = _Dst + 1;
      do {
        cVar1 = *_Dst;
        _Dst = _Dst + 1;
      } while (cVar1 != '\0');
      _Size = (int)_Dst - (int)pcVar3;
      _Dst = (char *)FUN_0071be00(-(uint)(*(char *)(param_1 + 1) != '\0') & (uint)pcVar2,
                                  _Size_00 + 1);
      if (*(char *)(param_1 + 1) == '\0') {
        FID_conflict__memcpy(_Dst,(void *)*param_1,_Size_00);
      }
      FID_conflict__memcpy(_Dst + _Size_00,(void *)*param_2,_Size);
      _Dst[_Size + _Size_00] = '\0';
      *(undefined1 *)(param_1 + 1) = 1;
    }
    *param_1 = _Dst;
  }
  return;
}

