
/* Library Function - Multiple Matches With Different Base Names
    __wcstoul_l
    _wcstoul
   
   Library: Visual Studio 2010 Release */

ulong __cdecl FID_conflict___wcstoul_l(wchar_t *_Str,wchar_t **_EndPtr,int _Radix)

{
  ulong uVar1;
  
  uVar1 = wcstoxl(_Str,_EndPtr,_Radix,1);
  return uVar1;
}

