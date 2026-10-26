
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > __thiscall std::collate<unsigned
   short>::do_transform(unsigned short const *,unsigned short const *)const 
   
   Library: Visual Studio 2010 Release */

ushort * __thiscall
std::collate<unsigned_short>::do_transform
          (collate<unsigned_short> *this,ushort *param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *in_stack_0000000c;
  
  param_1[10] = 7;
  param_1[0xb] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *param_1 = 0;
  uVar1 = (int)in_stack_0000000c - (int)param_2 >> 1;
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = uVar1;
    do {
      FID_conflict_resize(uVar2,0);
      puVar3 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        puVar3 = *(ushort **)param_1;
      }
      puVar4 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        puVar4 = *(ushort **)param_1;
      }
      uVar2 = _LStrxfrm<unsigned_short>
                        (puVar4,puVar3 + *(int *)(param_1 + 8),param_2,in_stack_0000000c,
                         (_Collvec *)(this + 8));
    } while ((*(uint *)(param_1 + 8) < uVar2) && (uVar2 != 0));
  }
  FID_conflict_resize(uVar2,0);
  return param_1;
}

