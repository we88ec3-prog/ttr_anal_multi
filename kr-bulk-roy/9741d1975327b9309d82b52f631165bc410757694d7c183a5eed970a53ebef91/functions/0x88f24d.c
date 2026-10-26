
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    private: static void __cdecl std::locale::_Locimp::_Makexloc(class std::_Locinfo const
   &,int,class std::locale::_Locimp *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

void __cdecl
std::locale::_Locimp::_Makexloc(_Locinfo *param_1,int param_2,_Locimp *param_3,locale *param_4)

{
  uint uVar1;
  facet *pfVar2;
  collate<char> *pcVar3;
  messages<char> *pmVar4;
  uint uVar5;
  _Mpunct<char> *p_Var6;
  moneypunct<char,0> *pmVar7;
  moneypunct<char,1> *pmVar8;
  time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *ptVar9;
  time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_> *ptVar10;
  _Collvec _Var11;
  
  uVar1 = collate<char>::_Getcat((facet **)0x0,(locale *)0x0);
  if ((param_2 & (1 << ((byte)uVar1 & 0x1f)) >> 1) != 0) {
    if (param_4 == (locale *)0x0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 = collate<char>::vftable;
        _Var11 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var11;
      }
      uVar1 = id::operator_unsigned_int((id *)&DAT_00f8ca98);
      _Locimp_Addfac(param_3,pfVar2,uVar1);
    }
    else {
      uVar1 = id::operator_unsigned_int((id *)&DAT_00f8ca98);
      pcVar3 = use_facet<std::collate<char>_>(param_4);
      _Locimp_Addfac(param_3,(facet *)pcVar3,uVar1);
    }
  }
  if ((param_2 & 0x20U) != 0) {
    if (param_4 == (locale *)0x0) {
      pfVar2 = (facet *)FUN_00891268(8);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 = messages<char>::vftable;
      }
      uVar1 = id::operator_unsigned_int((id *)&DAT_00f8cab0);
      _Locimp_Addfac(param_3,pfVar2,uVar1);
    }
    else {
      uVar1 = id::operator_unsigned_int((id *)&DAT_00f8cab0);
      pmVar4 = use_facet<std::messages<char>_>(param_4);
      _Locimp_Addfac(param_3,(facet *)pmVar4,uVar1);
    }
  }
  uVar1 = param_2 & 4;
  if (uVar1 != 0) {
    if (param_4 == (locale *)0x0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             money_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::vftable;
        _Var11 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var11;
      }
      uVar5 = id::operator_unsigned_int((id *)&DAT_00f8caa0);
      _Locimp_Addfac(param_3,pfVar2,uVar5);
    }
    else {
      uVar5 = id::operator_unsigned_int((id *)&DAT_00f8caa0);
      pfVar2 = (facet *)::use_facet<>(param_4);
      _Locimp_Addfac(param_3,pfVar2,uVar5);
    }
  }
  if (uVar1 != 0) {
    if (param_4 == (locale *)0x0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::vftable;
        _Var11 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var11;
      }
      uVar5 = id::operator_unsigned_int((id *)&DAT_00f8ca9c);
      _Locimp_Addfac(param_3,pfVar2,uVar5);
    }
    else {
      uVar5 = id::operator_unsigned_int((id *)&DAT_00f8ca9c);
      pfVar2 = (facet *)::use_facet<>(param_4);
      _Locimp_Addfac(param_3,pfVar2,uVar5);
    }
  }
  if (uVar1 != 0) {
    if (param_4 == (locale *)0x0) {
      p_Var6 = (_Mpunct<char> *)FUN_00891268(0x34);
      if (p_Var6 == (_Mpunct<char> *)0x0) {
        p_Var6 = (_Mpunct<char> *)0x0;
      }
      else {
        *(undefined4 *)(p_Var6 + 4) = 0;
        *(undefined ***)p_Var6 = _Mpunct<char>::vftable;
        p_Var6[0x28] = (_Mpunct<char>)0x0;
        _Mpunct<char>::_Init(p_Var6,param_1,false);
        *(undefined ***)p_Var6 = moneypunct<char,0>::vftable;
      }
      uVar5 = id::operator_unsigned_int((id *)&DAT_00f8caac);
      _Locimp_Addfac(param_3,(facet *)p_Var6,uVar5);
    }
    else {
      uVar5 = id::operator_unsigned_int((id *)&DAT_00f8caac);
      pmVar7 = use_facet<std::moneypunct<char,0>_>(param_4);
      _Locimp_Addfac(param_3,(facet *)pmVar7,uVar5);
    }
    if (uVar1 != 0) {
      if (param_4 == (locale *)0x0) {
        p_Var6 = (_Mpunct<char> *)FUN_00891268(0x34);
        if (p_Var6 == (_Mpunct<char> *)0x0) {
          p_Var6 = (_Mpunct<char> *)0x0;
        }
        else {
          *(undefined4 *)(p_Var6 + 4) = 0;
          *(undefined ***)p_Var6 = _Mpunct<char>::vftable;
          p_Var6[0x28] = (_Mpunct<char>)0x1;
          _Mpunct<char>::_Init(p_Var6,param_1,false);
          *(undefined ***)p_Var6 = moneypunct<char,1>::vftable;
        }
        uVar1 = id::operator_unsigned_int((id *)&DAT_00f8caa8);
        _Locimp_Addfac(param_3,(facet *)p_Var6,uVar1);
      }
      else {
        uVar1 = id::operator_unsigned_int((id *)&DAT_00f8caa8);
        pmVar8 = use_facet<std::moneypunct<char,1>_>(param_4);
        _Locimp_Addfac(param_3,(facet *)pmVar8,uVar1);
      }
    }
  }
  if ((param_2 & 0x10U) != 0) {
    if (param_4 == (locale *)0x0) {
      ptVar9 = (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)
               FUN_00891268(0x1c);
      if (ptVar9 == (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        pfVar2 = (facet *)time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::
                          time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>
                                    (ptVar9,param_1,0);
      }
      uVar1 = id::operator_unsigned_int((id *)&DAT_00f8ca94);
      _Locimp_Addfac(param_3,pfVar2,uVar1);
    }
    else {
      uVar1 = id::operator_unsigned_int((id *)&DAT_00f8ca94);
      ptVar9 = use_facet<std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>_>
                         (param_4);
      _Locimp_Addfac(param_3,(facet *)ptVar9,uVar1);
    }
  }
  if ((param_2 & 0x10U) != 0) {
    if (param_4 == (locale *)0x0) {
      pfVar2 = (facet *)FUN_00891268(0x14);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::vftable;
        *(undefined4 *)(pfVar2 + 8) = 0;
        Init(param_1);
      }
      uVar1 = id::operator_unsigned_int((id *)&DAT_00f8caa4);
      _Locimp_Addfac(param_3,pfVar2,uVar1);
    }
    else {
      uVar1 = id::operator_unsigned_int((id *)&DAT_00f8caa4);
      ptVar10 = use_facet<std::time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>_>
                          (param_4);
      _Locimp_Addfac(param_3,(facet *)ptVar10,uVar1);
    }
  }
  return;
}

