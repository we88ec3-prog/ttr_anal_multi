
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_narrow(unsigned short const *,unsigned short const *,char,char *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_narrow(wchar_t const
   *,wchar_t const *,char,char *)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

undefined2 *
do_narrow(undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = Donarrow(*param_1,param_3);
    *param_4 = uVar1;
    param_4 = param_4 + 1;
  }
  return param_1;
}

