
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    class std::messages<char> const & __cdecl std::use_facet<class std::messages<char> >(class
   std::locale const &)
   
   Library: Visual Studio 2010 Release */

messages<char> * __cdecl std::use_facet<std::messages<char>_>(locale *param_1)

{
  messages<char> *pmVar1;
  uint uVar2;
  messages<char> *pmVar3;
  int iVar4;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  messages<char> *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x88ddc5;
  _Lockit::_Lockit(local_18,0);
  pmVar1 = DAT_00f8ca74;
  local_8 = 0;
  local_14[0] = DAT_00f8ca74;
  uVar2 = locale::id::operator_unsigned_int((id *)&DAT_00f8cab0);
  pmVar3 = (messages<char> *)FUN_004311c0(uVar2);
  if ((pmVar3 == (messages<char> *)0x0) && (pmVar3 = pmVar1, pmVar1 == (messages<char> *)0x0)) {
    iVar4 = ::Getcat(local_14,param_1);
    pmVar3 = local_14[0];
    if (iVar4 == -1) {
      bad_cast::bad_cast(local_24,"bad cast");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c85874);
    }
    DAT_00f8ca74 = local_14[0];
    FUN_00431db0();
    locale::facet::_Facet_Register((facet *)pmVar3);
  }
  local_8 = 0xffffffff;
  FUN_0087dd6f();
  return pmVar3;
}

