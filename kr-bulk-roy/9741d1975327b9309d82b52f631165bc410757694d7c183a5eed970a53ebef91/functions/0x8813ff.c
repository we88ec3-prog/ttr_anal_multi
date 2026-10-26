
/* Library Function - Single Match
    int __cdecl std::_LStrcoll<unsigned short>(unsigned short const *,unsigned short const
   *,unsigned short const *,unsigned short const *,struct _Collvec const *)
   
   Library: Visual Studio 2010 Release */

int __cdecl
std::_LStrcoll<unsigned_short>
          (ushort *param_1,ushort *param_2,ushort *param_3,ushort *param_4,_Collvec *param_5)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 == param_4) goto LAB_0088142f;
    uVar1 = *param_1;
    uVar2 = *param_3;
    if (uVar2 >= uVar1 && uVar2 != uVar1) goto LAB_0088143a;
    if (uVar2 < uVar1) {
      return 1;
    }
    param_3 = param_3 + 1;
  }
  if (param_3 == param_4) {
LAB_0088142f:
    uVar3 = (uint)(param_1 != param_2);
  }
  else {
LAB_0088143a:
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

