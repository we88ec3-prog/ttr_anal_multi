
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::erase(unsigned
   int,unsigned int)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::erase(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_erase(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *in_ECX;
  undefined4 *puVar4;
  
  if ((uint)in_ECX[4] < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar3 = in_ECX[4] - param_1;
  if (uVar3 < param_2) {
    param_2 = uVar3;
  }
  if (param_2 != 0) {
    puVar4 = in_ECX;
    puVar2 = in_ECX;
    if (7 < (uint)in_ECX[5]) {
      puVar4 = (undefined4 *)*in_ECX;
      puVar2 = (undefined4 *)*in_ECX;
    }
    FID_conflict__memcpy
              ((void *)((int)puVar4 + param_1 * 2),(void *)((int)puVar2 + (param_1 + param_2) * 2),
               (uVar3 - param_2) * 2);
    iVar1 = in_ECX[4];
    in_ECX[4] = iVar1 - param_2;
    if (7 < (uint)in_ECX[5]) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    *(undefined2 *)((int)in_ECX + (iVar1 - param_2) * 2) = 0;
  }
  return;
}

