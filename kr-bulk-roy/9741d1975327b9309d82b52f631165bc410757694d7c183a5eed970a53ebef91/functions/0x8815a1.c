
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned short __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::sputc(unsigned short)
    public: unsigned short __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t>
   >::sputc(wchar_t)
   
   Library: Visual Studio 2010 Release */

uint sputc(uint param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int *in_ECX;
  
  if (*(int *)in_ECX[9] == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)in_ECX[0xd];
  }
  if (iVar2 < 1) {
    param_1 = (**(code **)(*in_ECX + 0xc))(param_1);
  }
  else {
    *(int *)in_ECX[0xd] = *(int *)in_ECX[0xd] + -1;
    puVar1 = *(undefined2 **)in_ECX[9];
    *(undefined2 **)in_ECX[9] = puVar1 + 1;
    *puVar1 = (short)param_1;
  }
  return param_1 & 0xffff;
}

