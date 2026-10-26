
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    class std::ctype<unsigned short> const & __cdecl std::use_facet<class std::ctype<unsigned short>
   >(class std::locale const &)
    class std::ctype<wchar_t> const & __cdecl std::use_facet<class std::ctype<wchar_t> >(class
   std::locale const &)
   
   Library: Visual Studio 2010 Release */

facet * use_facet<>(undefined4 param_1)

{
  facet *pfVar1;
  uint uVar2;
  facet *pfVar3;
  int iVar4;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  facet *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x8828bb;
  std::_Lockit::_Lockit(local_18,0);
  pfVar1 = DAT_00f8c9c8;
  local_8 = 0;
  local_14[0] = DAT_00f8c9c8;
  uVar2 = std::locale::id::operator_unsigned_int((id *)&DAT_00f8c860);
  pfVar3 = (facet *)FUN_004311c0(uVar2);
  if ((pfVar3 == (facet *)0x0) && (pfVar3 = pfVar1, pfVar1 == (facet *)0x0)) {
    iVar4 = Getcat(local_14,param_1);
    pfVar3 = local_14[0];
    if (iVar4 == -1) {
      std::bad_cast::bad_cast(local_24,"bad cast");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c85874);
    }
    DAT_00f8c9c8 = local_14[0];
    FUN_00431db0();
    std::locale::facet::_Facet_Register(pfVar3);
  }
  local_8 = 0xffffffff;
  FUN_0087dd6f();
  return pfVar3;
}

