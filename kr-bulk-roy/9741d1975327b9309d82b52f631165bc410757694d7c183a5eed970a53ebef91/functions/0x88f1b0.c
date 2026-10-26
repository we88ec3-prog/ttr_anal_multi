
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    class std::collate<char> const & __cdecl std::use_facet<class std::collate<char> >(class
   std::locale const &)
   
   Library: Visual Studio 2010 Release */

collate<char> * __cdecl std::use_facet<std::collate<char>_>(locale *param_1)

{
  collate<char> *pcVar1;
  uint uVar2;
  collate<char> *pcVar3;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  collate<char> *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x88f1bc;
  _Lockit::_Lockit(local_18,0);
  pcVar1 = DAT_00f8ca90;
  local_8 = 0;
  local_14[0] = DAT_00f8ca90;
  uVar2 = locale::id::operator_unsigned_int((id *)&DAT_00f8ca98);
  pcVar3 = (collate<char> *)FUN_004311c0(uVar2);
  if ((pcVar3 == (collate<char> *)0x0) && (pcVar3 = pcVar1, pcVar1 == (collate<char> *)0x0)) {
    uVar2 = collate<char>::_Getcat((facet **)local_14,param_1);
    pcVar3 = local_14[0];
    if (uVar2 == 0xffffffff) {
      bad_cast::bad_cast(local_24,"bad cast");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c85874);
    }
    DAT_00f8ca90 = local_14[0];
    FUN_00431db0();
    locale::facet::_Facet_Register((facet *)pcVar3);
  }
  local_8 = 0xffffffff;
  FUN_0087dd6f();
  return pcVar3;
}

