
/* Library Function - Multiple Matches With Same Base Name
    private: unsigned short __thiscall std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> >::_Peek(void)const 
    private: wchar_t __thiscall std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t>
   >::_Peek(void)const 
   
   Library: Visual Studio 2010 Release */

undefined2 Peek(void)

{
  short sVar1;
  int *in_ECX;
  
  if (*in_ECX != 0) {
    sVar1 = FUN_00721a70();
    if (sVar1 != -1) {
      *(short *)((int)in_ECX + 6) = sVar1;
      goto LAB_00881bd0;
    }
  }
  *in_ECX = 0;
LAB_00881bd0:
  *(undefined1 *)(in_ECX + 1) = 1;
  return *(undefined2 *)((int)in_ECX + 6);
}

