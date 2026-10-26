
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    private: static class std::locale::_Locimp * __cdecl std::locale::_Locimp::_Makeloc(class
   std::_Locinfo const &,int,class std::locale::_Locimp *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

_Locimp * __cdecl
std::locale::_Locimp::_Makeloc(_Locinfo *param_1,int param_2,_Locimp *param_3,locale *param_4)

{
  int iVar1;
  facet *pfVar2;
  uint uVar3;
  uint uVar4;
  _Locinfo *p_Var5;
  _Collvec _Var6;
  
  if ((param_2 & 2U) != 0) {
    if (param_4 == (locale *)0x0) {
      iVar1 = FUN_00891268(0x18);
      if (iVar1 == 0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        pfVar2 = (facet *)FUN_006de410(param_1,0);
      }
      uVar3 = id::operator_unsigned_int((id *)&DAT_00f8c84c);
      _Locimp_Addfac(param_3,pfVar2,uVar3);
    }
    else {
      uVar3 = id::operator_unsigned_int((id *)&DAT_00f8c84c);
      pfVar2 = (facet *)FUN_006de510(param_4);
      _Locimp_Addfac(param_3,pfVar2,uVar3);
    }
  }
  uVar3 = param_2 & 8;
  if (uVar3 != 0) {
    if (param_4 == (locale *)0x0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::vftable;
        _Var6 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var6;
      }
      uVar4 = id::operator_unsigned_int((id *)&DAT_00f8c974);
      _Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    else {
      uVar4 = id::operator_unsigned_int((id *)&DAT_00f8c974);
      pfVar2 = (facet *)::use_facet<>(param_4);
      _Locimp_Addfac(param_3,pfVar2,uVar4);
    }
  }
  if (uVar3 != 0) {
    if (param_4 == (locale *)0x0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::vftable;
        _Var6 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var6;
      }
      uVar4 = id::operator_unsigned_int((id *)&DAT_00fe7284);
      _Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    else {
      uVar4 = id::operator_unsigned_int((id *)&DAT_00fe7284);
      pfVar2 = (facet *)FUN_006efbb0(param_4);
      _Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    if (uVar3 != 0) {
      if (param_4 == (locale *)0x0) {
        pfVar2 = (facet *)FUN_00891268(0x18);
        if (pfVar2 == (facet *)0x0) {
          pfVar2 = (facet *)0x0;
        }
        else {
          *(undefined4 *)(pfVar2 + 4) = 0;
          *(undefined ***)pfVar2 = numpunct<char>::vftable;
          FUN_006effc0(param_1,0);
        }
        uVar3 = id::operator_unsigned_int((id *)&DAT_00fe7280);
        _Locimp_Addfac(param_3,pfVar2,uVar3);
      }
      else {
        uVar3 = id::operator_unsigned_int((id *)&DAT_00fe7280);
        pfVar2 = (facet *)FUN_006efcf0(param_4);
        _Locimp_Addfac(param_3,pfVar2,uVar3);
      }
    }
  }
  if ((param_2 & 2U) != 0) {
    if (param_4 == (locale *)0x0) {
      pfVar2 = (facet *)FUN_00891268(8);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 = codecvt<char,char,int>::vftable;
      }
      uVar3 = id::operator_unsigned_int((id *)&DAT_00fe7274);
      _Locimp_Addfac(param_3,pfVar2,uVar3);
    }
    else {
      uVar3 = id::operator_unsigned_int((id *)&DAT_00fe7274);
      pfVar2 = (facet *)FUN_007841f0(param_4);
      _Locimp_Addfac(param_3,pfVar2,uVar3);
    }
  }
  _Makexloc(param_1,param_2,param_3,param_4);
  FID_conflict__Makewloc(param_1,param_2,param_3,param_4);
  FID_conflict__Makewloc(param_1,param_2,param_3,param_4);
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) | param_2;
  p_Var5 = *(_Locinfo **)(param_1 + 0x1c);
  if (p_Var5 == (_Locinfo *)0x0) {
    p_Var5 = param_1 + 0x20;
  }
  FUN_00433ba0(p_Var5);
  return param_3;
}

