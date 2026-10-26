
/* Library Function - Multiple Matches With Different Base Names
    public: void __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::resize(unsigned int,unsigned short)
    public: void __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::resize(unsigned int,wchar_t)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_resize(uint param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x10) < param_1) {
    FID_conflict_append(param_1 - *(uint *)(in_ECX + 0x10),param_2);
  }
  else {
    FID_conflict_erase(param_1,0xffffffff);
  }
  return;
}

