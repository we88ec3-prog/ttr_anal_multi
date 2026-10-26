
/* Library Function - Single Match
    _towlower
   
   Library: Visual Studio 2010 Release */

wint_t __cdecl _towlower(wint_t _C)

{
  wint_t wVar1;
  
  wVar1 = __towlower_l(_C,(_locale_t)0x0);
  return wVar1;
}

