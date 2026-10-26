
/* Library Function - Single Match
    _wcstol
   
   Library: Visual Studio 2010 Release */

long __cdecl _wcstol(wchar_t *_Str,wchar_t **_EndPtr,int _Radix)

{
  ulong uVar1;
  
  uVar1 = wcstoxl(_Str,_EndPtr,_Radix,0);
  return uVar1;
}

