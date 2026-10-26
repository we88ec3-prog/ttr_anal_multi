
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_tolower(unsigned short *,unsigned short const *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_tolower(wchar_t *,wchar_t
   const *)const 
   
   Library: Visual Studio 2010 Release */

wchar_t * do_tolower(wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  int in_ECX;
  
  if (param_1 != param_2) {
    do {
      wVar1 = __Towlower(*param_1,(_Ctypevec *)(in_ECX + 8));
      *param_1 = wVar1;
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return param_1;
}

