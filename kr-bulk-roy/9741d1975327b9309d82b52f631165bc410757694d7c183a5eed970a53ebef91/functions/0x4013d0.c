
/* Library Function - Single Match
    public: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::reserve(unsigned int)
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::reserve
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = *(uint *)(this + 0x10);
  if ((uVar1 <= param_1) && (*(uint *)(this + 0x14) != param_1)) {
    cVar2 = FUN_00402f80(param_1,1);
    if (cVar2 != '\0') {
      *(uint *)(this + 0x10) = uVar1;
      if (0xf < *(uint *)(this + 0x14)) {
        this = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      this[uVar1] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
    }
  }
  return;
}

