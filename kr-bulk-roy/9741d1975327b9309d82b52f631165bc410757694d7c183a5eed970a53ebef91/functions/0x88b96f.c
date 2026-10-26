
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    private: static void __cdecl std::locale::_Locimp::_Makeushloc(class std::_Locinfo const
   &,int,class std::locale::_Locimp *,class std::locale const *)
    private: static void __cdecl std::locale::_Locimp::_Makewloc(class std::_Locinfo const
   &,int,class std::locale::_Locimp *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

void FID_conflict__Makewloc(undefined4 param_1,uint param_2,_Locimp *param_3,int param_4)

{
  byte bVar1;
  facet *pfVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  _Collvec _Var6;
  
  if ((param_2 & 2) != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x20);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 = std::ctype<unsigned_short>::vftable;
        Init(param_1);
      }
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8c860);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
    else {
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8c860);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
  }
  uVar3 = param_2 & 8;
  if (uVar3 != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             std::
             num_get<unsigned_short,std::istreambuf_iterator<unsigned_short,std::char_traits<unsigned_short>_>_>
             ::vftable;
        _Var6 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var6;
      }
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca60);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    else {
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca60);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
  }
  if (uVar3 != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             std::
             num_put<unsigned_short,std::ostreambuf_iterator<unsigned_short,std::char_traits<unsigned_short>_>_>
             ::vftable;
        _Var6 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var6;
      }
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca58);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    else {
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca58);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    if (uVar3 != 0) {
      if (param_4 == 0) {
        pfVar2 = (facet *)FUN_00891268(0x18);
        if (pfVar2 == (facet *)0x0) {
          pfVar2 = (facet *)0x0;
        }
        else {
          *(undefined4 *)(pfVar2 + 4) = 0;
          *(undefined ***)pfVar2 = std::numpunct<unsigned_short>::vftable;
          Init(param_1,0);
        }
        uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca4c);
        std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
      }
      else {
        uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca4c);
        pfVar2 = (facet *)use_facet<>(param_4);
        std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
      }
    }
  }
  bVar1 = Getcat(0,0);
  if ((param_2 & (1 << (bVar1 & 0x1f)) >> 1) != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 = std::collate<unsigned_short>::vftable;
        _Var6 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var6;
      }
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca38);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
    else {
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca38);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
  }
  if ((param_2 & 0x20) != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(8);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 = std::messages<unsigned_short>::vftable;
      }
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca3c);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
    else {
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca3c);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
  }
  uVar3 = param_2 & 4;
  if (uVar3 != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             std::
             money_get<unsigned_short,std::istreambuf_iterator<unsigned_short,std::char_traits<unsigned_short>_>_>
             ::vftable;
        _Var6 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var6;
      }
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca24);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    else {
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca24);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
  }
  if (uVar3 != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             std::
             money_put<unsigned_short,std::ostreambuf_iterator<unsigned_short,std::char_traits<unsigned_short>_>_>
             ::vftable;
        _Var6 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var6;
      }
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca6c);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    else {
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca6c);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
  }
  if (uVar3 != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x34);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 = std::_Mpunct<unsigned_short>::vftable;
        pfVar2[0x28] = (facet)0x0;
        Init(param_1,0);
        *(undefined ***)pfVar2 = std::moneypunct<unsigned_short,0>::vftable;
      }
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca5c);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    else {
      uVar4 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca5c);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar4);
    }
    if (uVar3 != 0) {
      if (param_4 == 0) {
        pfVar2 = (facet *)FUN_00891268(0x34);
        if (pfVar2 == (facet *)0x0) {
          pfVar2 = (facet *)0x0;
        }
        else {
          *(undefined4 *)(pfVar2 + 4) = 0;
          *(undefined ***)pfVar2 = std::_Mpunct<unsigned_short>::vftable;
          pfVar2[0x28] = (facet)0x1;
          Init(param_1,0);
          *(undefined ***)pfVar2 = std::moneypunct<unsigned_short,1>::vftable;
        }
        uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca70);
        std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
      }
      else {
        uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca70);
        pfVar2 = (facet *)use_facet<>(param_4);
        std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
      }
    }
  }
  if ((param_2 & 0x10) != 0) {
    if (param_4 == 0) {
      iVar5 = FUN_00891268(0x1c);
      if (iVar5 == 0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        pfVar2 = (facet *)time_get<>(param_1,0);
      }
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca28);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
    else {
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca28);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
  }
  if ((param_2 & 0x10) != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x14);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 =
             std::
             time_put<unsigned_short,std::ostreambuf_iterator<unsigned_short,std::char_traits<unsigned_short>_>_>
             ::vftable;
        *(undefined4 *)(pfVar2 + 8) = 0;
        Init(param_1);
      }
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca34);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
    else {
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8ca34);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
  }
  if ((param_2 & 2) != 0) {
    if (param_4 == 0) {
      pfVar2 = (facet *)FUN_00891268(0x10);
      if (pfVar2 == (facet *)0x0) {
        pfVar2 = (facet *)0x0;
      }
      else {
        *(undefined4 *)(pfVar2 + 4) = 0;
        *(undefined ***)pfVar2 = std::codecvt<unsigned_short,char,int>::vftable;
        _Var6 = __Getcoll();
        *(_Collvec *)(pfVar2 + 8) = _Var6;
      }
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8c850);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
    else {
      uVar3 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8c850);
      pfVar2 = (facet *)use_facet<>(param_4);
      std::locale::_Locimp::_Locimp_Addfac(param_3,pfVar2,uVar3);
    }
  }
  return;
}

