
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(unsigned short const *)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void basic_string<>(wchar_t *param_1)

{
  size_t sVar1;
  undefined2 *in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 10) = 7;
  *in_ECX = 0;
  sVar1 = _wcslen(param_1);
  FID_conflict_assign(param_1,sVar1);
  return;
}

