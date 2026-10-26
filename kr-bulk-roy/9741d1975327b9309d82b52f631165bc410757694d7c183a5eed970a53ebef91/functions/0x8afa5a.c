
/* Library Function - Single Match
    __getpath
   
   Library: Visual Studio 2010 Release */

char * __cdecl __getpath(char *_Src,char *_Dst,size_t _SizeInChars)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  
  for (; *_Src == ';'; _Src = _Src + 1) {
  }
  _SizeInChars = _SizeInChars - 1;
  pcVar3 = _Src;
  if (_SizeInChars == 0) {
    piVar2 = __errno();
    *piVar2 = 0x22;
  }
  else {
    cVar1 = *_Src;
    while (cVar1 != '\0') {
      if (cVar1 == ';') goto LAB_008afad7;
      if (cVar1 == '\"') {
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
        if (cVar1 == '\0') break;
        do {
          if (cVar1 == '\"') break;
          *_Dst = cVar1;
          _Dst = _Dst + 1;
          pcVar3 = pcVar3 + 1;
          _SizeInChars = _SizeInChars - 1;
          if (_SizeInChars == 0) goto LAB_008afaa3;
          cVar1 = *pcVar3;
        } while (cVar1 != '\0');
        if (*pcVar3 == '\0') break;
        pcVar3 = pcVar3 + 1;
      }
      else {
        *_Dst = cVar1;
        _Dst = _Dst + 1;
        pcVar3 = pcVar3 + 1;
        _SizeInChars = _SizeInChars - 1;
        if (_SizeInChars == 0) {
LAB_008afaa3:
          piVar2 = __errno();
          *piVar2 = 0x22;
          _Src = pcVar3;
          goto LAB_008afadd;
        }
      }
      cVar1 = *pcVar3;
    }
    for (; *pcVar3 == ';'; pcVar3 = pcVar3 + 1) {
LAB_008afad7:
    }
  }
LAB_008afadd:
  *_Dst = '\0';
  return (char *)(-(uint)(_Src != pcVar3) & (uint)pcVar3);
}

