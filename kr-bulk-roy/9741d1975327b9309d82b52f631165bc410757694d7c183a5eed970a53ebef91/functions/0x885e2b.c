
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::assign(unsigned short
   const *,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::assign(wchar_t const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_assign(void *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  cVar1 = FID_conflict__Inside(param_1);
  if (cVar1 == '\0') {
    cVar1 = FID_conflict__Grow(param_2,0);
    if (cVar1 != '\0') {
      puVar2 = in_ECX;
      if (7 < (uint)in_ECX[5]) {
        puVar2 = (undefined4 *)*in_ECX;
      }
      FID_conflict__memcpy(puVar2,param_1,param_2 * 2);
      in_ECX[4] = param_2;
      if (7 < (uint)in_ECX[5]) {
        in_ECX = (undefined4 *)*in_ECX;
      }
      *(undefined2 *)(param_2 * 2 + (int)in_ECX) = 0;
    }
  }
  else {
    puVar2 = in_ECX;
    if (7 < (uint)in_ECX[5]) {
      puVar2 = (undefined4 *)*in_ECX;
    }
    FID_conflict_assign(in_ECX,(int)param_1 - (int)puVar2 >> 1,param_2);
  }
  return;
}

