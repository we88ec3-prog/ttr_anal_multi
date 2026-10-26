
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual bool __thiscall std::ctype<unsigned short>::do_is(short,unsigned short)const 
    protected: virtual bool __thiscall std::ctype<wchar_t>::do_is(short,wchar_t)const 
   
   Library: Visual Studio 2010 Release */

bool do_is(ushort param_1,wchar_t param_2)

{
  ushort uVar1;
  int in_ECX;
  
  uVar1 = __Getwctype(param_2,(_Ctypevec *)(in_ECX + 8));
  return (param_1 & uVar1) != 0;
}

