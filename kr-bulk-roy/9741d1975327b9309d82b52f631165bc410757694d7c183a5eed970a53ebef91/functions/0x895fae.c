
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fgetws
   
   Library: Visual Studio 2010 Release */

wchar_t * __cdecl _fgetws(wchar_t *_Dst,int _SizeInWords,FILE *_File)

{
  wchar_t wVar1;
  int *piVar2;
  wchar_t *pwVar3;
  wchar_t *local_20;
  
  local_20 = _Dst;
  if ((((_Dst == (wchar_t *)0x0) && (_SizeInWords != 0)) || (_SizeInWords < 0)) ||
     (_File == (FILE *)0x0)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
  }
  else if (_SizeInWords != 0) {
    __lock_file(_File);
    pwVar3 = _Dst;
    if (_Dst != (wchar_t *)0x0) {
      do {
        _SizeInWords = _SizeInWords + -1;
        if (_SizeInWords == 0) break;
        wVar1 = __fgetwc_nolock(_File);
        if (wVar1 == L'\xffff') {
          if (pwVar3 == _Dst) {
            local_20 = (wchar_t *)0x0;
            goto LAB_00896048;
          }
          break;
        }
        *pwVar3 = wVar1;
        pwVar3 = pwVar3 + 1;
      } while (wVar1 != L'\n');
      *pwVar3 = L'\0';
    }
LAB_00896048:
    FUN_0089605d();
    return local_20;
  }
  return (wchar_t *)0x0;
}

