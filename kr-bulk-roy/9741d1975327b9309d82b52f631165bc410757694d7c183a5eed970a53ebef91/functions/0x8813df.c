
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual long __thiscall std::collate<unsigned short>::do_hash(unsigned short const
   *,unsigned short const *)const 
    protected: virtual long __thiscall std::collate<wchar_t>::do_hash(wchar_t const *,wchar_t const
   *)const 
   
   Library: Visual Studio 2010 Release */

uint do_hash(ushort *param_1,ushort *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = (uVar1 << 8 | uVar1 >> 0x18) + (uint)*param_1;
  }
  return uVar1;
}

