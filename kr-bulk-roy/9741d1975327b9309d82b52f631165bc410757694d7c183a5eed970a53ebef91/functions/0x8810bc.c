
/* Library Function - Multiple Matches With Same Base Name
    protected: unsigned short __thiscall std::ctype<unsigned short>::_Dowiden(char)const 
    protected: wchar_t __thiscall std::ctype<wchar_t>::_Dowiden(char)const 
   
   Library: Visual Studio 2010 Release */

uint Dowiden(void)

{
  int iVar1;
  uint uVar2;
  uint in_ECX;
  mbstate_t local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = in_ECX;
  iVar1 = __Mbrtowc((wchar_t *)&local_8,&stack0x00000004,1,&local_c,(_Cvtvec *)(in_ECX + 0x18));
  uVar2 = 0xffff;
  if (-1 < iVar1) {
    uVar2 = local_8 & 0xffff;
  }
  return uVar2;
}

