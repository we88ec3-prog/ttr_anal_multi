
/* Library Function - Multiple Matches With Same Base Name
    protected: char __thiscall std::ctype<unsigned short>::_Donarrow(unsigned short,char)const 
    protected: char __thiscall std::ctype<wchar_t>::_Donarrow(wchar_t,char)const 
   
   Library: Visual Studio 2010 Release */

void Donarrow(wchar_t param_1)

{
  int in_ECX;
  mbstate_t local_14;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = 0;
  __Wcrtomb(local_10,param_1,&local_14,(_Cvtvec *)(in_ECX + 0x18));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

