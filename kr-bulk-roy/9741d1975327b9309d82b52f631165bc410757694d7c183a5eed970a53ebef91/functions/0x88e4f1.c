
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    class std::moneypunct<char,0> const & __cdecl std::use_facet<class std::moneypunct<char,0>
   >(class std::locale const &)
   
   Library: Visual Studio 2010 Release */

moneypunct<char,0> * __cdecl std::use_facet<std::moneypunct<char,0>_>(locale *param_1)

{
  moneypunct<char,0> *pmVar1;
  uint uVar2;
  moneypunct<char,0> *pmVar3;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  moneypunct<char,0> *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x88e4fd;
  _Lockit::_Lockit(local_18,0);
  pmVar1 = DAT_00f8ca84;
  local_8 = 0;
  local_14[0] = DAT_00f8ca84;
  uVar2 = locale::id::operator_unsigned_int((id *)&DAT_00f8caac);
  pmVar3 = (moneypunct<char,0> *)FUN_004311c0(uVar2);
  if ((pmVar3 == (moneypunct<char,0> *)0x0) &&
     (pmVar3 = pmVar1, pmVar1 == (moneypunct<char,0> *)0x0)) {
    uVar2 = moneypunct<char,0>::_Getcat((facet **)local_14,param_1);
    pmVar3 = local_14[0];
    if (uVar2 == 0xffffffff) {
      bad_cast::bad_cast(local_24,"bad cast");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c85874);
    }
    DAT_00f8ca84 = local_14[0];
    FUN_00431db0();
    locale::facet::_Facet_Register((facet *)pmVar3);
  }
  local_8 = 0xffffffff;
  FUN_0087dd6f();
  return pmVar3;
}

