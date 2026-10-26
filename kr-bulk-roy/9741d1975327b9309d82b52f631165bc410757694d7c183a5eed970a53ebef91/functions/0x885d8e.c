
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::assign(class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const &,unsigned int,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::assign(class
   std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class std::allocator<wchar_t> > const
   &,unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_assign(undefined4 *param_1,uint param_2,uint param_3)

{
  char cVar1;
  undefined4 *in_ECX;
  undefined4 *_Dst;
  uint uVar2;
  
  if (param_2 <= (uint)param_1[4]) {
    uVar2 = param_1[4] - param_2;
    if (param_3 < uVar2) {
      uVar2 = param_3;
    }
    if (in_ECX == param_1) {
      FID_conflict_erase(uVar2 + param_2,0xffffffff);
      FID_conflict_erase(0,param_2);
    }
    else {
      cVar1 = FID_conflict__Grow(uVar2,0);
      if (cVar1 != '\0') {
        if (7 < (uint)param_1[5]) {
          param_1 = (undefined4 *)*param_1;
        }
        _Dst = in_ECX;
        if (7 < (uint)in_ECX[5]) {
          _Dst = (undefined4 *)*in_ECX;
        }
        FID_conflict__memcpy(_Dst,(void *)((int)param_1 + param_2 * 2),uVar2 * 2);
        in_ECX[4] = uVar2;
        if (7 < (uint)in_ECX[5]) {
          in_ECX = (undefined4 *)*in_ECX;
        }
        *(undefined2 *)(uVar2 * 2 + (int)in_ECX) = 0;
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("invalid string position");
}

