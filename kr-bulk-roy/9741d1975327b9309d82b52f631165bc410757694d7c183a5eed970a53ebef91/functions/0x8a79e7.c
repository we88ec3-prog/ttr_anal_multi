
/* Library Function - Multiple Matches With Different Base Names
    __vfprintf_p_l
    __vfprintf_s_l
   
   Library: Visual Studio 2010 Release */

int __cdecl
FID_conflict___vfprintf_s_l(FILE *_File,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  
  iVar1 = vfprintf_helper(FUN_008a2ba0,_File,_Format,_Locale,_ArgList);
  return iVar1;
}

