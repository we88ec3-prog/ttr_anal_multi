
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: static unsigned int __cdecl std::moneypunct<char,1>::_Getcat(class std::locale::facet
   const * *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

uint __cdecl std::moneypunct<char,1>::_Getcat(facet **param_1,locale *param_2)

{
  bool bVar1;
  _Mpunct<char> *this;
  int iVar2;
  _Locinfo *p_Var3;
  
  bVar1 = false;
  if ((param_1 != (facet **)0x0) && (*param_1 == (facet *)0x0)) {
    this = (_Mpunct<char> *)FUN_00891268(0x34);
    if (this == (_Mpunct<char> *)0x0) {
      this = (_Mpunct<char> *)0x0;
    }
    else {
      iVar2 = *(int *)(*(int *)param_2 + 0x18);
      if (iVar2 == 0) {
        iVar2 = *(int *)param_2 + 0x1c;
      }
      p_Var3 = (_Locinfo *)FUN_00431550(iVar2);
      *(undefined4 *)(this + 4) = 0;
      bVar1 = true;
      this[0x28] = (_Mpunct<char>)0x1;
      *(undefined ***)this = _Mpunct<char>::vftable;
      _Mpunct<char>::_Init(this,p_Var3,true);
      *(undefined ***)this = vftable;
    }
    *param_1 = (facet *)this;
    if (bVar1) {
      FUN_00431620();
    }
  }
  return 3;
}

