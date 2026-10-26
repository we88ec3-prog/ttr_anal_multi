
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual char const * __thiscall std::ctype<unsigned short>::do_widen(char const
   *,char const *,unsigned short *)const 
    protected: virtual char const * __thiscall std::ctype<wchar_t>::do_widen(char const *,char const
   *,wchar_t *)const 
   
   Library: Visual Studio 2010 Release */

undefined1 * do_widen(undefined1 *param_1,undefined1 *param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = Dowiden(*param_1);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return param_1;
}

