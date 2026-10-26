
/* Library Function - Multiple Matches With Different Base Names
    __vprintf_p_l
    __vprintf_s_l
    __vwprintf_p_l
    __vwprintf_s_l
   
   Library: Visual Studio 2010 Release */

int __cdecl FID_conflict___vwprintf_s_l(wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  
  iVar1 = FID_conflict__vprintf_helper(FUN_008a2ba0,_Format,_Locale,_ArgList);
  return iVar1;
}

