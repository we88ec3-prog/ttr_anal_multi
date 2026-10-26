
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::append(unsigned
   int,unsigned short)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::append(unsigned int,wchar_t)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_append(uint param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  undefined4 *in_ECX;
  
  if (param_1 < -in_ECX[4] - 1) {
    if (param_1 != 0) {
      iVar1 = in_ECX[4] + param_1;
      cVar2 = FID_conflict__Grow(iVar1,0);
      if (cVar2 != '\0') {
        FID_conflict__Chassign(in_ECX[4],param_1,param_2);
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

