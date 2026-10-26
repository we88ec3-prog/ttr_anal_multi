
char * FUN_0071cab0(void)

{
  char *pcVar1;
  int *in_ECX;
  char *_Str;
  
  if (in_ECX[1] == 0) {
    if (*in_ECX != 0) {
      _Str = *(char **)(*in_ECX + 8);
      goto LAB_0071cacc;
    }
  }
  else {
    _Str = *(char **)(in_ECX[1] + 4);
LAB_0071cacc:
    if (_Str != (char *)0x0) goto LAB_0071cad7;
  }
  _Str = "";
LAB_0071cad7:
  pcVar1 = _strchr(_Str,0x3a);
  if (pcVar1 != (char *)0x0) {
    return pcVar1 + 1;
  }
  return _Str;
}

