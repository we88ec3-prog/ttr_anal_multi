
/* Library Function - Single Match
    __ismbblead_l
   
   Library: Visual Studio 2010 Release */

int __cdecl __ismbblead_l(uint _C,_locale_t _Locale)

{
  int iVar1;
  
  iVar1 = x_ismbbtype_l(_Locale,_C,0,4);
  return iVar1;
}

