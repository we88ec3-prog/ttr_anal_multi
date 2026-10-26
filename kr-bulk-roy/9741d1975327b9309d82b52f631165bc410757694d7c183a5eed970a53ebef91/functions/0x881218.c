
/* Library Function - Multiple Matches With Same Base Name
    private: int __cdecl std::num_get<unsigned short,class std::istreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Hexdig(unsigned short,unsigned short,unsigned
   short,unsigned short)const 
    private: int __cdecl std::num_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Hexdig(wchar_t,wchar_t,wchar_t,wchar_t)const 
   
   Library: Visual Studio 2010 Release */

int Hexdig(undefined4 param_1,ushort param_2,ushort param_3,ushort param_4,ushort param_5)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 <= param_2) {
    if ((uint)param_2 <= param_3 + 9) {
      return (uint)param_2 - (uint)param_3;
    }
  }
  if (((param_2 < param_4) || (uVar2 = (uint)param_4, uVar2 + 5 < (uint)param_2)) &&
     ((param_2 < param_5 || (uVar2 = (uint)param_5, uVar2 + 5 < (uint)param_2)))) {
    iVar1 = -1;
  }
  else {
    iVar1 = (param_2 - uVar2) + 10;
  }
  return iVar1;
}

