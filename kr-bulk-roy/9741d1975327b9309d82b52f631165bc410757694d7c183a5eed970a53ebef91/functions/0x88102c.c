
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short __thiscall std::ctype<unsigned short>::do_tolower(unsigned
   short)const 
    protected: virtual wchar_t __thiscall std::ctype<wchar_t>::do_tolower(wchar_t)const 
   
   Library: Visual Studio 2010 Release */

void do_tolower(wchar_t param_1)

{
  int in_ECX;
  
  __Towlower(param_1,(_Ctypevec *)(in_ECX + 8));
  return;
}

