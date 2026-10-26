
/* Library Function - Multiple Matches With Same Base Name
    char __cdecl std::_Maklocbyte<unsigned short>(unsigned short,struct _Cvtvec const &)
    char __cdecl std::_Maklocbyte<wchar_t>(wchar_t,struct _Cvtvec const &)
   
   Library: Visual Studio 2010 Release */

undefined1 _Maklocbyte<>(wchar_t param_1,_Cvtvec *param_2)

{
  uint3 in_ECX;
  mbstate_t local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = (uint)in_ECX;
  __Wcrtomb((char *)((int)&uStack_8 + 3),param_1,&local_c,param_2);
  return uStack_8._3_1_;
}

