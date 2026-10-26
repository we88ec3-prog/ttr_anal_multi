
/* Library Function - Single Match
    protected: virtual int __thiscall std::collate<unsigned short>::do_compare(unsigned short const
   *,unsigned short const *,unsigned short const *,unsigned short const *)const 
   
   Library: Visual Studio 2010 Release */

int __thiscall
std::collate<unsigned_short>::do_compare
          (collate<unsigned_short> *this,ushort *param_1,ushort *param_2,ushort *param_3,
          ushort *param_4)

{
  int iVar1;
  
  iVar1 = _LStrcoll<unsigned_short>(param_1,param_2,param_3,param_4,(_Collvec *)(this + 8));
  return iVar1;
}

