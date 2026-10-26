
/* Library Function - Single Match
    _wcstok_s
   
   Library: Visual Studio 2010 Release */

wchar_t * __cdecl _wcstok_s(wchar_t *_Str,wchar_t *_Delim,wchar_t **_Context)

{
  wchar_t wVar1;
  wchar_t wVar2;
  int *piVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  
  if (_Context == (wchar_t **)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_00893343();
    return (wchar_t *)0x0;
  }
  if ((_Delim == (wchar_t *)0x0) ||
     ((_Str == (wchar_t *)0x0 && (_Str = *_Context, _Str == (wchar_t *)0x0)))) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_00893343();
    pwVar4 = (wchar_t *)0x0;
  }
  else {
    wVar2 = *_Str;
    if (wVar2 != L'\0') {
      wVar1 = *_Delim;
      pwVar4 = _Delim;
      do {
        while ((wVar1 != L'\0' && (wVar1 != wVar2))) {
          wVar1 = pwVar4[1];
          pwVar4 = pwVar4 + 1;
        }
        if (*pwVar4 == L'\0') break;
        _Str = _Str + 1;
        wVar2 = *_Str;
        wVar1 = *_Delim;
        pwVar4 = _Delim;
      } while (wVar2 != L'\0');
    }
    pwVar4 = _Str;
    if (*_Str != L'\0') {
      do {
        pwVar5 = _Delim;
        if (*_Delim != L'\0') {
          wVar2 = *_Delim;
          do {
            if (wVar2 == *pwVar4) break;
            pwVar5 = pwVar5 + 1;
            wVar2 = *pwVar5;
          } while (wVar2 != L'\0');
        }
        if (*pwVar5 != L'\0') {
          *pwVar4 = L'\0';
          pwVar4 = pwVar4 + 1;
          break;
        }
        pwVar4 = pwVar4 + 1;
      } while (*pwVar4 != L'\0');
    }
    *_Context = pwVar4;
    pwVar4 = (wchar_t *)(-(uint)(_Str != pwVar4) & (uint)_Str);
  }
  return pwVar4;
}

