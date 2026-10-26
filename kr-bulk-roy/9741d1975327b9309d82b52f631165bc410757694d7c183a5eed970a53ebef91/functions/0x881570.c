
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned short __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::sbumpc(void)
    public: unsigned short __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t>
   >::sbumpc(void)
   
   Library: Visual Studio 2010 Release */

undefined2 sbumpc(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int *in_ECX;
  
  if (*(int *)in_ECX[8] == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)in_ECX[0xc];
  }
  if (0 < iVar3) {
    *(int *)in_ECX[0xc] = *(int *)in_ECX[0xc] + -1;
    puVar1 = *(undefined2 **)in_ECX[8];
    *(undefined2 **)in_ECX[8] = puVar1 + 1;
    return *puVar1;
  }
  uVar2 = (**(code **)(*in_ECX + 0x1c))();
  return uVar2;
}

