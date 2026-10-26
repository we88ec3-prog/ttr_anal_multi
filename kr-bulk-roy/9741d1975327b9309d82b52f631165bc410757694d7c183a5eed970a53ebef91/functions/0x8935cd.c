
/* Library Function - Single Match
    __wtol
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

long __cdecl __wtol(wchar_t *_Str)

{
  long lVar1;
  
  lVar1 = _wcstol(_Str,(wchar_t **)0x0,10);
  return lVar1;
}

