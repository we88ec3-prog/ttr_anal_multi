
/* Library Function - Single Match
    _wcschr
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2019 Release */

wchar_t * __cdecl _wcschr(wchar_t *_Str,wchar_t _Ch)

{
  while( true ) {
    if (*_Str == L'\0') {
      if (*_Str != _Ch) {
        _Str = (wchar_t *)0x0;
      }
      return _Str;
    }
    if (*_Str == _Ch) break;
    _Str = _Str + 1;
  }
  return _Str;
}

