
/* Library Function - Single Match
    _strcoll
   
   Library: Visual Studio 2010 Release */

int __cdecl _strcoll(char *_Str1,char *_Str2)

{
  int iVar1;
  
  iVar1 = __strcoll_l(_Str1,_Str2,(_locale_t)0x0);
  return iVar1;
}

