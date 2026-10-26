
/* Library Function - Single Match
    __vsnwprintf
   
   Library: Visual Studio 2010 Release */

int __cdecl __vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = __vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}

