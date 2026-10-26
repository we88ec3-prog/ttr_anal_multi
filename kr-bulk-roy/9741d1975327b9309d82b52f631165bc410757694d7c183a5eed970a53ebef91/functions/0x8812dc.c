
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned short __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::sgetc(void)
    public: unsigned short __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t>
   >::sgetc(void)
   
   Library: Visual Studio 2010 Release */

undefined2 sgetc(void)

{
  undefined2 uVar1;
  int *in_ECX;
  int iVar2;
  
  if (*(int *)in_ECX[8] == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)in_ECX[0xc];
  }
  if (0 < iVar2) {
    return **(undefined2 **)in_ECX[8];
  }
  uVar1 = (**(code **)(*in_ECX + 0x18))();
  return uVar1;
}

