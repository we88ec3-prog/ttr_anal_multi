
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned short>::do_is(unsigned
   short const *,unsigned short const *,short *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_is(wchar_t const *,wchar_t
   const *,short *)const 
   
   Library: Visual Studio 2010 Release */

void do_is(wchar_t *param_1,wchar_t *param_2,short *param_3)

{
  int in_ECX;
  
  __Getwctypes(param_1,param_2,param_3,(_Ctypevec *)(in_ECX + 8));
  return;
}

