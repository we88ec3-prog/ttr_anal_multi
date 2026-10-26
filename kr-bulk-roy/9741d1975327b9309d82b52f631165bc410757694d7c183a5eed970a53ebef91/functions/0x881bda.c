
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> >::_Inc(void)
    private: void __thiscall std::istreambuf_iterator<wchar_t,struct std::char_traits<wchar_t>
   >::_Inc(void)
   
   Library: Visual Studio 2010 Release */

void Inc(void)

{
  short sVar1;
  int *in_ECX;
  
  if (*in_ECX != 0) {
    sVar1 = sbumpc();
    if (sVar1 != -1) {
      *(undefined1 *)(in_ECX + 1) = 0;
      return;
    }
  }
  *in_ECX = 0;
  *(undefined1 *)(in_ECX + 1) = 1;
  return;
}

