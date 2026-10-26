
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::insert(unsigned
   int,unsigned int,unsigned short)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::insert(unsigned int,unsigned
   int,wchar_t)
   
   Library: Visual Studio 2010 Release */

void FID_conflict_insert(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *in_ECX;
  
  uVar1 = in_ECX[4];
  if (uVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  if (-uVar1 - 1 <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (param_2 != 0) {
    iVar4 = uVar1 + param_2;
    cVar3 = FID_conflict__Grow(iVar4,0);
    if (cVar3 != '\0') {
      puVar5 = in_ECX;
      puVar2 = in_ECX;
      if (7 < (uint)in_ECX[5]) {
        puVar5 = (undefined4 *)*in_ECX;
        puVar2 = (undefined4 *)*in_ECX;
      }
      FID_conflict__memcpy
                ((void *)((int)puVar5 + (param_1 + param_2) * 2),(void *)((int)puVar2 + param_1 * 2)
                 ,(in_ECX[4] - param_1) * 2);
      FID_conflict__Chassign(param_1,param_2,param_3);
      in_ECX[4] = iVar4;
      if (7 < (uint)in_ECX[5]) {
        in_ECX = (undefined4 *)*in_ECX;
      }
      *(undefined2 *)((int)in_ECX + iVar4 * 2) = 0;
    }
  }
  return;
}

