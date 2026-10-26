
/* Library Function - Multiple Matches With Different Base Names
    public: bool __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Grow(unsigned int,bool)
    public: bool __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Grow(unsigned int,bool)
   
   Library: Visual Studio 2010 Release */

bool FID_conflict__Grow(uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *in_ECX;
  
  if (0x7ffffffe < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if ((uint)in_ECX[5] < param_1) {
    FUN_008827c2(param_1,in_ECX[4]);
  }
  else if ((param_2 == '\0') || (7 < param_1)) {
    if (param_1 == 0) {
      in_ECX[4] = 0;
      if (7 < (uint)in_ECX[5]) {
        in_ECX = (undefined4 *)*in_ECX;
      }
      *(undefined2 *)in_ECX = 0;
    }
  }
  else {
    uVar1 = in_ECX[4];
    if (param_1 < (uint)in_ECX[4]) {
      uVar1 = param_1;
    }
    FID_conflict__Tidy(1,uVar1);
  }
  return param_1 != 0;
}

