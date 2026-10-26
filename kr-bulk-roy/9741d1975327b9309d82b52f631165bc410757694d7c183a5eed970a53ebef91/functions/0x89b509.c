
/* Library Function - Single Match
    __Strftime
   
   Library: Visual Studio 2010 Release */

size_t __cdecl __Strftime(char *param_1,size_t _Maxsize,char *param_3,tm *param_4,void *param_5)

{
  size_t sVar1;
  
  sVar1 = __Strftime_l(param_1,_Maxsize,param_3,param_4,param_5,0);
  return sVar1;
}

