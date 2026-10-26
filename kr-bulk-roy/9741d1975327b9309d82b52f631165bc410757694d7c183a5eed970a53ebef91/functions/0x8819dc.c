
/* Library Function - Multiple Matches With Different Base Names
    public: void __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Tidy(bool,unsigned int)
    public: void __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Tidy(bool,unsigned int)
   
   Library: Visual Studio 2010 Release */

void FID_conflict__Tidy(char param_1,int param_2)

{
  void *_Src;
  undefined4 *in_ECX;
  
  if ((param_1 != '\0') && (7 < (uint)in_ECX[5])) {
    _Src = (void *)*in_ECX;
    if (param_2 != 0) {
      FID_conflict__memcpy(in_ECX,_Src,param_2 * 2);
    }
    FUN_0089120c(_Src);
  }
  in_ECX[4] = param_2;
  in_ECX[5] = 7;
  *(undefined2 *)((int)in_ECX + param_2 * 2) = 0;
  return;
}

