
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::assign(unsigned
   int,unsigned short)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::assign(unsigned int,wchar_t)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_assign(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *in_ECX;
  
  if (param_1 != -1) {
    cVar1 = FID_conflict__Grow(param_1,0);
    if (cVar1 != '\0') {
      FID_conflict__Chassign(0,param_1,param_2);
      in_ECX[4] = param_1;
      if (7 < (uint)in_ECX[5]) {
        in_ECX = (undefined4 *)*in_ECX;
      }
      *(undefined2 *)((int)in_ECX + param_1 * 2) = 0;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("string too long");
}

