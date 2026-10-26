
/* Library Function - Multiple Matches With Different Base Names
    public: void __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Chassign(unsigned int,unsigned int,unsigned
   short)
    public: void __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Chassign(unsigned int,unsigned int,wchar_t)
   
   Library: Visual Studio 2010 Release */

void FID_conflict__Chassign(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  if (param_2 == 1) {
    if (7 < (uint)in_ECX[5]) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    *(undefined2 *)((int)in_ECX + param_1 * 2) = (undefined2)param_3;
  }
  else {
    if (7 < (uint)in_ECX[5]) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    FUN_004022a0((int)in_ECX + param_1 * 2,param_3,param_2);
  }
  return;
}

