
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_scan_is(short,unsigned short const *,unsigned short const *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_scan_is(short,wchar_t
   const *,wchar_t const *)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

undefined2 * do_scan_is(undefined4 param_1,undefined2 *param_2,undefined2 *param_3)

{
  char cVar1;
  int *in_ECX;
  
  while( true ) {
    if (param_2 == param_3) {
      return param_2;
    }
    cVar1 = (**(code **)(*in_ECX + 8))(param_1,*param_2);
    if (cVar1 != '\0') break;
    param_2 = param_2 + 1;
  }
  return param_2;
}

