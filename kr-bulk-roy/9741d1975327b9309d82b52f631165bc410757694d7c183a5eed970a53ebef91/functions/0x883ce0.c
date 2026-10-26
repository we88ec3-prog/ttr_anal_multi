
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::append(class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const &,unsigned int,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::append(class
   std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class std::allocator<wchar_t> > const
   &,unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_append(undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *in_ECX;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar3 = param_1[4] - param_2;
  if (uVar3 < param_3) {
    param_3 = uVar3;
  }
  if (param_3 < -in_ECX[4] - 1) {
    if (param_3 != 0) {
      iVar1 = in_ECX[4] + param_3;
      cVar2 = FID_conflict__Grow(iVar1,0);
      if (cVar2 != '\0') {
        if (7 < (uint)param_1[5]) {
          param_1 = (undefined4 *)*param_1;
        }
        puVar4 = in_ECX;
        if (7 < (uint)in_ECX[5]) {
          puVar4 = (undefined4 *)*in_ECX;
        }
        FID_conflict__memcpy
                  ((void *)((int)puVar4 + in_ECX[4] * 2),(void *)((int)param_1 + param_2 * 2),
                   param_3 * 2);
        in_ECX[4] = iVar1;
        if (7 < (uint)in_ECX[5]) {
          in_ECX = (undefined4 *)*in_ECX;
        }
        *(undefined2 *)((int)in_ECX + iVar1 * 2) = 0;
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("string too long");
}

