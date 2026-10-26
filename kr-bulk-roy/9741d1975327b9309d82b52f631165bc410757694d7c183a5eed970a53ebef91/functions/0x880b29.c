
/* Library Function - Multiple Matches With Same Base Name
    unsigned short __cdecl std::_Maklocchr<unsigned short>(char,unsigned short *,struct _Cvtvec
   const &)
    wchar_t __cdecl std::_Maklocchr<wchar_t>(char,wchar_t *,struct _Cvtvec const &)
   
   Library: Visual Studio 2010 Release */

uint _Maklocchr<>(undefined4 param_1,undefined4 param_2,_Cvtvec *param_3)

{
  mbstate_t local_c;
  uint local_8;
  
  local_8 = 0;
  local_c = 0;
  __Mbrtowc((wchar_t *)&local_8,(char *)&param_1,1,&local_c,param_3);
  return local_8 & 0xffff;
}

