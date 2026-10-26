
/* Library Function - Single Match
    unsigned int __cdecl std::_LStrxfrm<unsigned short>(unsigned short *,unsigned short *,unsigned
   short const *,unsigned short const *,struct _Collvec const *)
   
   Library: Visual Studio 2010 Release */

uint __cdecl
std::_LStrxfrm<unsigned_short>
          (ushort *param_1,ushort *param_2,ushort *param_3,ushort *param_4,_Collvec *param_5)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (int)param_2 - (int)param_1 >> 1;
  uVar2 = (int)param_4 - (int)param_3 >> 1;
  if (uVar2 <= uVar1) {
    _memcpy_s(param_1,uVar1 * 2,param_3,uVar2 * 2);
  }
  return uVar2;
}

