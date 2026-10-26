
/* Library Function - Multiple Matches With Different Base Names
    public: bool __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Inside(unsigned short const *)
    public: bool __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Inside(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

uint FID_conflict__Inside(undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  if (param_1 != (undefined4 *)0x0) {
    in_EAX = in_ECX;
    if (7 < (uint)in_ECX[5]) {
      in_EAX = (undefined4 *)*in_ECX;
    }
    if (in_EAX <= param_1) {
      puVar1 = in_ECX;
      if (7 < (uint)in_ECX[5]) {
        puVar1 = (undefined4 *)*in_ECX;
      }
      in_EAX = (undefined4 *)((int)puVar1 + in_ECX[4] * 2);
      if (param_1 < in_EAX) {
        return CONCAT31((int3)((uint)in_EAX >> 8),1);
      }
    }
  }
  return (uint)in_EAX & 0xffffff00;
}

