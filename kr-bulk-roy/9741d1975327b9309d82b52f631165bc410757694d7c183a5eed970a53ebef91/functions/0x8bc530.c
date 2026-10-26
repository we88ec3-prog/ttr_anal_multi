
undefined4 *
FUN_008bc530(undefined4 *param_1,undefined4 param_2,char *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  char cVar1;
  char *_Src;
  char *pcVar2;
  size_t _Size;
  void *_Dst;
  
  _Src = param_3;
  pcVar2 = param_3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  _Size = (int)pcVar2 - (int)(param_3 + 1);
  if (0x7fffffff < (int)(_Size + 6)) {
    return (undefined4 *)0xa;
  }
  _Dst = (void *)FUN_008baee0(*param_1,_Size + 6,&param_1);
  if (param_1 == (undefined4 *)0x0) {
    FID_conflict__memcpy(_Dst,_Src,_Size);
    *(undefined4 *)(_Size + (int)_Dst) = 0x7273722f;
    *(undefined2 *)(_Size + 4 + (int)_Dst) = 99;
    *param_4 = _Dst;
    *param_5 = 0;
    param_1 = (undefined4 *)0x0;
  }
  return param_1;
}

